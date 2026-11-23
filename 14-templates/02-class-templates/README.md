# Class templates

> **Goal:** write a class that holds values of any type, and put it in a header.

## A class with the type left open

You have used a **class template** since
[Vectors](../../05-vectors-and-strings/01-vectors/README.md): `std::vector` is a pattern
for classes with the element type left open. You can write your own.

**`box.cpp`**
<!-- file: box.cpp -->
```cpp
#include <iostream>
#include <string>

template <typename T>
class Box {
public:
    explicit Box(const T& value) : value_(value) {}

    const T& get() const { return value_; }
    void set(const T& value) { value_ = value; }

private:
    T value_;
};

int main() {
    Box<int> number(42);
    Box<std::string> city("Khiva");
    city.set("Bukhara");

    std::cout << number.get() << '\n';
    std::cout << city.get() << '\n';
}
```

<!-- output: box -->
```text
42
Bukhara
```

- Inside the class, `T` is used like any other type.
- You say the type in angle brackets: the `int` in `Box<int>` is the **template argument**.
- `Box<int>` and `Box<std::string>` are two separate classes. The compiler writes each one
  from the pattern.
- A template argument can also be a value: the `5` in `std::array<int, 5>`
  ([Arrays](../../05-vectors-and-strings/06-arrays/README.md)).

## A stack in a header

A stack is a pile: you put a value on top, and you take the top value off. This class
template keeps its values in a `std::vector<T>`. It is in `stack.h`:

**`stack/stack.h`**
<!-- file: stack/stack.h -->
```cpp
#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T>
class Stack {
public:
    void push(const T& value) { items_.push_back(value); }

    void pop() {
        if (items_.empty()) {
            throw std::out_of_range("the stack is empty");
        }
        items_.pop_back();
    }

    const T& top() const {
        if (items_.empty()) {
            throw std::out_of_range("the stack is empty");
        }
        return items_.back();
    }

    bool empty() const { return items_.empty(); }
    std::size_t size() const { return items_.size(); }

private:
    std::vector<T> items_;
};

#endif
```

`main.cpp` uses it with two types:

**`stack/main.cpp`**
<!-- file: stack/main.cpp -->
```cpp
#include <iostream>
#include <stdexcept>
#include <string>

#include "stack.h"

int main() {
    Stack<int> numbers;
    numbers.push(10);
    numbers.push(20);
    std::cout << numbers.top() << " is on top of " << numbers.size() << " numbers\n";

    Stack<std::string> cities;
    cities.push("Tashkent");
    cities.push("Samarkand");
    cities.pop();                    // removes Samarkand
    std::cout << cities.top() << '\n';

    try {
        cities.pop();
        cities.pop();                // the stack is already empty
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
}
```

```sh
g++ -std=c++20 -Wall -Wextra main.cpp -o stack
./stack
```

<!-- output: stack -->
```text
20 is on top of 2 numbers
Tashkent
Error: the stack is empty
```

- `pop` and `top` check first, and throw `std::out_of_range` when the stack is empty
  ([Standard exceptions](../../13-exceptions/02-standard-exceptions/README.md)).
  `back()` on an empty vector is undefined behaviour.
- The whole class template is in the header, with the function bodies inside the class.

## Why there is no stack.cpp

[`split_nocompile`](split_nocompile/) moves the bodies to a `stack.cpp`, as
[Headers and source files](../../07-classes/06-headers-and-source-files/README.md) does for
an ordinary class. Both files compile, but linking fails:

<!-- errors: split_nocompile -->
```text
ld: program.o: in function `main':
main.cpp:(.text+0x3f): undefined reference to `Stack<int>::push(int const&)'
ld: main.cpp:(.text+0x4b): undefined reference to `Stack<int>::size() const'
collect2: error: ld returned 1 exit status
```

To write `Stack<int>::push`, the compiler needs two things in one file: a use of
`Stack<int>` and the body of `push`. `main.cpp` has the use, but sees only the header.
`stack.cpp` has the bodies, but no use. So the function is never written, and the linker
cannot find it.

## Watch out

- `Stack numbers;` does not compile: the template argument is missing. Write
  `Stack<int> numbers;`.
- Do not use this `Stack` in a real program. The standard library has `std::stack`
  ([Stack, queue and priority queue](../../15-standard-library/06-stack-queue-priority-queue/README.md)).

## Try it

1. Predict: you push `Aziz`, `Malika` and `Jasur` onto a `Stack<std::string>`, then call
   `pop()` once. What do `top()` and `size()` return?
2. Make `split_nocompile` build: move the two bodies into the class in `stack.h`.

<details>
<summary>Answers</summary>

1. `Malika` and `2`. `pop()` removed `Jasur`, the value that was added last.
2. In the class, write `void push(const T& value) { items_.push_back(value); }` and
   `std::size_t size() const { return items_.size(); }`. Delete `stack.cpp` and build
   `main.cpp` alone.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)
