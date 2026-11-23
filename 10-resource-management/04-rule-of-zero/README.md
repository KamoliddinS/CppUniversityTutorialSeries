# The rule of zero

> **Goal:** write classes that need no destructor, no copy functions and no move functions.

## Let a member own the memory

The five functions of the last lesson took about forty lines, and each line was a chance
for a bug. `std::vector<int>` already has all five, and they are correct. So make a vector
the member and delete your own five:

**`rule_of_zero.cpp`**
<!-- file: rule_of_zero.cpp -->
```cpp
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

class IntBuffer {
public:
    explicit IntBuffer(std::size_t size) : data_(size) {}       // a vector of size zeros
    int& operator[](std::size_t index) { return data_[index]; }
    std::size_t size() const { return data_.size(); }

private:
    std::vector<int> data_;         // the vector owns the memory
};

int main() {
    IntBuffer a(3);
    a[0] = 7;

    IntBuffer b = a;                // copies the vector: b gets its own elements
    b[0] = 99;
    std::cout << "a[0] = " << a[0] << ", b[0] = " << b[0] << '\n';

    IntBuffer c = std::move(a);     // moves the vector: c takes over the elements of a
    std::cout << "a has " << a.size() << " ints, c has " << c.size() << '\n';
}
```

<!-- output: rule_of_zero -->
```text
a[0] = 7, b[0] = 99
a has 0 ints, c has 3
```

- You wrote none of the five, so the compiler generates them. Each one handles the members
  one by one, and the vector member copies, moves and frees its own memory.
- There is no `new` and no `delete`, so there is nothing to forget.

**Rule of zero:** let members such as `std::vector`, `std::string` and the smart pointers of
the next lessons own the resources, and write none of the five functions. Prefer this
whenever you can.

## Say what you want: `= default` and `= delete`

Sometimes the generated functions are not what you want. One seat has one ticket, so a
`Ticket` must not be copied:

**`no_copy_nocompile.cpp`**
<!-- file: no_copy_nocompile.cpp -->
```cpp
#include <iostream>
#include <string>

class Ticket {
public:
    explicit Ticket(const std::string& seat) : seat_(seat) {}
    Ticket(const Ticket& other) = delete;               // no copy constructor
    Ticket& operator=(const Ticket& other) = delete;    // no copy assignment
    Ticket(Ticket&& other) = default;                   // moving is allowed
    Ticket& operator=(Ticket&& other) = default;
    const std::string& seat() const { return seat_; }

private:
    std::string seat_;
};

int main() {
    Ticket first("12A");
    Ticket second = first;          // a second ticket for the same seat?
    std::cout << second.seat() << '\n';
}
```

<!-- errors: no_copy_nocompile -->
```text
no_copy_nocompile.cpp: In function ‘int main()’:
no_copy_nocompile.cpp:19:21: error: use of deleted function ‘Ticket::Ticket(const Ticket&)’
   19 |     Ticket second = first;          // a second ticket for the same seat?
      |                     ^~~~~
no_copy_nocompile.cpp:7:5: note: declared here
    7 |     Ticket(const Ticket& other) = delete;               // no copy constructor
      |     ^~~~~~
```

| You write | Meaning |
|-----------|---------|
| `= delete` | this function is forbidden: every use of it is a compile error |
| `= default` | generate the usual version for me, as in [Constructors](../../07-classes/02-constructors/README.md) |

## Watch out

- Do not add an empty destructor "to be safe". When a class declares a destructor, the
  compiler stops generating the two move functions, and every move silently becomes a copy.

## Try it

1. Add `~IntBuffer() {}` to the class in `rule_of_zero.cpp`. Predict the last line of the
   output.
2. Change one line of `main` in `no_copy_nocompile.cpp` so that it builds. Keep both
   `= delete` lines.

<details>
<summary>Answers</summary>

1. `a has 3 ints, c has 3`. The move functions are gone, so `std::move(a)` only copies and
   `a` keeps its elements.
2. `Ticket second = std::move(first);` (and `#include <utility>`). The ticket is handed over,
   not copied, and the move constructor exists.
</details>

**Next:** [unique_ptr](../05-unique-ptr/README.md)
