# Format output

> **Goal:** print a table with aligned columns and numbers with a fixed number of decimals.

## Plain `<<` is not enough

[`plain.cpp`](plain.cpp) prints three students with one space between name and mark:

<!-- snippet: plain.cpp -->
```cpp
std::cout << s.name << ' ' << s.mark << '\n';
```

<!-- output: plain -->
```text
Aziz 85.5
Dilnoza 92.375
Jasur 100
```

The columns do not line up, and every mark has a different number of decimals.

## Manipulators

A **manipulator** is something you send to `std::cout` with `<<` to change how the values
after it are printed.

**`table.cpp`**
<!-- file: table.cpp -->
```cpp
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    double mark = 0.0;
};

int main() {
    std::vector<Student> group = {{"Aziz", 85.5}, {"Dilnoza", 92.375}, {"Jasur", 100.0}};

    std::cout << std::fixed << std::setprecision(1);    // for every number from here on

    std::cout << std::left << std::setw(10) << "Name"
              << std::right << std::setw(6) << "Mark" << '\n';
    std::cout << std::setfill('-') << std::setw(16) << "" << std::setfill(' ') << '\n';
    for (const Student& s : group) {
        std::cout << std::left << std::setw(10) << s.name
                  << std::right << std::setw(6) << s.mark << '\n';
    }
}
```

<!-- output: table -->
```text
Name        Mark
----------------
Aziz        85.5
Dilnoza     92.4
Jasur      100.0
```

| Manipulator | What it sets | Stays on? |
|-------------|--------------|-----------|
| `std::setw(10)` | the next item takes at least 10 characters | **no: next item only** |
| `std::left`, `std::right` | the side of that space where the item goes (right, until you change it) | yes |
| `std::setfill('-')` | the character that fills the rest of the space | yes |
| `std::fixed` | a `double` gets a fixed number of decimals: `1234567.5`, not `1.23457e+06` | yes |
| `std::setprecision(1)` | that number of decimals (6, until you change it) | yes |

- So `std::setw` is repeated before every item, and `std::fixed` is written once.
- `std::setw`, `std::setfill` and `std::setprecision` need `<iomanip>`. The others come
  with `<iostream>`.
- The dashed line is an empty text, printed 16 wide and filled with `-`. Then the fill is
  set back to a space.
- Manipulators work on a file stream as on `std::cout`.

## Watch out

- `std::setw` never cuts. `std::setw(3) << "Samarkand"` prints all nine letters and pushes
  the rest of the line to the right. Choose the width for the longest value.
- Without `std::fixed`, `std::setprecision(2)` counts all digits: `3.14159` is printed
  as `3.1`. With `std::fixed` it is `3.14`.

## The newer way: `std::format`

C++20 has `std::format` (`#include <format>`, g++ 13 or newer). One text describes the
whole line, and nothing stays on:

<!-- snippet: with_format.cpp -->
```cpp
std::cout << std::format("{:<10}{:>6.1f}\n", s.name, s.mark);
```

`{:<10}` means left, 10 wide. `{:>6.1f}` means right, 6 wide, 1 decimal.
[`with_format.cpp`](with_format.cpp) prints the same table:

<!-- output: with_format -->
```text
Name        Mark
----------------
Aziz        85.5
Dilnoza     92.4
Jasur      100.0
```

## Try it

1. Predict the output of [`puzzle.cpp`](puzzle.cpp):

   <!-- snippet: puzzle.cpp -->
   ```cpp
   std::cout << std::setw(5) << 42 << 7 << '\n';
   std::cout << std::setfill('*') << std::setw(5) << 42 << std::setw(3) << 7 << '\n';
   ```

2. Add `{"Nodira Yusupova", 90.0}` to the group in `table.cpp`. What happens to her row?
   Repair the table.

<details>
<summary>Answers</summary>

1. `std::setw(5)` pads only the `42`. The `7` follows directly. The fill character `*`
   stays on for the second `std::setw`.

   <!-- output: puzzle -->
   ```text
      427
   ***42**7
   ```

2. Her mark stands five places too far to the right: the name has 15 characters, and
   `std::setw(10)` does not cut it. Use `std::setw(16)` for the names and for `"Name"`,
   and `std::setw(22)` for the dashed line.
</details>

**Next:** [Program arguments](../06-program-arguments/README.md)
