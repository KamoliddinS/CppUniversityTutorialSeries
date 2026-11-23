# Whole numbers and decimals

> **Goal:** choose between `int` and `double`, and know the limits of each.

## Two types for numbers

| Type | Holds | Use it for | Example |
|------|-------|------------|---------|
| `int` | whole numbers | things you count | `int students = 28;` |
| `double` | numbers with a fraction | things you measure | `double height = 1.75;` |

Use these two unless you have a reason not to.

## An `int` has a largest value

On most systems an `int` holds whole numbers from -2 147 483 648 to 2 147 483 647: about
two billion each way. Prices in so'm get there quickly.

**`three_flats_bug.cpp`**
<!-- file: three_flats_bug.cpp -->
```cpp
#include <iostream>

int main() {
    int flat = 900000000;           // one flat costs 900 million so'm
    int total = flat * 3;           // 2 700 000 000 is too big for an int
    std::cout << "Three flats: " << total << " so'm\n";
}
```

The compiler says nothing. On one machine the program prints:

```text
Three flats: -1594967296 so'm
```

This is **overflow**: the result does not fit in the type. For an `int`, overflow is
undefined behaviour. Usually you see a wrong number, often a negative one, and no message.

When a whole number can pass two billion, use `long long`. It holds every number of up to 18 digits.

<!-- snippet: three_flats.cpp -->
```cpp
    long long flat = 900000000;     // one flat costs 900 million so'm
    long long total = flat * 3;
```

<!-- output: three_flats -->
```text
Three flats: 2700000000 so'm
```

## A `double` is not exact

**`not_exact.cpp`**
<!-- file: not_exact.cpp -->
```cpp
#include <iostream>

int main() {
    double sum = 0.1 + 0.2;
    std::cout << sum << '\n';           // looks like 0.3
    std::cout << sum - 0.3 << '\n';     // but it is not exactly 0.3
}
```

<!-- output: not_exact -->
```text
0.3
5.55112e-17
```

- A `double` keeps about 15 to 16 significant digits. Most fractions, even `0.1`, do not fit
  exactly, just as 1/3 does not fit in 0.333.
- `5.55112e-17` is 0.0000000000000000555112: the `e-17` moves the point 17 places to the
  left. Very small, but not zero.

## How much memory a type takes

`sizeof` gives the size of a type in bytes, the units of memory. It is an operator, like `+`,
not a function.

**`sizes.cpp`**
<!-- file: sizes.cpp -->
```cpp
#include <iostream>

int main() {
    std::cout << "int        " << sizeof(int) << " bytes\n";
    std::cout << "long       " << sizeof(long) << " bytes\n";
    std::cout << "long long  " << sizeof(long long) << " bytes\n";
    std::cout << "double     " << sizeof(double) << " bytes\n";
}
```

<!-- output: sizes -->
```text
int        4 bytes
long       8 bytes
long long  8 bytes
double     8 bytes
```

The C++ standard sets only a smallest size for each type, so sizes differ between systems:
`long` takes 8 bytes on Linux and macOS, but 4 on Windows.

## Watch out

- Write `1.75`, not `1,75`. C++ uses a point, also in what the user types.
- `std::cout` shows at most 6 significant digits of a `double`: `1234567.5` prints as
  `1.23457e+06`. The variable still holds the full value.
  [Format output](../../06-structs-and-files/05-format-output/README.md) shows how to change that.
- Count money in whole so'm, in an `int` or a `long long`. Keep `double` for measurements.

## Try it

Which type fits: `int`, `long long` or `double`?

1. the number of pages in a book
2. your body temperature, such as 36.6
3. the number of people on Earth, about 8 billion

<details>
<summary>Answers</summary>

1. `int`
2. `double`
3. `long long`: 8 billion is too big for an `int`.
</details>

**Next:** [Text, characters and booleans](../03-text-characters-and-booleans/README.md)
