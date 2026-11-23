# Switch

> **Goal:** choose between several fixed values of one variable with `switch`.

## One value, several cases

An `else if` chain that compares the same variable with one fixed value after another is
easier to read as a `switch`.

**`drink.cpp`**
<!-- file: drink.cpp -->
```cpp
#include <iostream>

int main() {
    std::cout << "Tea or coffee (t/c)? ";
    char drink = ' ';
    std::cin >> drink;

    switch (drink) {
    case 't':
    case 'T':                           // two labels share one block
        std::cout << "Tea costs 5000 so'm.\n";
        break;
    case 'c':
    case 'C':
        std::cout << "Coffee costs 15000 so'm.\n";
        break;
    default:
        std::cout << "We do not sell that.\n";
        break;
    }
}
```

<!-- session: drink -->
```text
Tea or coffee (t/c)? c
Coffee costs 15000 so'm.
```

| Part | Meaning |
|------|---------|
| `switch (drink)` | look at this value once |
| `case 'c':` | a label: jump here when the value is `'c'` |
| `break;` | leave the `switch` |
| `default:` | jump here when no label fits |

Two labels can share one block, as `'t'` and `'T'` do.

## Without break, the program falls through

**`medal_bug.cpp`**
<!-- file: medal_bug.cpp -->
```cpp
#include <iostream>

int main() {
    int place = 2;

    switch (place) {
    case 1:
        std::cout << "gold\n";
        break;
    case 2:
        std::cout << "silver\n";
    case 3:
        std::cout << "bronze\n";
        break;
    default:
        std::cout << "no medal\n";
        break;
    }
}
```

<!-- errors: medal_bug -->
```text
medal_bug.cpp: In function ‘int main()’:
medal_bug.cpp:11:22: warning: this statement may fall through [-Wimplicit-fallthrough=]
   11 |         std::cout << "silver\n";
      |                      ^~~~~~~~~~
medal_bug.cpp:12:5: note: here
   12 |     case 3:
      |     ^~~~
```

It is built, and second place gets two medals:

```text
silver
bronze
```

A label only marks a place to jump to. It does not stop the code that arrives from above.
After `silver` there is no `break`, so the program runs on into `case 3`. This is called
**fall-through**.

## Watch out

- `switch` works only on whole numbers, characters and enums
  ([chapter 6](../../06-structs-and-files/02-enums/README.md)). A `std::string` or a
  `double` gives `error: switch quantity not an integer`.
- A label is one fixed value. A range such as `case score >= 90:` is not possible.
  For text, decimals and ranges, use an `else if` chain.
- A variable created inside a case, such as `int bonus = 100;`, needs braces `{ }` around
  the code of that case. Without them the program does not build: the next label gives
  `error: jump to case label`, because a jump to it would skip the starting value.

## Try it

1. Predict what `medal_bug.cpp` prints when `place` is 1, then 3, then 7.
2. Add the missing `break`. Check that second place now gets only `silver`.
3. Add water (`w`, 3000 so'm) to `drink.cpp`.

<details>
<summary>Answer to 1</summary>

`gold` (the `break` stops it), then `bronze`, then `no medal`.
</details>

**Next:** [While loops](../04-while-loops/README.md)
