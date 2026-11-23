# Headers and source files

> **Goal:** split a class into a header file and a source file, and build a program from several files.

## One class, two files

A class written inside `main.cpp` can be used only there. Split it, and every file of the
program can use it. The folder [`bank`](bank/) holds three files:

| File | Holds |
|------|-------|
| `account.h` | the class definition: what the class offers. This is a **header file** |
| `account.cpp` | the bodies of the member functions |
| `main.cpp` | code that uses the class |

```text
account.h ──(#include)──┬──► account.cpp ──► compile ──┐
                        │                              ├──► link ──► bank
                        └──► main.cpp ─────► compile ──┘
```

**`bank/account.h`**
<!-- file: bank/account.h -->
```cpp
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
    explicit Account(int amount);

    void deposit(int amount);
    bool withdraw(int amount);
    int balance() const;

private:
    int balance_ = 0;   // so'm; never negative
};

#endif
```

**`bank/account.cpp`**
<!-- file: bank/account.cpp -->
```cpp
#include "account.h"

Account::Account(int amount) : balance_(amount) {
    if (balance_ < 0) {
        balance_ = 0;
    }
}

void Account::deposit(int amount) {
    if (amount > 0) {
        balance_ += amount;
    }
}

bool Account::withdraw(int amount) {
    if (amount <= 0 || amount > balance_) {
        return false;
    }
    balance_ -= amount;
    return true;
}

int Account::balance() const {
    return balance_;
}
```

**`bank/main.cpp`**
<!-- file: bank/main.cpp -->
```cpp
#include <iostream>

#include "account.h"

int main() {
    Account account(120000);
    account.deposit(30000);
    if (!account.withdraw(500000)) {
        std::cout << "Not enough money.\n";
    }
    std::cout << "Balance: " << account.balance() << " so'm\n";
}
```

In the folder `bank`, give every `.cpp` file to `g++`. Headers are not listed: `#include`
copies them into the `.cpp` files.

```sh
g++ -std=c++20 -Wall -Wextra main.cpp account.cpp -o bank
./bank
```

<!-- output: bank -->
```text
Not enough money.
Balance: 150000 so'm
```

- `#include "account.h"` has quotes: the compiler looks for the file next to this one
  first. `<...>` is for library headers.
- In `account.cpp`, every body starts like its declaration, with `Account::` in front of the
  name: "the `deposit` of class `Account`". `const` is repeated there; `explicit` is not.
- The lines `#ifndef`, `#define` and `#endif` are an *include guard*: if the header reaches
  the same file twice, the second copy is skipped. Many projects write one line instead:
  `#pragma once`.

## A forgotten file

Leave `account.cpp` out of the `g++` command, and the build fails.
[`main_alone_nocompile.cpp`](main_alone_nocompile.cpp) is `main.cpp` built that way:

<!-- errors: main_alone_nocompile -->
```text
ld: program.o: in function `main':
main_alone_nocompile.cpp:(.text+0x29): undefined reference to `Account::Account(int)'
ld: main_alone_nocompile.cpp:(.text+0x3a): undefined reference to `Account::deposit(int)'
ld: main_alone_nocompile.cpp:(.text+0x4b): undefined reference to `Account::withdraw(int)'
ld: main_alone_nocompile.cpp:(.text+0x93): undefined reference to `Account::balance() const'
collect2: error: ld returned 1 exit status
```

The header promised the functions, so compiling worked. Then the linker found no bodies.
[Build errors](../../01-first-programs/04-build-errors/README.md) shows how to read this message.

## Watch out

- Without the include guard, a file that gets the header twice stops with
  `redefinition of 'class Account'`.
- Other people's code often has the line `using namespace std;`, which lets them leave out
  `std::`. Never put it in a header: every file that includes the header gets it too.

## Try it

1. Delete `Account::` in front of `deposit` in `account.cpp`. Predict who complains: the
   compiler or the linker?
2. Add a member function `isEmpty` that returns `true` when the balance is 0. Declare it in
   `account.h`, define it in `account.cpp`, call it in `main.cpp`.

<details>
<summary>Answers</summary>

1. The compiler: `'balance_' was not declared in this scope`. Without `Account::`, `deposit`
   is an ordinary function that knows nothing about the class.
2. In the header: `bool isEmpty() const;`. In the source file:
   `bool Account::isEmpty() const { return balance_ == 0; }`
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)
