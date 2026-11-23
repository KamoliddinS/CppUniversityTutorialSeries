# Comparison operators

> **Goal:** compare objects with `==` and `<`, and let the compiler write the operators when it can.

## A class has no `==` until you ask

This `Money` class has no comparison operators yet:

<!-- snippet: no_equal_nocompile.cpp -->
```cpp
Money bread(4200, 50);
Money coins(0, 420050);     // the same amount, given in tiyin

if (bread == coins) {
    std::cout << "The same amount.\n";
}
```

<!-- errors: no_equal_nocompile -->
```text
no_equal_nocompile.cpp: In function ‘int main()’:
no_equal_nocompile.cpp:15:15: error: no match for ‘operator==’ (operand types are ‘Money’ and ‘Money’)
   15 |     if (bread == coins) {
      |         ~~~~~ ^~ ~~~~~
      |         |        |
      |         Money    Money
```

The compiler does not guess what "equal" means for your class.

## `= default`: the compiler writes it

Declare the operator and write `= default` in place of a body. The compiler then writes
the function. Such a function is called **defaulted**.

**`compare.cpp`**
<!-- file: compare.cpp -->
```cpp
#include <compare>
#include <iostream>

class Money {
public:
    Money(long long soms, long long tiyin) : amount_(soms * 100 + tiyin) {}

    bool operator==(const Money&) const = default;
    auto operator<=>(const Money&) const = default;

private:
    long long amount_ = 0;      // in tiyin: 1 so'm = 100 tiyin
};

int main() {
    Money bread(4200, 50);
    Money milk(11800, 75);
    Money coins(0, 420050);     // the same amount as bread, given in tiyin

    if (bread == coins) {
        std::cout << "bread == coins\n";
    }
    if (bread != milk) {
        std::cout << "bread != milk\n";
    }
    if (bread < milk) {
        std::cout << "bread < milk\n";
    }
    if (milk >= coins) {
        std::cout << "milk >= coins\n";
    }
}
```

<!-- output: compare -->
```text
bread == coins
bread != milk
bread < milk
milk >= coins
```

| Line in the class | You get | How it compares |
|-------------------|---------|-----------------|
| `operator==` with `= default` | `==` and `!=` | member by member |
| `operator<=>` with `= default` | `<`, `<=`, `>`, `>=` | member by member, in the order the members are declared |

- `<=>` is the **three-way comparison**: one call tells whether the left operand is less
  than, equal to or greater than the right one. It needs `#include <compare>`. With `auto`,
  the compiler fills in the return type.
- The parameters have no names: without a body, nothing uses them.
- `bread == coins` is true, because both objects store 420050 tiyin.
- A defaulted `<=>` brings a defaulted `==` with it, so the `operator==` line may be left
  out. A hand-written `<=>` brings no `==` (Try it 2).
- With these two lines, `std::ranges::sort` and `std::ranges::max` work on a vector of `Money`
  ([Sort and search](../../05-vectors-and-strings/08-sort-and-search/README.md)).

## When the default order is wrong

A date is written as day, month, year. A defaulted `<=>` would compare the days first, so
here `<` is written by hand.

**`by_hand.cpp`**
<!-- file: by_hand.cpp -->
```cpp
#include <iostream>

struct Date {
    int day = 1;
    int month = 1;
    int year = 2000;

    bool operator==(const Date& other) const {      // what = default would write
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator<(const Date& other) const {       // year first, day last
        if (year != other.year) {
            return year < other.year;
        }
        if (month != other.month) {
            return month < other.month;
        }
        return day < other.day;
    }
};

int main() {
    Date exam{25, 5, 2026};
    Date holiday{1, 9, 2026};

    if (exam == holiday) {
        std::cout << "Both are on the same day.\n";
    } else if (exam < holiday) {
        std::cout << "The exam comes first.\n";
    } else {
        std::cout << "The holiday comes first.\n";
    }
}
```

<!-- output: by_hand -->
```text
The exam comes first.
```

- A hand-written `<` gives only `<`. `holiday > exam` does not build, and
  `std::ranges::sort` does not accept a vector of `Date`.

## Watch out

- A defaulted `==` compares a `double` member with `==`, and that is
  [not reliable](../../03-control-flow/01-comparisons-and-logic/README.md). `Money` counts
  whole tiyin, so its comparisons are exact.
- Comparison operators only read. Make them `const`, or const objects cannot be compared.

## Try it

1. In `by_hand.cpp`, replace the whole `operator<` by
   `auto operator<=>(const Date&) const = default;` and add `#include <compare>`.
   Predict the output.
2. Undo that, but keep the `#include`. Change `bool operator<` to `auto operator<=>`, and
   `<` to `<=>` in its three `return` lines. In `main`, write `holiday > exam` instead of
   `exam < holiday`. Does it build? Then delete `operator==`. Does it still build?

<details>
<summary>Answers</summary>

1. `The holiday comes first.` The default compares `day` first, and 1 is less than 25.
2. Yes. From any `<=>`, also a hand-written one, the compiler makes `<`, `<=`, `>` and `>=`.
   Without `operator==` it does not build: `no match for 'operator=='` in `exam == holiday`.
   Only a defaulted `<=>` brings an `==` with it.
</details>

**Next:** [Stream operators](../04-stream-operators/README.md)
