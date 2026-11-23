# Code style

> **Goal:** write code that looks like the examples of this course.

The compiler does not care how code looks. People do: code is read far more often than it
is written. Every example in this course follows the rules on this page.

## Names

| What | Style | Write | Not |
|------|-------|-------|-----|
| variables and functions | `camelCase` | `totalPrice`, `readAge()` | `total_price`, `ReadAge()` |
| constants | the same, with `const` or `constexpr` | `maxSeats` | `MAX_SEATS` |
| types: structs, classes, enums | `PascalCase` | `Student` | `student` |
| private data of a class | an underscore at the end | `balance_` | `m_balance` |
| files | small letters, words joined with `_` | `count_up.cpp` | `CountUp.cpp` |

You write your own types from [chapter 6](../../06-structs-and-files/README.md) on, and
classes from [chapter 7](../../07-classes/README.md) on.

## Layout

Use four spaces for each level, never tabs. Put the opening brace at the end of the line.

```cpp
if (age >= 18) {                 // like this
    std::cout << "adult\n";
}

if (age >= 18)                   // not like this
{
  std::cout << "adult\n";
}
```

## Habits

| Rule | Write | Not | Why |
|------|-------|-----|-----|
| Always write `std::` | `std::cout` | `using namespace std;` | your names can never be mixed up with the thousands of names in the library |
| End a line with `'\n'` | `<< '\n'` | `<< std::endl` | `std::endl` also forces the text out at once, which costs time |
| Give every variable a starting value | `int total = 0;` | `int total;` | reading a variable before it has a value is undefined behaviour |
| Leave out `return 0;` in `main` | | `return 0;` | `main` returns 0 by itself |
| A comment says why | `// the shop rounds down` | `// divide by 100` | the code already says what it does |

Two more habits come later: loop over a list without an index when you can
([chapter 5](../../05-vectors-and-strings/README.md)), and let the library manage memory
instead of writing `new` and `delete` ([chapter 10](../../10-resource-management/README.md)).

## Why follow rules at all

Other projects use other rules, and `snake_case` is as good as `camelCase`: what matters is
that all code in one project looks the same, so that readers think about what the code
does and not about how it is written.

## Watch out

- In a project that already has a style, follow that style, not this page.
- Let the editor do the layout. In VS Code, right-click in the code and choose
  **Format Document**: it uses the file `.clang-format` in the top folder of the course.
  It does not fix names.

## Try it

`messy.cpp` builds without a warning and prints the right answer, but it breaks the rules
of this page in nine ways. Find them.

**`messy.cpp`**
<!-- file: messy.cpp -->
```cpp
// This program works, but it breaks the style rules of the course on purpose.
#include <iostream>
using namespace std;

int Free_Seats(int taken)
{
  constexpr int MAX_SEATS = 40;
  return MAX_SEATS - taken;
}

int main()
{
  int taken;
  taken = 28;
  // print the free seats
  cout << "Free seats: " << Free_Seats(taken) << endl;
  return 0;
}
```

<!-- output: messy -->
```text
Free seats: 12
```

<details>
<summary>Answer</summary>

`using namespace std;`, the names `MAX_SEATS` and `Free_Seats`, braces on their own lines,
two spaces instead of four, `taken` without a starting value, a comment that repeats the
code, `endl`, and `return 0;`. `tidy.cpp` is the same program in the style of the course:

**`tidy.cpp`**
<!-- file: tidy.cpp -->
```cpp
#include <iostream>

int freeSeats(int taken) {
    constexpr int maxSeats = 40;
    return maxSeats - taken;
}

int main() {
    int taken = 28;
    std::cout << "Free seats: " << freeSeats(taken) << '\n';
}
```

<!-- output: tidy -->
```text
Free seats: 12
```

</details>
