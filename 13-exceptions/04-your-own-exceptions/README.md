# Your own exceptions

> **Goal:** write an exception class of your own, and say what `noexcept` promises.

## A class for one kind of error

A handler chooses by type. With a class of your own, a handler can catch exactly your
error, and the exception can carry more than text.

**`balance_too_low.cpp`**
<!-- file: balance_too_low.cpp -->
```cpp
#include <iostream>
#include <stdexcept>

class BalanceTooLow : public std::runtime_error {
public:
    explicit BalanceTooLow(int missing)
        : std::runtime_error("balance too low"), missing_(missing) {}

    int missing() const noexcept { return missing_; }

private:
    int missing_;       // what the handler needs besides the text
};

int withdraw(int balance, int amount) {
    if (amount > balance) {
        throw BalanceTooLow(amount - balance);
    }
    return balance - amount;
}

int main() {
    int balance = 50000;
    try {
        balance = withdraw(balance, 20000);
        balance = withdraw(balance, 90000);
    } catch (const BalanceTooLow& e) {
        std::cout << "Refused: " << e.what() << ", " << e.missing() << " so'm missing\n";
    }
    std::cout << "Balance: " << balance << " so'm\n";
}
```

<!-- output: balance_too_low -->
```text
Refused: balance too low, 60000 so'm missing
Balance: 30000 so'm
```

- Derive from `std::runtime_error` and pass the message to its constructor. Usually that
  is all: `what()` is inherited.
- Add data members when the handler needs more than text. Here it is the missing amount.
- A handler for `std::runtime_error` or `std::exception` fits a `BalanceTooLow` too.

## noexcept is a promise

`noexcept` after the parameter list promises that no exception leaves the function. You saw
it in [Moving objects](../../10-resource-management/03-moving-objects/README.md).
`missing()` keeps that promise. `half` breaks it:

<!-- snippet: noexcept_bug.cpp -->
```cpp
int half(int number) noexcept {     // promise: no exception leaves this function
    if (number % 2 != 0) {
        throw std::runtime_error("odd number");     // breaks the promise
    }
    return number / 2;
}
```

<!-- errors: noexcept_bug -->
```text
noexcept_bug.cpp: In function ‘int half(int)’:
noexcept_bug.cpp:6:9: warning: ‘throw’ will always call ‘terminate’ [-Wterminate]
    6 |         throw std::runtime_error("odd number");     // breaks the promise
      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
```

[`noexcept_bug.cpp`](noexcept_bug.cpp) calls `half(7)` inside a `try` block with a fitting
handler. That does not help: a broken promise terminates the program.

```text
terminate called after throwing an instance of 'std::runtime_error'
  what():  odd number
Aborted (core dumped)
```

## Constructors and destructors

| | May an exception leave it? | What happens |
|---|---|---|
| Constructor | yes: it has no return value to report a failure | The object never existed, so its destructor does not run. The members that were already built are destroyed. |
| Destructor | never | A destructor is `noexcept` by default: an exception that leaves it terminates the program. |

## Watch out

- You rarely need your own `what()`. If you write one, its exact form is
  `const char* what() const noexcept override`.

## Try it

**`constructor_throws.cpp`**
<!-- file: constructor_throws.cpp -->
```cpp
#include <iostream>
#include <stdexcept>

class Engine {
public:
    Engine() { std::cout << "Engine built\n"; }
    ~Engine() { std::cout << "Engine destroyed\n"; }
};

class Car {
public:
    explicit Car(int seats) {
        if (seats < 1) {
            throw std::invalid_argument("a car needs a seat");
        }
        std::cout << "Car built\n";
    }
    ~Car() { std::cout << "Car destroyed\n"; }

private:
    Engine engine_;
};

int main() {
    try {
        Car car(0);
        std::cout << "driving\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
}
```

1. Predict the output of this program.
2. In `balance_too_low.cpp`, change the handler to `catch (const std::runtime_error& e)`.
   Which line stops compiling?

<details>
<summary>Answers</summary>

<!-- output: constructor_throws -->
```text
Engine built
Engine destroyed
caught: a car needs a seat
```

1. `engine_` is built before the body of the constructor runs, so it is destroyed again.
   `Car built`, `driving` and `Car destroyed` never appear: there never was a `Car`.
2. The line with `e.missing()`. A `std::runtime_error` has no such function.
</details>

**Next:** [Exceptions or return values](../05-exceptions-or-return-values/README.md)
