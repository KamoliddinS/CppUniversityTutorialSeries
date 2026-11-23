# RAII

> **Goal:** release a resource automatically by putting the clean-up into a destructor.

## One way out skips the clean-up

A **resource** is anything a program must give back after use, such as heap memory or an
open file. This function takes memory at the top and gives it back at the bottom:

**`early_return_bug.cpp`**
<!-- file: early_return_bug.cpp -->
```cpp
#include <cstddef>
#include <iostream>

void report(std::size_t days) {
    int* visitors = new int[days]{};        // take: one counter for each day
    if (days < 7) {
        std::cout << "Need at least a week of data.\n";
        return;                             // leaves early: the delete[] below never runs
    }
    visitors[0] = 120;
    std::cout << "First day: " << visitors[0] << " visitors\n";
    delete[] visitors;                      // give back
}

int main() {
    report(7);
    report(3);
}
```

Built with the sanitizer
([What goes wrong](../../09-pointers-and-memory/06-what-goes-wrong/README.md)), it reports:

```text
==3538257==ERROR: LeakSanitizer: detected memory leaks
Direct leak of 12 byte(s) in 1 object(s) allocated from:
    #1 0x571737186382 in report(unsigned long) .../early_return_bug.cpp:5
```

`report(3)` leaves at the `return`, so its three `int`s are never given back. You could add
a `delete[]` there. But every new way out needs one more, and one day you forget it.

## Let a destructor do it

A destructor runs whenever the life of an object ends, on every way out of the function
([Destructors and lifetime](../../07-classes/03-destructors-and-lifetime/README.md)).
So put the `new` into a constructor and the `delete[]` into the destructor:

**`raii.cpp`**
<!-- file: raii.cpp -->
```cpp
#include <cstddef>
#include <iostream>

class IntBuffer {
public:
    explicit IntBuffer(std::size_t size) : size_(size), data_(new int[size]{}) {
        std::cout << "  take " << size_ << " ints\n";
    }
    ~IntBuffer() {
        std::cout << "  give back " << size_ << " ints\n";
        delete[] data_;
    }
    int& operator[](std::size_t index) { return data_[index]; }
    std::size_t size() const { return size_; }

private:
    std::size_t size_ = 0;
    int* data_ = nullptr;
};

void report(std::size_t days) {
    IntBuffer visitors(days);
    if (days < 7) {
        std::cout << "Need at least a week of data.\n";
        return;                             // the destructor runs here ...
    }
    visitors[0] = 120;
    std::cout << "First day: " << visitors[0] << " visitors\n";
}                                           // ... and here

int main() {
    report(7);
    report(3);
}
```

<!-- output: raii -->
```text
  take 7 ints
First day: 120 visitors
  give back 7 ints
  take 3 ints
Need at least a week of data.
  give back 3 ints
```

- `visitors` owns the memory: its constructor takes it, its destructor gives it back.
- `report` contains no `delete[]`, so it cannot forget one. Both calls print `give back`.

The constructor takes the resource and the destructor gives it back: this pattern is called
**RAII** ("resource acquisition is initialisation"). `std::vector`, `std::string` and file
streams all work this way. That is why a vector never leaks and a file closes itself.

## Watch out

- RAII needs an object that is destroyed automatically. An `IntBuffer` created with `new`
  lives until you `delete` it.
- This `IntBuffer` is not finished: a copy of it breaks the program. The next lesson shows why.

## Try it

1. Add a second early `return` to `report` in `raii.cpp`, for `days > 365`. What else must
   you change?
2. Predict the output when `main` in `raii.cpp` holds only these lines. Then run it.

```cpp
IntBuffer a(2);
{
    IntBuffer b(5);
}
std::cout << "end of main\n";
```

<details>
<summary>Answers</summary>

1. Nothing. The destructor runs at the new `return` too.
2. `take 2 ints`, `take 5 ints`, `give back 5 ints`, `end of main`, `give back 2 ints`.
   `b` is destroyed at the `}` of its block, `a` at the end of `main`.
</details>

**Next:** [Copying objects](../02-copying-objects/README.md)
