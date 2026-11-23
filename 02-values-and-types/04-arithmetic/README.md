# Arithmetic

> **Goal:** calculate with `+ - * / %` and predict what dividing whole numbers gives.

## Dividing whole numbers

`+`, `-` and `*` work as in mathematics. `/` and `%` need care.

**`divide.cpp`**
<!-- file: divide.cpp -->
```cpp
#include <iostream>

int main() {
    int minutes = 135;
    std::cout << minutes / 60 << " h " << minutes % 60 << " min\n";

    std::cout << 7 / 2 << '\n';         // the fraction is cut off
    std::cout << -7 / 2 << '\n';        // cut toward zero, not down to -4
    std::cout << -7 % 2 << '\n';        // the remainder keeps the sign of -7
    std::cout << 7.0 / 2.0 << '\n';     // two doubles keep the fraction
}
```

<!-- output: divide -->
```text
2 h 15 min
3
-3
-1
3.5
```

- `int / int` gives an `int`: the fraction is cut off, never rounded. This is **integer division**.
- The cut goes toward zero: `-7 / 2` is `-3`, not `-4`.
- `%` gives the remainder, the part left over after the division: 135 minutes are 2 full
  hours and 15 minutes. `%` works on whole numbers only.
- Dividing a whole number by zero, with `/` or `%`, is undefined behaviour
  (see [Run errors](../../01-first-programs/05-run-errors/README.md)).

## Which numbers belong together

**`order.cpp`**
<!-- file: order.cpp -->
```cpp
#include <iostream>

int main() {
    std::cout << 2 + 3 * 4 << '\n';         // * before +
    std::cout << (2 + 3) * 4 << '\n';       // brackets first
    std::cout << 8 / 4 * 2 << '\n';         // left to right: (8 / 4) * 2
}
```

<!-- output: order -->
```text
14
20
4
```

C++ groups the numbers the way mathematics does:

1. Brackets `( )` group first.
2. Then `*`, `/` and `%` take the numbers next to them. They have the same rank, so they
   are grouped from left to right: `8 / 4 * 2` means `(8 / 4) * 2`.
3. Then `+` and `-`, also from left to right.

## There is no power operator

**`power.cpp`**
<!-- file: power.cpp -->
```cpp
#include <cmath>
#include <iostream>

int main() {
    int base = 2;
    std::cout << (base ^ 3) << '\n';            // not "2 to the power of 3"
    std::cout << std::pow(base, 3) << '\n';     // this is
}
```

<!-- output: power -->
```text
1
8
```

`^` means something else in C++ (it is one of the
[bit operators](../../appendix/number-systems-and-bits/README.md)), so `2 ^ 3` is `1`.
For powers, use `std::pow` from `<cmath>`. Its result is a `double`.

## Change a variable

**`update.cpp`**
<!-- file: update.cpp -->
```cpp
#include <iostream>

int main() {
    int score = 10;
    score += 5;             // score = score + 5
    score *= 2;             // score = score * 2
    score++;                // score = score + 1
    std::cout << score << '\n';

    int a = 5;
    int b = a++;            // b gets the old value, then a grows
    int c = ++a;            // a grows first, then c gets the new value
    std::cout << a << ' ' << b << ' ' << c << '\n';
}
```

<!-- output: update -->
```text
31
7 5 7
```

| Short form | Means |
|------------|-------|
| `x += 5;` | `x = x + 5;` (the same for `-=`, `*=`, `/=`, `%=`) |
| `x++;` or `++x;` | `x = x + 1;` |
| `x--;` or `--x;` | `x = x - 1;` |

`x++` and `++x` differ only when you use the value in the same statement: `a++` gives the
old value, `++a` gives the new one.

## Watch out

- `1 / 2 * 100` is `0`: it means `(1 / 2) * 100`, and `1 / 2` is already `0`. Multiply first:
  `100 * 1 / 2` is `50`.
- When you are not sure about the order, add brackets.
- Write `x++;` as a statement of its own. Inside a longer calculation it is easy to misread.

## Try it

1. Predict each value: `19 / 5`, `19 % 5`, `2 + 19 % 5 * 3`, `3 / 4 * 100`, `100 * 3 / 4`.
2. 100 students travel in minibuses with 14 seats. Write a program that prints how many
   minibuses are full and how many students are left over.

<details>
<summary>Answers</summary>

1. `3`, `4`, `14`, `0`, `75`.
2. `100 / 14` gives `7` full minibuses. `100 % 14` gives `2` students left over.
</details>

**Next:** [Conversions](../05-conversions/README.md)
