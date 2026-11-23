# Index and increment

> **Goal:** reach an element of your class with `[]`, and write both forms of `++`.

## `[]` returns a reference to an element

A `Receipt` holds a list of prices. You want to write `receipt[1]`, as with a vector,
both to read a price and to change it.

**`index.cpp`**
<!-- file: index.cpp -->
```cpp
#include <cstddef>
#include <iostream>
#include <vector>

class Receipt {
public:
    void add(int price) { prices_.push_back(price); }
    std::size_t size() const { return prices_.size(); }

    int& operator[](std::size_t i) { return prices_.at(i); }                // read and write
    const int& operator[](std::size_t i) const { return prices_.at(i); }    // read only

private:
    std::vector<int> prices_;       // in so'm
};

int total(const Receipt& receipt) {
    int sum = 0;
    for (std::size_t i = 0; i < receipt.size(); ++i) {
        sum += receipt[i];          // receipt is const here: the second version is called
    }
    return sum;
}

int main() {
    Receipt receipt;
    receipt.add(4200);
    receipt.add(11800);

    receipt[1] = 9900;              // the first version: assign to the element itself
    std::cout << "Total: " << total(receipt) << " so'm\n";
}
```

<!-- output: index -->
```text
Total: 14100 so'm
```

- `operator[]` returns a reference, so `receipt[1] = 9900` assigns to the element itself.
  One operator does the work of a "get" and a "set" function.
- There are two versions. Inside `total`, `receipt` is const, so the compiler picks the
  `const` version. It returns a const reference: reading works, assigning does not.
- `[]` must be a member function.

## `++` in two forms

`++now` is the **prefix** form: the operator stands before its operand. `now++` is the
**postfix** form. They differ in the value they give back
([Arithmetic](../../02-values-and-types/04-arithmetic/README.md)), so they are two functions.

**`increment.cpp`**
<!-- file: increment.cpp -->
```cpp
#include <iostream>

class Clock {
public:
    Clock(int hour, int minute) : hour_(hour), minute_(minute) {}

    Clock& operator++() {           // prefix: ++clock
        ++minute_;
        if (minute_ == 60) {
            minute_ = 0;
            hour_ = (hour_ + 1) % 24;
        }
        return *this;               // the changed object itself
    }

    Clock operator++(int) {         // postfix: clock++
        Clock old = *this;          // remember the value before the change
        ++*this;                    // the prefix version does the work
        return old;                 // a copy of the old value
    }

    void print() const { std::cout << hour_ << " h " << minute_ << " min\n"; }

private:
    int hour_ = 0;
    int minute_ = 0;
};

int main() {
    Clock now(9, 58);

    Clock a = ++now;        // now changes first: a and now are both 9 h 59 min
    a.print();

    Clock b = now++;        // b gets the old value; now moves on to 10 h 0 min
    b.print();
    now.print();
}
```

<!-- output: increment -->
```text
9 h 59 min
9 h 59 min
10 h 0 min
```

| | Prefix: `++now` | Postfix: `now++` |
|---|---|---|
| Declared as | `Clock& operator++()` | `Clock operator++(int)` |
| Returns | the changed object, by reference | a copy of the old value |

- The `int` parameter of the postfix form is never used. It only tells the compiler which
  form this is.
- Postfix makes a copy, prefix does not. When you do not need the old value, write `++now`.
- `--` is written in the same way.

## Watch out

- Nothing checks the index for you. Here `at()` does it: `receipt[5]` stops the program
  ([Vectors](../../05-vectors-and-strings/01-vectors/README.md)). With `prices_[i]` in the
  operator, a wrong index is undefined behaviour.
- Postfix `++` returns `Clock`, never `Clock&`: `old` is a local variable.

## Try it

1. Predict the output when `main` in `increment.cpp` holds only these lines:

   ```cpp
   Clock c(23, 59);
   Clock d = c++;
   ++c;
   d.print();
   c.print();
   ```

2. Delete the `const` version of `operator[]` from `index.cpp` and build. Which line
   fails, and why?

<details>
<summary>Answers</summary>

1. `23 h 59 min` and `0 h 1 min`. `d` is a copy of the old value. `c` passes midnight, and
   then `++c` adds one more minute.
2. `sum += receipt[i];` in `total`, with
   `error: passing 'const Receipt' as 'this' argument discards qualifiers`. There `receipt`
   is const, and the version that is left does not promise to leave it unchanged.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)
