# Constructors

> **Goal:** write a constructor, so that every object is valid from the moment it exists.

## First values for a new object

An account needs an owner and a first balance, but `main` cannot set private members. The
**constructor** is the member function that fills them. It runs automatically when an object
is created.

**`account.cpp`**
<!-- file: account.cpp -->
```cpp
#include <iostream>
#include <string>

class Account {
public:
    Account(const std::string& owner, int amount) : owner_(owner), balance_(amount) {
        if (balance_ < 0) {
            balance_ = 0;       // an account never starts below zero
        }
    }

    void print() {
        std::cout << owner_ << ": " << balance_ << " so'm\n";
    }

private:
    std::string owner_;
    int balance_ = 0;
};

int main() {
    Account malika("Malika", 50000);
    Account jasur{"Jasur", -700};   // braces work too
    malika.print();
    jasur.print();
}
```

<!-- output: account -->
```text
Malika: 50000 so'm
Jasur: 0 so'm
```

| Part | Meaning |
|------|---------|
| `Account(...)` | a constructor has the name of the class and no return type |
| `: owner_(owner), balance_(amount)` | the *member initialiser list* gives each member its first value |
| `{ ... }` | the body runs next. Here it repairs a bad amount |
| `int balance_ = 0;` | a default member value, for when the list does not name the member. With neither, an `int` member has no value, and reading it is undefined behaviour |

## The default constructor

A **default constructor** is a constructor that can be called without arguments. The compiler
writes one for you, but only as long as you write no constructor yourself:

<!-- snippet: no_default_nocompile.cpp -->
```cpp
Account account;    // whose account? how much money?
```

<!-- errors: no_default_nocompile -->
```text
no_default_nocompile.cpp: In function ‘int main()’:
no_default_nocompile.cpp:18:13: error: no matching function for call to ‘Account::Account()’
   18 |     Account account;    // whose account? how much money?
      |             ^~~~~~~
no_default_nocompile.cpp:6:5: note: candidate: ‘Account::Account(const std::string&, int)’
    6 |     Account(const std::string& owner, int amount) : owner_(owner), balance_(amount) {}
      |     ^~~~~~~
no_default_nocompile.cpp:6:5: note:   candidate expects 2 arguments, 0 provided
no_default_nocompile.cpp:4:7: note: candidate: ‘constexpr Account::Account(const Account&)’
    4 | class Account {
      |       ^~~~~~~
no_default_nocompile.cpp:4:7: note:   candidate expects 1 argument, 0 provided
no_default_nocompile.cpp:4:7: note: candidate: ‘constexpr Account::Account(Account&&)’
no_default_nocompile.cpp:4:7: note:   candidate expects 1 argument, 0 provided
```

The `error` line says it: there is no `Account::Account()`. Here that is right, because every
account needs an owner. If an object without arguments makes sense for your class, add
`Account() = default;`. The members then get their default values.

## Watch out

- Members are initialised in the order they are **declared in the class**, not in the order of
  the list. Write both in the same order; `g++` warns (`-Wreorder`) when they differ.
- `Account a();` creates no object: it declares a function named `a`. To call the default
  constructor, write `Account a;` or `Account a{};`.
- A constructor with one parameter also works as a silent conversion: with
  `Account(int amount)`, the line `Account a = 500;` builds. Write
  `explicit Account(int amount)` to forbid that.

## Try it

1. Build and run [`wrong_order_bug.cpp`](wrong_order_bug.cpp). Why is the bonus wrong? Fix it.
2. Add `Account() = default;` to `account.cpp`, then `Account empty;` and `empty.print();` to
   `main`. Predict the new line of output.

<details>
<summary>Answers</summary>

1. `bonus_` is declared first, so it is initialised first, from a `balance_` that has no value
   yet. That is undefined behaviour; you usually see a random bonus. `g++` warns about it twice
   (`-Wreorder` and `-Wuninitialized`). Declare `balance_` first.
2. `: 0 so'm`. No list names the members, so `balance_` gets its default value, and `owner_`,
   a `std::string`, starts empty.
</details>

**Next:** [Destructors and lifetime](../03-destructors-and-lifetime/README.md)
