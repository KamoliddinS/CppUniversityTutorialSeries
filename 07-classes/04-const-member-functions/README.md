# Const member functions

> **Goal:** mark every member function that only reads as `const`, so that it also works on const objects.

## The problem: a const object refuses the call

You pass objects to functions as `const Account&`
([Const references](../../04-functions/04-const-references/README.md)). With the classes of
the earlier lessons, that does not build:

<!-- snippet: not_const_nocompile.cpp -->
```cpp
int balance() { return balance_; }      // only reads, but does not say so

void printBalance(const Account& account) {
    std::cout << account.balance() << " so'm\n";
}
```

<!-- errors: not_const_nocompile -->
```text
not_const_nocompile.cpp: In function ‘void printBalance(const Account&)’:
not_const_nocompile.cpp:20:33: error: passing ‘const Account’ as ‘this’ argument discards qualifiers [-fpermissive]
   20 |     std::cout << account.balance() << " so'm\n";
      |                  ~~~~~~~~~~~~~~~^~
not_const_nocompile.cpp:13:9: note:   in call to ‘int Account::balance()’
   13 |     int balance() { return balance_; }      // only reads, but does not say so
      |         ^~~~~~~
```

`account` is const, so the compiler allows only functions that promise not to change it.
`balance()` gives no such promise. "Discards qualifiers" means: this call would throw the
`const` away.

## The promise: const after the parameter list

**`const_account.cpp`**
<!-- file: const_account.cpp -->
```cpp
#include <iostream>

class Account {
public:
    explicit Account(int amount) { deposit(amount); }

    void deposit(int amount) {                  // no const: it changes the object
        if (amount > 0) {
            balance_ += amount;
        }
    }

    int balance() const { return balance_; }    // const: it only reads

private:
    int balance_ = 0;
};

void printBalance(const Account& account) {
    std::cout << account.balance() << " so'm\n";
}

int main() {
    Account account(50000);
    account.deposit(25000);
    printBalance(account);

    const Account gift(10000);      // a const object: it can never change
    std::cout << gift.balance() << " so'm\n";
}
```

<!-- output: const_account -->
```text
75000 so'm
10000 so'm
```

- `int balance() const` is a **const member function**: it promises not to change the object,
  and the compiler checks the promise.
- A const object (`gift`) and a const reference (`account` in `printBalance`) can call only
  const member functions.
- Make every member function that only reads `const`.

## this

Inside a member function, `this` is the address of the object the function was called on;
that is the `this` in the error message above. `this->balance_` is that object's `balance_`,
and plain `balance_` is short for it. Addresses and `->` come in
[chapter 9](../../09-pointers-and-memory/README.md).

## Watch out

- `const` goes after the `)`. In `const int balance()` it belongs to the return type, and the
  function is still not const.
- A parameter with the same name as a member hides the member. `balance = balance;` then
  copies the parameter into itself, and `g++` does not warn. Write `this->balance = balance;`,
  or do as this course does: end member names with `_`, so that `this->` is rarely needed.

## Try it

1. Add `const` to `deposit` in `const_account.cpp` and build. What does the compiler say?
2. [`same_name_bug.cpp`](same_name_bug.cpp) prints `0 so'm`, not `50000 so'm`. Find out why
   and fix it.

<details>
<summary>Answers</summary>

1. `error: assignment of member 'Account::balance_' in read-only object`. A const member
   function may not change a member.
2. In the constructor, both names in `balance = balance;` mean the parameter, so the member
   keeps its default value 0. Write `this->balance = balance;`, or rename the member to
   `balance_`.
</details>

**Next:** [Static members and friends](../05-static-members-and-friends/README.md)
