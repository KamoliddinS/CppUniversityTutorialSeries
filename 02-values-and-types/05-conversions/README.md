# Conversions

> **Goal:** predict what happens when `int` and `double` meet, and convert on purpose with `static_cast`.

## A `double` that lost its fraction

**`still_85.cpp`**
<!-- file: still_85.cpp -->
```cpp
#include <iostream>

int main() {
    int first = 80;
    int second = 91;
    double average = (first + second) / 2;      // a double, so 85.5?
    std::cout << "Average: " << average << '\n';
}
```

<!-- output: still_85 -->
```text
Average: 85
```

The average of 80 and 91 is 85.5. Making `average` a `double` does not help, because the
right side is calculated first:

1. `(first + second) / 2` is `171 / 2`. Both sides are `int`, so the result is `85`.
2. Only then is `85` turned into a `double` and stored. The fraction is already gone.

Step 2 is a **conversion**: a value of one type is made from a value of another type.

## When `int` meets `double`

When one side of an operator is a `double` and the other is an `int`, the `int` is converted
to `double` first. So `171 / 2.0` is `85.5`.

With two `int` variables, convert one side yourself:

<!-- snippet: average.cpp -->
```cpp
    double average = static_cast<double>(first + second) / 2;
```

<!-- output: average -->
```text
Average: 85.5
```

`static_cast<double>(...)` is a **cast**: a conversion that you ask for. It gives the value
as a `double`. The variables stay `int`.

## From `double` to `int`

**`cut_off.cpp`**
<!-- file: cut_off.cpp -->
```cpp
#include <iostream>

int main() {
    double average = 4.75;
    int grade = average;        // no error and no warning
    std::cout << "Grade: " << grade << '\n';
}
```

<!-- output: cut_off -->
```text
Grade: 4
```

The fraction is cut off, not rounded, and nobody tells you. A conversion that can lose
information is called **narrowing**. Write the starting value in braces `{ }`, and the
compiler does not accept it:

**`braces_nocompile.cpp`**
<!-- file: braces_nocompile.cpp -->
```cpp
#include <iostream>

int main() {
    int grade{4.75};            // braces instead of =
    std::cout << "Grade: " << grade << '\n';
}
```

<!-- errors: braces_nocompile -->
```text
braces_nocompile.cpp: In function ‘int main()’:
braces_nocompile.cpp:4:15: error: narrowing conversion of ‘4.75e+0’ from ‘double’ to ‘int’ [-Wnarrowing]
    4 |     int grade{4.75};            // braces instead of =
      |               ^~~~
```

`int grade{4};` is fine: it means the same as `int grade = 4;`. That is why braces are the
safer way to write a starting value. When you want the cut, ask for it:
`int grade{static_cast<int>(average)};`

## Watch out

- The same trap with [big numbers](../02-whole-numbers-and-decimals/README.md):
  `long long total = flat * 3;` still overflows when `flat` is an `int`. The multiplication
  is done with `int` values first.
- With a variable in the braces (`int grade{average};`) it is still narrowing, but g++ only
  warns. Apple clang refuses it. Read the warning.
- To round instead of cutting, use `std::round` from `<cmath>`: `std::round(4.75)` is `5`,
  still a `double`.

## Try it

Predict the output of [`mix.cpp`](mix.cpp). Then run it.

**`mix.cpp`**
<!-- file: mix.cpp -->
```cpp
#include <iostream>

int main() {
    int a = 7;
    int b = 2;
    double x = a / b;
    double y = a / 2.0;
    double z = static_cast<double>(a / b);
    int w = a / 2.0;
    std::cout << x << ' ' << y << ' ' << z << ' ' << w << '\n';
}
```

<details>
<summary>Answer</summary>

<!-- output: mix -->
```text
3 3.5 3 3
```

- `x`: `7 / 2` is integer division, so `3`.
- `y`: `2.0` is a `double`, so `a` is converted and the result is `3.5`.
- `z`: the cast comes after the integer division, so `3`.
- `w`: `3.5` is stored in an `int`, so the fraction is cut off.
</details>

**Next:** [Constants](../06-constants/README.md)
