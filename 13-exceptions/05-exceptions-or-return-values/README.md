# Exceptions or return values

> **Goal:** choose between an exception and a return value when a function can fail.

## Not every failure is an exception

| The failure | Report it with | Examples |
|-------------|----------------|----------|
| is rare, and the caller cannot go on normally | an exception | a broken file, an impossible argument |
| is a normal outcome: "there is no result" | the return value | a search finds nothing, the user types letters instead of a number |

For the second row, return a `bool`, a pointer that may be `nullptr`, or a `std::optional`.

## Maybe a value: std::optional

A `std::optional<int>` holds an `int` or nothing. It comes from `<optional>`.

**`find_discount.cpp`**
<!-- file: find_discount.cpp -->
```cpp
#include <iostream>
#include <optional>
#include <string>
#include <vector>

struct Card {
    std::string owner;
    int discount = 0;       // percent
};

std::optional<int> findDiscount(const std::vector<Card>& cards, const std::string& owner) {
    for (const Card& card : cards) {
        if (card.owner == owner) {
            return card.discount;       // a value
        }
    }
    return std::nullopt;                // no value: a normal answer, not an error
}

int main() {
    const std::vector<Card> cards = {{"Malika", 10}, {"Jasur", 5}};

    std::optional<int> discount = findDiscount(cards, "Malika");
    if (discount) {
        std::cout << "Malika gets " << *discount << "% off\n";
    }

    discount = findDiscount(cards, "Aziz");
    if (!discount.has_value()) {
        std::cout << "Aziz has no card\n";
    }
    std::cout << "Aziz gets " << discount.value_or(0) << "% off\n";
}
```

<!-- output: find_discount -->
```text
Malika gets 10% off
Aziz has no card
Aziz gets 0% off
```

| Code | Meaning |
|------|---------|
| `return std::nullopt;` | return "no value" |
| `if (discount)` or `discount.has_value()` | is there a value? |
| `*discount` | the value; use it only when there is one |
| `discount.value_or(0)` | the value, or `0` when there is none |

A customer without a card is normal, so `findDiscount` does not throw. And unlike a special
value such as `-1`, an empty optional cannot be mistaken for a real discount.

## Watch out

- `*discount` on an empty optional is undefined behaviour. Test first, or use `value_or`.
- Do not steer the normal flow of a program with exceptions. This loop from
  [`loop_exit_bug.cpp`](loop_exit_bug.cpp) ends only because `at()` throws. That is slow and
  hard to read, and it hides real mistakes. Use a loop condition.

<!-- snippet: loop_exit_bug.cpp -->
```cpp
    try {
        for (std::size_t i = 0; true; ++i) {
            total += prices.at(i);      // the loop "ends" when at() throws
        }
    } catch (const std::out_of_range&) {
    }
```

## Try it

1. Exception or return value?
   - (a) `loadMenu("menu.txt")`, and the file does not exist.
   - (b) `findGrade(students, "Laziz")`, and there is no Laziz.
   - (c) `Date(2026, 13, 40)`: there is no month 13.
2. Predict the output:
   `std::optional<int> a = 7;` `std::optional<int> b;` `std::cout << a.value_or(1) + b.value_or(1);`

<details>
<summary>Answers</summary>

1. (a) Exception: the program cannot go on without the menu. (b) Return value, a
   `std::optional`: "not found" is normal. (c) Exception: the argument is impossible, and a
   constructor has no return value.
2. `8`. `a` holds 7. `b` is empty, so `value_or` gives 1.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)
