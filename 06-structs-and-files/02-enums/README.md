# Enums

> **Goal:** give names to a fixed set of choices and handle each one in a `switch`.

## Names instead of numbers

A course has three levels. An `int` can store the level, but the number is a
[magic number](../../02-values-and-types/06-constants/README.md), and nonsense is accepted:

```cpp
int level = 2;      // 2 means... middle? advanced?
level = 7;          // no such level, but it compiles
```

An **enum** is a type whose only values are the names that you list.

**`level.cpp`**
<!-- file: level.cpp -->
```cpp
#include <iostream>
#include <string>

enum class Level { beginner, middle, advanced };

std::string toText(Level level) {
    switch (level) {
    case Level::beginner:
        return "beginner";      // return leaves the function: no break needed
    case Level::middle:
        return "middle";
    case Level::advanced:
        return "advanced";
    }
    return "unknown";
}

int main() {
    Level level = Level::middle;

    if (level == Level::middle) {
        std::cout << "You are in the middle group.\n";
    }
    std::cout << "As text:     " << toText(level) << '\n';
    std::cout << "As a number: " << static_cast<int>(level) << '\n';
}
```

<!-- output: level -->
```text
You are in the middle group.
As text:     middle
As a number: 1
```

- `enum class Level { ... };` defines the type. Its values are written `Level::beginner`,
  `Level::middle` and `Level::advanced`.
- A `Level` holds nothing else: `level = 7;` does not compile.
- Use it like any other type: for a variable, a parameter or a struct member.
  Compare with `==` and `!=`.

An enum does not turn into a number or into text by itself:

| You write | You get |
|-----------|---------|
| `int n = level;` | compile error: `cannot convert 'Level' to 'int'` |
| `std::cout << level;` | compile error |
| `static_cast<int>(level)` | `1`: the names are numbered from 0, in the order of the list |
| `toText(level)` | `middle`: a function you write yourself, with a `switch` |

## The compiler checks your switch

**`missing_case_bug.cpp`**
<!-- file: missing_case_bug.cpp -->
```cpp
#include <iostream>

enum class Level { beginner, middle, advanced };

int main() {
    Level level = Level::advanced;

    switch (level) {
    case Level::beginner:
        std::cout << "Start with lesson 1.\n";
        break;
    case Level::middle:
        std::cout << "Start with lesson 10.\n";
        break;
    }
}
```

<!-- errors: missing_case_bug -->
```text
missing_case_bug.cpp: In function ‘int main()’:
missing_case_bug.cpp:8:12: warning: enumeration value ‘advanced’ not handled in switch [-Wswitch]
    8 |     switch (level) {
      |            ^
```

The program is built, but for `advanced` it prints nothing. The warning names the case you forgot.

## Watch out

- Do not put `default:` in a `switch` over an enum. It switches this warning off, also for
  names you add to the enum later.
- `toText` ends with `return "unknown";` because without a `return` after the `switch`, g++
  warns: `control reaches end of non-void function`. That line runs only when a `Level`
  holds a number without a name, such as `static_cast<Level>(7)`.
- Old code has `enum Level { ... };` without `class`. Its names are written without
  `Level::` and turn into numbers silently. Write `enum class`.

## Try it

1. Predict the output:

   ```cpp
   enum class Day { monday, tuesday, wednesday };
   Day day = Day::wednesday;
   std::cout << static_cast<int>(day) + 1 << '\n';
   ```

2. Add `expert` at the end of `Level` in `level.cpp` and build. What does g++ report, and
   for which line? Fix it.

<details>
<summary>Answers</summary>

1. `3`. `wednesday` is the third name, so its number is 2.
2. `warning: enumeration value 'expert' not handled in switch`, for the `switch` in `toText`.
   Add a `case Level::expert:` that returns `"expert"`.
</details>

**Next:** [Write and read files](../03-write-and-read-files/README.md)
