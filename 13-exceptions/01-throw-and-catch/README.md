# Throw and catch

> **Goal:** report an error with `throw` and handle it somewhere else with `try` and `catch`.

## A function that cannot do its job

The function `withdraw` finds that the balance is too low. It cannot do its job, and only
the caller knows what to do next. A special return value such as `-1` is easy to ignore.
So `withdraw` throws an **exception**: an object that describes the problem.

**`uncaught_bug.cpp`**
<!-- file: uncaught_bug.cpp -->
```cpp
#include <iostream>
#include <stdexcept>

int withdraw(int balance, int amount) {
    if (amount > balance) {
        throw std::runtime_error("balance too low");   // leaves the function here
    }
    std::cout << "Paid out " << amount << " so'm\n";
    return balance - amount;
}

int main() {
    int balance = withdraw(50000, 90000);   // nobody catches the exception
    std::cout << "Balance: " << balance << " so'm\n";
}
```

`throw` leaves the function at once. The lines after it do not run, and nothing is
returned. Here nobody catches the exception. Such an **uncaught exception** ends the
program: C++ calls `std::terminate`, which stops it at once. Built with g++:

```text
terminate called after throwing an instance of 'std::runtime_error'
  what():  balance too low
Aborted (core dumped)
```

You have seen this before: [`v.at(10)`](../../05-vectors-and-strings/01-vectors/README.md)
and [`std::stoi("abc")`](../../06-structs-and-files/04-parse-lines/README.md) threw
exceptions, and nobody caught them.

## Catch it

[`withdraw.cpp`](withdraw.cpp) has the same function. `main` now has a `try` block:

<!-- snippet: withdraw.cpp -->
```cpp
int main() {
    int balance = 50000;
    try {
        balance = withdraw(balance, 20000);
        balance = withdraw(balance, 90000);
        std::cout << "This line is skipped.\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Refused: " << e.what() << '\n';
    }
    std::cout << "Balance: " << balance << " so'm\n";
}
```

<!-- output: withdraw -->
```text
Paid out 20000 so'm
Refused: balance too low
Balance: 30000 so'm
```

1. The second call throws. Control jumps to the nearest `try` block that is still running
   and has a `catch` for this type. The rest of that block is skipped.
2. The `catch` block, the **handler**, runs. `e.what()` gives the text of the exception.
3. The program goes on below the handler. Without an exception, the handler is skipped.

## C++ does not throw for you

A handler only catches what some code throws. Most mistakes throw nothing:

| Code | Does it throw? |
|------|----------------|
| a whole number divided by `0` | no: undefined behaviour. `Floating point exception` on Linux is not a C++ exception |
| `v[10]` on a short vector | no: undefined behaviour |
| `v.at(10)` on a short vector | yes: `std::out_of_range` |
| `std::stoi("abc")` | yes: `std::invalid_argument` |
| `new` when memory runs out | yes: `std::bad_alloc` |

So test first, and throw yourself.

## Watch out

- A variable declared inside the `try` block does not exist in the handler or below it.
  So `balance` is declared before `try`.

## Try it

1. Predict the output of `withdraw.cpp` when the first call asks for `60000` instead of `20000`.
2. Write `int perStudent(int sweets, int students)` that throws a `std::runtime_error` when
   `students` is `0`. Call it from a `try` block.

<details>
<summary>Answers</summary>

1. `Refused: balance too low`, then `Balance: 50000 so'm`. The first call throws, so the
   second call is skipped too.
2. Test before you divide:

```cpp
int perStudent(int sweets, int students) {
    if (students == 0) {
        throw std::runtime_error("no students");
    }
    return sweets / students;
}
```
</details>

**Next:** [Standard exceptions](../02-standard-exceptions/README.md)
