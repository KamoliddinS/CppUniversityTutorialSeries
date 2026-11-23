# Copying objects

> **Goal:** copy an object that owns memory, so that the copy gets a block of its own.

## A copy copies the members

When a class says nothing about copying, `IntBuffer b = a;` copies each member of `a` into
the same member of `b`. This is a **memberwise copy**. For a pointer member it copies the
address, not the block of memory that the pointer points to:

**`shared_block_bug.cpp`**
<!-- file: shared_block_bug.cpp -->
```cpp
#include <cstddef>
#include <iostream>

class IntBuffer {
public:
    explicit IntBuffer(std::size_t size) : size_(size), data_(new int[size]{}) {}
    ~IntBuffer() { delete[] data_; }
    int& operator[](std::size_t index) { return data_[index]; }
    std::size_t size() const { return size_; }

private:
    std::size_t size_ = 0;
    int* data_ = nullptr;
};

int main() {
    IntBuffer a(3);
    a[0] = 7;

    IntBuffer b = a;        // copies the members: b.data_ gets the address in a.data_
    b[0] = 99;

    std::cout << "a[0] = " << a[0] << '\n';
}   // b is destroyed, then a: the same block is deleted twice
```

Built with the sanitizer:

```text
a[0] = 99
==3538200==ERROR: AddressSanitizer: attempting double-free on 0x502000000010 in thread T0:
    #1 0x580005be8bcb in IntBuffer::~IntBuffer() .../shared_block_bug.cpp:7
```

| Name | Address | Value |
|------|---------|-------|
| `a.data_` | `0x1008` | `0x5000` |
| `b.data_` | `0x1018` | `0x5000` (the same block) |
| heap block | `0x5000` | `99 0 0` |

Two objects own one block. A change through `b` changes `a`, and both destructors delete
the block: undefined behaviour.

## Give the copy its own block

The class needs two more functions. It is growing, so it moves into
[`int_buffer.h`](copy/int_buffer.h) and `int_buffer.cpp`
([Headers and source files](../../07-classes/06-headers-and-source-files/README.md)).

**`copy/int_buffer.cpp`**
<!-- file: copy/int_buffer.cpp -->
```cpp
#include "int_buffer.h"

#include <iostream>

IntBuffer::IntBuffer(const IntBuffer& other) : size_(other.size_), data_(new int[other.size_]) {
    std::cout << "  copy constructor\n";
    for (std::size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];          // copy the values, not the address
    }
}

IntBuffer& IntBuffer::operator=(const IntBuffer& other) {
    std::cout << "  copy assignment\n";
    if (this != &other) {                   // a = a; must change nothing
        delete[] data_;                     // give back the block held so far
        size_ = other.size_;
        data_ = new int[size_];
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}
```

**`copy/main.cpp`**
<!-- file: copy/main.cpp -->
```cpp
#include <iostream>

#include "int_buffer.h"

int main() {
    IntBuffer a(3);
    a[0] = 7;

    IntBuffer b = a;        // b is created from a: copy constructor
    b[0] = 99;

    IntBuffer c(5);
    c = a;                  // c exists already: copy assignment

    std::cout << "a[0] = " << a[0] << ", b[0] = " << b[0] << ", c[0] = " << c[0] << '\n';
}
```

<!-- output: copy -->
```text
  copy constructor
  copy assignment
a[0] = 7, b[0] = 99, c[0] = 7
```

| Name | Address | Value |
|------|---------|-------|
| `a.data_` | `0x1008` | `0x5000` |
| `b.data_` | `0x1018` | `0x6000` (its own block) |
| heap block | `0x5000` | `7 0 0` |
| heap block | `0x6000` | `99 0 0` |

- The **copy constructor** builds a new object from an existing one.
- The **copy assignment operator** gives a new value to an object that exists already, so
  it must first give back the block it holds. Without the `if`, `a = a;` would delete the
  values before copying them.

**Rule of three:** a class that needs one of these functions needs all three.

<!-- snippet: copy/int_buffer.h -->
```cpp
~IntBuffer() { delete[] data_; }                    // 1 destructor
IntBuffer(const IntBuffer& other);                  // 2 copy constructor
IntBuffer& operator=(const IntBuffer& other);       // 3 copy assignment operator
```

All this is needed only because `data_` is a raw pointer that owns memory. For `int`,
`std::string` and `std::vector` members the memberwise copy is right: a vector copies its
own elements. Most classes need none of the three.

## Watch out

- `IntBuffer b = a;` contains `=`, but it creates `b`. The copy constructor runs, not the
  assignment.

## Try it

1. Add this function to `main.cpp` and call `show(a);`. Predict what is printed. What
   changes when the parameter is `const IntBuffer& buffer`?

```cpp
void show(IntBuffer buffer) {
    std::cout << buffer.size() << " ints\n";
}
```

2. Remove the `if` and its `}` from `operator=`, and add `a = a;` before the last line of
   `main`. What does `a[0]` print now?

<details>
<summary>Answers</summary>

1. `copy constructor`, then `3 ints`: passing by value copies the object. With the
   reference only `3 ints` is printed, because nothing is copied.
2. A meaningless number instead of `7`: `a` deleted its values before it copied them.
   This is undefined behaviour.
</details>

**Next:** [Moving objects](../03-moving-objects/README.md)
