# Arithmetic operators

> **Goal:** write `+=`, `+` and unary `-` the usual way, and make `3 * price` work as well as `price * 3`.

## `+=` changes the object, `+` makes a new one

With an `int`, `total += price` changes `total`, and `a + b` changes nothing. Your operators
must behave the same. Write `+=` first, then build `+` on it.

**`add.cpp`**
<!-- file: add.cpp -->
```cpp
#include <iostream>

class Money {
public:
    Money(long long soms, long long tiyin) : amount_(soms * 100 + tiyin) {}

    Money& operator+=(const Money& other) {
        amount_ += other.amount_;
        return *this;                       // the object itself, not a copy
    }

    Money operator-() const {               // unary minus: no parameter
        return Money(0, -amount_);          // 0 so'm and -amount_ tiyin
    }

    void print() const {
        std::cout << amount_ / 100 << " so'm " << amount_ % 100 << " tiyin\n";
    }

private:
    long long amount_ = 0;      // in tiyin: 1 so'm = 100 tiyin
};

Money operator+(const Money& a, const Money& b) {
    Money sum = a;      // a copy: a itself must not change
    sum += b;
    return sum;
}

int main() {
    Money bread(4200, 50);
    Money milk(11800, 75);

    Money total = bread + milk;     // a new Money: bread and milk stay as they are
    total += bread;                 // total itself changes
    total.print();

    Money paid(25000, 0);
    Money change = paid + -total;   // unary minus first, then +
    change.print();
}
```

<!-- output: add -->
```text
20201 so'm 75 tiyin
4798 so'm 25 tiyin
```

| Operator | Write it as | It changes | It returns |
|----------|-------------|------------|------------|
| `total += bread` | a member | `total` | `*this`, by reference |
| `bread + milk` | a non-member | nothing | a new `Money`, by value |
| `-total` | a `const` member without parameters | nothing | a new `Money`, by value |

- **`*this`** is the object the function was called on, here `total`. The return type
  `Money&` means that no copy is made. (`this` alone is the object's address: see
  [Const member functions](../../07-classes/04-const-member-functions/README.md).)
- `+` copies `a`, adds `b` to the copy and returns the copy. It needs no private data, and
  the adding is written only once.
- `-total` is a **unary operator**: it has one operand, the object itself. `a + b` has two
  operands: it is a binary operator.

## A member needs your object on the left

Three notebooks cost `notebook * 3`. With `*` as a member, only that order builds:

<!-- snippet: times_nocompile.cpp -->
```cpp
Money operator*(int count) const { return Money(0, amount_ * count); }

Money three = notebook * 3;     // notebook.operator*(3)
Money same = 3 * notebook;      // 3.operator*(notebook)? An int has no member functions.
```

<!-- errors: times_nocompile -->
```text
times_nocompile.cpp: In function ‘int main()’:
times_nocompile.cpp:21:20: error: no match for ‘operator*’ (operand types are ‘int’ and ‘Money’)
   21 |     Money same = 3 * notebook;      // 3.operator*(notebook)? An int has no member functions.
      |                  ~ ^ ~~~~~~~~
      |                  |   |
      |                  int Money
```

A non-member function takes both operands as parameters, so you can write one for each
order. [`times.cpp`](times.cpp) has `*=` as a member, like `+=`, and these two functions:

<!-- snippet: times.cpp -->
```cpp
Money operator*(const Money& m, int count) {
    Money result = m;
    result *= count;
    return result;
}

Money operator*(int count, const Money& m) {
    return m * count;               // the same result: let the first function work
}
```

<!-- output: times -->
```text
37501 so'm 50 tiyin
37501 so'm 50 tiyin
```

So the habit is: an operator that changes its object (`+=`, `*=`) is a member. An operator
that makes a new value from two operands (`+`, `*`) is a non-member.

## Watch out

- An `operator+` that changes `*this` and returns `Money&` is a `+=` with the wrong name:
  `total = bread + milk` would change `bread` too.
- `+` returns `Money`, never `Money&`. `sum` is a local variable: it is gone when the
  function ends ([Scope and lifetime](../../04-functions/07-scope-and-lifetime/README.md)),
  and using a reference to it is undefined behaviour.

## Try it

1. Add these lines at the end of `main` in `add.cpp`. Predict the two lines they print.

   ```cpp
   Money a(1000, 0);
   Money b = a + a;
   a += b;
   a += b;
   a.print();
   b.print();
   ```

2. Add `-=` and a binary `-` to `add.cpp`. Check that `paid - total` gives the same change
   as `paid + -total`.

<details>
<summary>Answers</summary>

1. `5000 so'm 0 tiyin` and `2000 so'm 0 tiyin`. `a + a` makes a new `Money` and leaves `a`
   at 1000 so'm. Each `+=` then adds 2000 so'm to `a` itself.
2. Copy `operator+=` and `operator+`, and write `-` where they have `+`. The change is
   `4798 so'm 25 tiyin` both times.
</details>

**Next:** [Comparison operators](../03-comparison-operators/README.md)
