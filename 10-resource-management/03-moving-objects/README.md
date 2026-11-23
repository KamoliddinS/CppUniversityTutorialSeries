# Moving objects

> **Goal:** hand a resource over to another object instead of copying it.

## Take over instead of copying

A copy of a buffer with a million `int`s copies a million `int`s. That is wasted work when
the original is thrown away right after. A **move** is cheaper: the new object takes over
the block of the old one and leaves the old one empty.

Two more functions in [`int_buffer.cpp`](move/int_buffer.cpp) do this:

<!-- snippet: move/int_buffer.cpp -->
```cpp
IntBuffer::IntBuffer(IntBuffer&& other) noexcept : size_(other.size_), data_(other.data_) {
    other.size_ = 0;
    other.data_ = nullptr;                  // other is empty: its destructor deletes nothing
}

IntBuffer& IntBuffer::operator=(IntBuffer&& other) noexcept {
    if (this != &other) {
        delete[] data_;                     // give back the block held so far
        size_ = other.size_;
        data_ = other.data_;                // take over the block of other
        other.size_ = 0;
        other.data_ = nullptr;
    }
    return *this;
}
```

`IntBuffer&&` accepts only an object that is about to disappear, or one that you marked
with `std::move`. `noexcept` promises that no exception leaves the function
([Your own exceptions](../../13-exceptions/04-your-own-exceptions/README.md)). A growing
`std::vector` moves its elements only when their move constructor is `noexcept`; otherwise
it copies them.

`IntBuffer c = std::move(a);` changes the owner, not the block. Before:

| Name | Address | Value |
|------|---------|-------|
| `a.data_` | `0x1008` | `0x5000` |
| heap block | `0x5000` | 1000 `int`s |

After:

| Name | Address | Value |
|------|---------|-------|
| `a.data_` | `0x1008` | `nullptr` |
| `c.data_` | `0x1018` | `0x5000` |
| heap block | `0x5000` | 1000 `int`s |

## Which function runs?

In this lesson every copy and move function prints its name.

**`move/main.cpp`**
<!-- file: move/main.cpp -->
```cpp
#include <iostream>
#include <utility>

#include "int_buffer.h"

IntBuffer makeBuffer() {
    IntBuffer result(1000);
    result[0] = 7;
    return result;                  // plain return: no std::move
}

int main() {
    IntBuffer a(1000);

    std::cout << "1\n";
    IntBuffer b = a;                // a keeps its block: copy
    std::cout << "2\n";
    IntBuffer c = std::move(a);     // a gives its block away: move
    std::cout << "3\n";
    IntBuffer d = makeBuffer();     // result is built directly in d
    std::cout << "4\n";
    b = makeBuffer();               // the returned buffer is a temporary: move
    std::cout << "a has " << a.size() << " ints, c has " << c.size() << '\n';
}
```

<!-- output: move -->
```text
1
  copy constructor
2
  move constructor
3
4
  move assignment
a has 0 ints, c has 1000
```

- Step 3 prints nothing: the compiler builds `result` directly in `d`, with no copy and no
  move. A compiler that cannot do that moves `result`. It never copies it.
- Step 4: the returned buffer is a **temporary**, an object without a name that disappears
  at the end of the statement. It is moved without `std::move`.

**Rule of five:** a class that needs one of these functions usually needs all five.

<!-- snippet: move/int_buffer.h -->
```cpp
~IntBuffer() { delete[] data_; }                    // 1 destructor
IntBuffer(const IntBuffer& other);                  // 2 copy constructor
IntBuffer& operator=(const IntBuffer& other);       // 3 copy assignment operator
IntBuffer(IntBuffer&& other) noexcept;              // 4 move constructor
IntBuffer& operator=(IntBuffer&& other) noexcept;   // 5 move assignment operator
```

Without 4 and 5 the class still works, but every move becomes a copy.

## Watch out

- `std::move(a)` moves nothing. It only gives permission to take the block of `a`. The
  move constructor or the move assignment does the work.
- After `std::move(a)`, do not rely on the old value of `a`. Give it a new value or stop
  using it.
- Do not write `return std::move(result);`. Plain `return result;` is never slower, and
  `g++` warns that the `std::move` prevents building in place.

## Try it

Add this function to `main.cpp`, and the line `IntBuffer e = withFirst(c, 5);` to the end
of `main`. Predict what the new line prints.

```cpp
IntBuffer withFirst(IntBuffer buffer, int value) {
    buffer[0] = value;
    return buffer;
}
```

<details>
<summary>Answer</summary>

`copy constructor`, then `move constructor`. `c` is copied into the parameter `buffer`.
A parameter cannot be built directly in `e`, so `return buffer;` moves it, without
`std::move`.
</details>

**Next:** [The rule of zero](../04-rule-of-zero/README.md)
