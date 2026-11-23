# Constants

> **Goal:** give a fixed value a name with `const` or `constexpr`, so that nobody changes it by mistake.

## A number without a name

**`magic.cpp`**
<!-- file: magic.cpp -->
```cpp
#include <iostream>

int main() {
    int bill = 250000;
    std::cout << "Service: " << bill * 15 / 100 << " so'm\n";
    std::cout << "To pay:  " << bill + bill * 15 / 100 << " so'm\n";
}
```

<!-- output: magic -->
```text
Service: 37500 so'm
To pay:  287500 so'm
```

What is `15`? The reader has to guess. And when the cafe changes its service charge, you
must find every `15` in the program and not touch a `15` that means something else. A number
like this is called a **magic number**.

## Give it a name

**`cafe_bill.cpp`**
<!-- file: cafe_bill.cpp -->
```cpp
#include <iostream>

int main() {
    // A fixed fact: known when the program is built.
    constexpr int servicePercent = 15;

    std::cout << "Bill: ";
    int bill = 0;
    std::cin >> bill;

    // Worked out from what the user types: known only when the program runs.
    const int service = bill * servicePercent / 100;

    std::cout << "Service: " << service << " so'm\n";
    std::cout << "To pay:  " << bill + service << " so'm\n";
}
```

<!-- session: cafe_bill -->
```text
Bill: 250000
Service: 37500 so'm
To pay:  287500 so'm
```

A **constant** is a variable whose value cannot change after it is set. Now the code says
what `15` means, and the number is written in one place.

| | `const` | `constexpr` |
|---|---------|-------------|
| Can the value change later? | no | no |
| The value must be known | when the line runs | when the program is built |
| Use it for | a result you work out once | a fixed fact written in the code |

## The compiler protects a constant

**`change_nocompile.cpp`**
<!-- file: change_nocompile.cpp -->
```cpp
#include <iostream>

int main() {
    const int servicePercent = 15;
    servicePercent = 20;            // a constant cannot get a new value
    std::cout << servicePercent << '\n';
}
```

<!-- errors: change_nocompile -->
```text
change_nocompile.cpp: In function ‘int main()’:
change_nocompile.cpp:5:20: error: assignment of read-only variable ‘servicePercent’
    5 |     servicePercent = 20;            // a constant cannot get a new value
      |     ~~~~~~~~~~~~~~~^~~~
```

The compiler calls a constant a *read-only variable*. A `constexpr` variable is protected
in the same way.

## Watch out

- A constant needs its value in the line that creates it. `const int days;` does not compile.
- Constants are named like variables in this course: `servicePercent`, not `SERVICE_PERCENT`.
- Old code writes `#define SERVICE_PERCENT 15`. That is plain text replacement before
  compiling: the name has no type, and it is replaced everywhere below that line, wanted or
  not. This course does not use `#define` for constants.

## Try it

1. In `cafe_bill.cpp`, change `const int service` to `constexpr int service` and build.
   What does the compiler say, and why?
2. Which number in [`divide.cpp`](../04-arithmetic/divide.cpp) should have a name? Give it one.

<details>
<summary>Answers</summary>

1. `error: the value of 'bill' is not usable in a constant expression`. The user types the
   bill while the program runs, so `service` cannot be known when the program is built.
2. `60`. Write `constexpr int minutesPerHour = 60;` and use the name in both places.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)
