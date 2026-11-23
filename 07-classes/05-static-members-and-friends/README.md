# Static members and friends

> **Goal:** share one value between all objects of a class, and give one chosen function access to the private members.

## One variable for the whole class

Every account has its own owner. The number of accounts opened so far belongs to no single
account: it belongs to the class. Such a member is marked `static`.

**`count_accounts.cpp`**
<!-- file: count_accounts.cpp -->
```cpp
#include <iostream>
#include <string>

class Account {
public:
    explicit Account(const std::string& owner) : owner_(owner) {
        ++count_;
        number_ = count_;
    }

    void print() const {
        std::cout << "Account " << number_ << " of " << count_ << ": " << owner_ << '\n';
    }

    static int count() { return count_; }   // needs no object

private:
    inline static int count_ = 0;   // one for the whole class
    std::string owner_;             // one for each object
    int number_ = 0;                // one for each object
};

int main() {
    std::cout << "Accounts: " << Account::count() << '\n';
    Account first("Malika");
    Account second("Jasur");
    first.print();
    second.print();
    std::cout << "Accounts: " << Account::count() << '\n';
}
```

<!-- output: count_accounts -->
```text
Accounts: 0
Account 1 of 2: Malika
Account 2 of 2: Jasur
Accounts: 2
```

- `count_` is a **static member**: it exists once for the whole class, even before the first
  object is created. Creating `second` changed what `first` prints.
- `inline static int count_ = 0;` creates it and gives it its first value in one line. Older
  code needs two: `static int count_;` in the class and `int Account::count_ = 0;` after it.
- `count()` is a static member function. It has no object and no `this`, so it cannot use
  `owner_` or `number_`. Call it with the class name: `Account::count()`.

## Friends

A class can declare a function as its `friend`. A **friend** is not a member, but it may use
the private members.

**`friend_transfer.cpp`**
<!-- file: friend_transfer.cpp -->
```cpp
#include <iostream>

class Account {
public:
    explicit Account(int amount) {
        if (amount > 0) {
            balance_ = amount;
        }
    }

    int balance() const { return balance_; }

    friend void transfer(Account& from, Account& to, int amount);

private:
    int balance_ = 0;
};

void transfer(Account& from, Account& to, int amount) {
    if (amount > 0 && amount <= from.balance_) {
        from.balance_ -= amount;    // allowed only because transfer is a friend
        to.balance_ += amount;
    }
}

int main() {
    Account malika(50000);
    Account jasur(10000);
    transfer(malika, jasur, 20000);
    std::cout << "Malika: " << malika.balance() << " so'm\n";
    std::cout << "Jasur: " << jasur.balance() << " so'm\n";
}
```

<!-- output: friend_transfer -->
```text
Malika: 30000 so'm
Jasur: 30000 so'm
```

`friend class Bank;` would give every member function of a class `Bank` the same right.

Use `friend` rarely. Each friend is one more place that can break the invariant, and public
member functions can usually do the job.
[Stream operators](../../08-operator-overloading/04-stream-operators/README.md) shows the
common use: printing an object with `<<`.

## Watch out

- Without `inline`, the line with `= 0` does not build:
  `ISO C++ forbids in-class initialization of non-const static member`.
- The class chooses its friends. A function cannot declare itself a friend of a class.

## Try it

1. In `count_accounts.cpp`, add the line `{ Account third("Laziz"); }` before the last line of
   `main`. Predict the last line of output.
2. Delete the `friend` line in `friend_transfer.cpp` and build. What does the first error say?

<details>
<summary>Answers</summary>

1. `Accounts: 3`. The object `third` is gone, but nothing makes `count_` smaller: it counts
   the accounts that were opened.
2. `'int Account::balance_' is private within this context`. Without the `friend` line,
   `transfer` is an ordinary function outside the class.
</details>

**Next:** [Headers and source files](../06-headers-and-source-files/README.md)
