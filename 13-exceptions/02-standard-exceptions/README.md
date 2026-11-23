# Standard exceptions

> **Goal:** catch the standard library's exception types, the most specific one first.

## One family

`std::runtime_error` belongs to a family of classes. They all derive from `std::exception`.

```text
std::exception                     <exception>
├── std::logic_error               <stdexcept>   the caller broke a rule
│   ├── std::invalid_argument      <stdexcept>   std::stoi("abc")
│   └── std::out_of_range          <stdexcept>   v.at(10)
├── std::runtime_error             <stdexcept>   a problem found while running
│   └── std::overflow_error        <stdexcept>   a result is too large
└── std::bad_alloc                 <new>         no memory left
```

A handler for a base class also fits every class derived from it.

## Handlers are tried from top to bottom

The first handler that fits runs, and the others are skipped. So this order is wrong:

**`wrong_order_bug.cpp`**
<!-- file: wrong_order_bug.cpp -->
```cpp
#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    try {
        int age = std::stoi("abc");
        std::cout << "age " << age << '\n';
    } catch (const std::exception& e) {         // fits every standard exception
        std::cout << "error: " << e.what() << '\n';
    } catch (const std::invalid_argument&) {    // too late: never reached
        std::cout << "not a number\n";
    }
}
```

<!-- errors: wrong_order_bug -->
```text
wrong_order_bug.cpp: In function ‘int main()’:
wrong_order_bug.cpp:11:7: warning: exception of type ‘std::invalid_argument’ will be caught by earlier handler [-Wexceptions]
   11 |     } catch (const std::invalid_argument&) {    // too late: never reached
      |       ^~~~~
wrong_order_bug.cpp:9:7: note: for type ‘std::exception’
    9 |     } catch (const std::exception& e) {         // fits every standard exception
      |       ^~~~~
```

The first handler fits every standard exception. The program prints `error: stoi`, and
the second handler can never run.

## The specific type goes first

**`handlers.cpp`**
<!-- file: handlers.cpp -->
```cpp
#include <iostream>
#include <stdexcept>
#include <string>

int toAge(const std::string& text) {
    int age = std::stoi(text);      // may throw std::invalid_argument or std::out_of_range
    if (age < 0) {
        throw std::runtime_error("an age cannot be negative");
    }
    return age;
}

void show(const std::string& text) {
    try {
        int age = toAge(text);
        std::cout << text << ": age " << age << '\n';
    } catch (const std::invalid_argument&) {
        std::cout << text << ": not a number\n";
    } catch (const std::out_of_range&) {
        std::cout << text << ": too large for an int\n";
    } catch (const std::exception& e) {     // every other standard exception
        std::cout << text << ": " << e.what() << '\n';
    }
}

int main() {
    show("19");
    show("abc");
    show("99999999999");
    show("-5");
}
```

<!-- output: handlers -->
```text
19: age 19
abc: not a number
99999999999: too large for an int
-5: an age cannot be negative
```

- Catch by `const` reference, as in `const std::exception& e`: nothing is copied.
- A handler that does not use the exception needs no name for it.

## Pass it on, or catch anything

**`rethrow.cpp`**
<!-- file: rethrow.cpp -->
```cpp
#include <exception>
#include <iostream>
#include <stdexcept>

void writeFile() {
    throw std::runtime_error("disk is full");
}

void saveReport() {
    try {
        writeFile();
    } catch (const std::exception& e) {
        std::cout << "saveReport: " << e.what() << '\n';
        throw;                      // pass the same exception on
    }
}

int main() {
    try {
        saveReport();
    } catch (const std::runtime_error& e) {
        std::cout << "main: " << e.what() << '\n';
    }

    try {
        throw 42;                   // legal, but 42 is not a std::exception
    } catch (const std::exception&) {
        std::cout << "not reached\n";
    } catch (...) {
        std::cout << "main: caught something else\n";
    }
}
```

<!-- output: rethrow -->
```text
saveReport: disk is full
main: disk is full
main: caught something else
```

- `throw;` inside a handler **rethrows**: the same exception goes on to the next `try`
  block around it. It keeps its real type, so `main` catches a `std::runtime_error`.
- `catch (...)` fits anything. It must be the last handler, and it gives you no object to ask.
- Other types can be thrown too, even an `int`. Such a value is not a `std::exception`, so
  `catch (const std::exception&)` does not catch everything. Throw only classes of this family.

## Watch out

- `catch (std::exception e)` copies only the base part, so your message is lost. g++ warns.
- `std::exception` is an ordinary class, not an abstract one. `throw std::exception();`
  compiles, but it carries no message of yours: with g++, `what()` gives just
  `std::exception`. Throw a derived class.

## Try it

1. Suppose `toAge` in `handlers.cpp` throws a `std::overflow_error`. Which handler runs?
   And which one for `throw 42;`?
2. Delete the line `throw;` in `rethrow.cpp`. Predict the output.

<details>
<summary>Answers</summary>

1. The third: a `std::overflow_error` is a `std::runtime_error`, and so a `std::exception`.
   For `42`, none: the exception leaves `show`, and the program ends.
2. `saveReport: disk is full`, then `main: caught something else`. The first exception
   ends in `saveReport`, so `main` never sees it.
</details>

**Next:** [Stack unwinding](../03-stack-unwinding/README.md)
