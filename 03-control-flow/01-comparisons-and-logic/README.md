# Comparisons and logic

> **Goal:** write a condition: a question that C++ answers with `true` or `false`.

## Compare and combine

`if` and loops (the next lessons) decide what to do by testing a **condition**: a `bool`
value, `true` or `false`. A comparison gives such a value.

| Write | True when |
|-------|-----------|
| `a == b`, `a != b` | the two values are equal; are different |
| `a < b`, `a <= b` | `a` is less than `b`; less than or equal |
| `a > b`, `a >= b` | `a` is greater than `b`; greater than or equal |
| `a && b` | **and**: both sides are true |
| `a \|\| b` | **or**: at least one side is true |
| `!a` | **not**: `a` is false |

**`conditions.cpp`**
<!-- file: conditions.cpp -->
```cpp
#include <iostream>

int main() {
    int age = 19;

    bool adult = age >= 18;                     // a comparison gives true or false
    bool teenager = age >= 13 && age <= 19;     // both sides must be true
    bool freeEntry = age < 7 || age >= 65;      // one true side is enough
    bool mustPay = !freeEntry;                  // the opposite

    std::cout << std::boolalpha;                // print true/false instead of 1/0
    std::cout << "adult:      " << adult << '\n';
    std::cout << "teenager:   " << teenager << '\n';
    std::cout << "free entry: " << freeEntry << '\n';
    std::cout << "must pay:   " << mustPay << '\n';
}
```

<!-- output: conditions -->
```text
adult:      true
teenager:   true
free entry: false
must pay:   true
```

Where you write no brackets, C++ adds them by fixed rules: first around `!`, then around
arithmetic, then comparisons, then `&&`, and last `||`. So `a || b && c` means
`a || (b && c)`, and `!x == 5` means `(!x) == 5`. The brackets only decide what belongs
together, not which part is calculated first. When in doubt, write them yourself (g++ calls
them parentheses). To print a condition, you need them: `std::cout << (x > 3);`.

## The right side can be skipped

**`guard.cpp`**
<!-- file: guard.cpp -->
```cpp
#include <iostream>

int main() {
    int total = 0;      // sum of all marks
    int count = 0;      // number of marks: there are none yet

    bool goodAverage = count != 0 && total / count >= 60;
    std::cout << std::boolalpha << "good average: " << goodAverage << '\n';
}
```

<!-- output: guard -->
```text
good average: false
```

`&&` and `||` always test the left side first. If that already decides the answer, the
right side does not run. This is **short-circuit evaluation**. Here `count != 0` is false,
so the division by zero never happens. Put the safe test on the left.

## Watch out

**`traps_bug.cpp`**
<!-- file: traps_bug.cpp -->
```cpp
#include <iostream>

int main() {
    int x = 50;
    bool inRange = 1 < x < 10;
    bool isFive = x = 5;
    std::cout << std::boolalpha << inRange << ' ' << isFive << '\n';
}
```

<!-- errors: traps_bug -->
```text
traps_bug.cpp: In function ‘int main()’:
traps_bug.cpp:5:26: warning: comparison of constant ‘10’ with boolean expression is always true [-Wbool-compare]
    5 |     bool inRange = 1 < x < 10;
      |                    ~~~~~~^~~~
traps_bug.cpp:5:22: warning: comparisons like ‘X<=Y<=Z’ do not have their mathematical meaning [-Wparentheses]
    5 |     bool inRange = 1 < x < 10;
      |                    ~~^~~
traps_bug.cpp:6:21: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
    6 |     bool isFive = x = 5;
      |                   ~~^~~
```

The program is built and prints `true true`. Both answers are wrong.

| You wrote | What C++ does | Write |
|-----------|---------------|-------|
| `1 < x < 10` | means `(1 < x) < 10`. The result of `1 < x` counts as 0 or 1, and that is always less than 10. | `1 < x && x < 10` |
| `x = 5` | stores 5 in `x`. Every number except 0 counts as `true`, so `if (x = 5)` is always true. | `x == 5` |

The third trap gives no warning: `==` between two `double` values.

**`doubles.cpp`**
<!-- file: doubles.cpp -->
```cpp
#include <cmath>
#include <iostream>

int main() {
    double sum = 0.1 + 0.2;

    bool equal = sum == 0.3;
    bool close = std::abs(sum - 0.3) < 0.000001;    // std::abs removes the minus sign
    std::cout << std::boolalpha << "equal: " << equal << ", close: " << close << '\n';
}
```

<!-- output: doubles -->
```text
equal: false, close: true
```

A `double` is
[not exact](../../02-values-and-types/02-whole-numbers-and-decimals/README.md), so
`0.1 + 0.2` is not exactly `0.3`. Test that the difference is tiny instead.

## Try it

1. `int x = 7;` Predict each result: `x > 3 && x < 5`, then `x < 3 || x == 7`, then `!(x == 7)`.
2. In `guard.cpp`, swap the two sides of `&&`. Build and run. What happens, and why?

<details>
<summary>Answers</summary>

1. `false`, `true`, `false`.
2. On Linux the program usually stops with `Floating point exception`. The division now runs
   first, and dividing a whole number by zero is undefined behaviour.
</details>

**Next:** [If and else](../02-if-and-else/README.md)
