# Operators are functions

> **Goal:** read `a + b` as a function call, and write that function for a class of your own.

## `+` calls a function named `operator+`

`+` joins two `std::string`s because the library has a function for that. For your own
class you write the function yourself. Its name is `operator+`, and writing it is called
**operator overloading**.

**`member.cpp`**
<!-- file: member.cpp -->
```cpp
#include <iostream>

class Money {
public:
    Money(long long soms, long long tiyin) : amount_(soms * 100 + tiyin) {}

    long long soms() const { return amount_ / 100; }
    long long tiyin() const { return amount_ % 100; }

    Money operator+(const Money& other) const {
        return Money(soms() + other.soms(), tiyin() + other.tiyin());
    }

    void print() const { std::cout << soms() << " so'm " << tiyin() << " tiyin\n"; }

private:
    long long amount_ = 0;      // in tiyin: 1 so'm = 100 tiyin
};

int main() {
    Money water(21900, 60);
    Money gas(38400, 70);

    Money bills = water + gas;              // the usual way
    Money same = water.operator+(gas);      // the same call, written out

    bills.print();
    same.print();
}
```

<!-- output: member -->
```text
60301 so'm 30 tiyin
60301 so'm 30 tiyin
```

- `water + gas` and `water.operator+(gas)` are the same call.
- `water` and `gas` are the **operands**: the values the operator works on. The left one
  is the object the function is called on. The right one arrives as `other`.
- Adding changes neither operand, so the function is `const`, takes a const reference and
  returns a new `Money`.
- `Money` stores one number, the amount in tiyin. So 60 + 70 tiyin become 1 so'm 30 tiyin.

## The same operator outside the class

An operator can also be a **non-member function**: an ordinary function outside the
class. [`nonmember.cpp`](nonmember.cpp) is the same program with two changes:

<!-- snippet: nonmember.cpp -->
```cpp
Money operator+(const Money& a, const Money& b) {
    return Money(a.soms() + b.soms(), a.tiyin() + b.tiyin());
}

Money same = operator+(water, gas);     // the same call, written out
```

<!-- output: nonmember -->
```text
60301 so'm 30 tiyin
60301 so'm 30 tiyin
```

Now both operands are parameters. The function is outside the class, so it can use only
the public members.

| You write | Member | Non-member |
|-----------|--------|------------|
| `a + b` | `a.operator+(b)` | `operator+(a, b)` |

Both forms work here. The next lesson shows how to choose.

## The rules

- Only operators that exist can be overloaded. You cannot invent `**` for powers.
- At least one operand must have a class or enum type. `2 + 3` keeps its meaning.
- The number of operands and the
  [rank](../../02-values-and-types/04-arithmetic/README.md) stay: `a + b * c` multiplies
  first, for `Money` too.
- A few operators cannot be overloaded, for example `::`, `.` and `sizeof`.

## Watch out

- An operator must do what the reader expects: `+` adds, and changes nothing. If no
  meaning is obvious (what would `water * gas` be?), write a function with a clear name.
- Each operator is a separate function. `+` gives you neither `+=` nor `-`.

## Try it

1. Write `water + gas + gas` as explicit calls of the member `operator+`.
2. Delete `operator+` from `member.cpp` and build. What is the compiler looking for?

<details>
<summary>Answers</summary>

1. `water.operator+(gas).operator+(gas)`. The first call returns a `Money`, and the second
   call is made on that result.
2. `error: no match for 'operator+' (operand types are 'Money' and 'Money')`: a function
   with exactly that name.
</details>

**Next:** [Arithmetic operators](../02-arithmetic-operators/README.md)
