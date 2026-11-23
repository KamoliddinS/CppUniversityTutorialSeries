# From struct to class

> **Goal:** write a class that keeps its data private and changes it only through its own functions.

## The problem: a struct protects nothing

A bank balance must never be negative. This struct cannot promise that: its members are
public, so any line of code may change them.

**`open_struct.cpp`**
<!-- file: open_struct.cpp -->
```cpp
#include <iostream>
#include <string>

struct Account {
    std::string owner;
    int balance = 0;    // so'm; must never be negative
};

int main() {
    Account account{"Malika", 50000};
    account.balance -= 80000;   // nothing stops this line
    std::cout << account.owner << ": " << account.balance << " so'm\n";
}
```

<!-- output: open_struct -->
```text
Malika: -30000 so'm
```

## A class guards its data

**`account.cpp`**
<!-- file: account.cpp -->
```cpp
#include <iostream>

class Account {
public:
    void deposit(int amount) {
        if (amount > 0) {
            balance_ += amount;
        }
    }

    bool withdraw(int amount) {
        if (amount <= 0 || amount > balance_) {
            return false;       // refuse, so the balance stays valid
        }
        balance_ -= amount;
        return true;
    }

    int balance() { return balance_; }

private:
    int balance_ = 0;   // so'm; never negative
};

int main() {
    Account account;
    account.deposit(50000);
    if (!account.withdraw(80000)) {
        std::cout << "Not enough money.\n";
    }
    std::cout << "Balance: " << account.balance() << " so'm\n";
}
```

<!-- output: account -->
```text
Not enough money.
Balance: 50000 so'm
```

- `Account` is a **class**: a type that holds data together with the functions that work on
  it. `account` is an **object**: a variable whose type is a class.
- `deposit`, `withdraw` and `balance` are **member functions**: functions that belong to the
  class. They are `public`, so all code may call them.
- `balance_` is **private**: only the member functions of the class can use it.

Only `deposit` and `withdraw` change `balance_`, and both check first. So `balance_ >= 0` is
always true. A condition that is always true for a valid object is called an **invariant**.

## The compiler enforces it

A line in `main` tries to change the balance directly:

<!-- snippet: private_nocompile.cpp -->
```cpp
account.balance_ -= 80000;      // not allowed: balance_ is private
```

<!-- errors: private_nocompile -->
```text
private_nocompile.cpp: In function ‘int main()’:
private_nocompile.cpp:16:13: error: ‘int Account::balance_’ is private within this context
   16 |     account.balance_ -= 80000;      // not allowed: balance_ is private
      |             ^~~~~~~~
private_nocompile.cpp:10:9: note: declared private here
   10 |     int balance_ = 0;   // so'm; never negative
      |         ^~~~~~~~
```

The compiler sees `balance_`, but it does not let `main` use it. The mistake is caught
before the program ever runs.

## struct or class?

The only difference is the default access: `public` in a `struct`, `private` in a `class`.

```cpp
struct Point { int x = 0; };    // x is public
class Secret { int x = 0; };    // x is private
```

By habit, a `struct` holds plain data and a `class` protects an invariant.

## Watch out

- Do not write a getter and a setter (`getBalance`, `setBalance`) for every member.
  `setBalance(-500)` would break the invariant again. Offer what the object really does:
  `deposit`, `withdraw`.
- The `_` at the end of `balance_` marks private data in this course. C++ does not require it.

## Try it

1. Add this line before the last line of `main` in `account.cpp`. Predict the balance, then
   run it: `account.deposit(-20000); account.withdraw(50000); account.withdraw(1);`
2. Add a member function `canPay(int price)` that returns `true` when the balance is at
   least `price`.

<details>
<summary>Answers</summary>

1. `Balance: 0 so'm`. The negative deposit is ignored, the withdrawal of 50000 works, and the
   last one is refused because the account is empty.
2. Under `public:` write `bool canPay(int price) { return price <= balance_; }`
</details>

**Next:** [Constructors](../02-constructors/README.md)
