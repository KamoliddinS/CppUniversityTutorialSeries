# Safe input

> **Goal:** keep a program working when the user types letters where a number is expected.

## One wrong key and the loop never stops

**`menu_bug.cpp`**
<!-- file: menu_bug.cpp -->
```cpp
#include <iostream>

int main() {
    while (true) {
        std::cout << "1 = greet, 2 = quit: ";
        int choice = 0;
        std::cin >> choice;
        if (choice == 2) {
            break;
        }
        if (choice == 1) {
            std::cout << "Salom!\n";
        } else {
            std::cout << "Unknown choice.\n";
        }
    }
}
```

The user types `x` instead of a number:

```text
1 = greet, 2 = quit: x
Unknown choice.
1 = greet, 2 = quit: Unknown choice.
1 = greet, 2 = quit: Unknown choice.
1 = greet, 2 = quit: Unknown choice.
...
```

The program never waits again. Only Ctrl+C stops it.

1. `std::cin >> choice` cannot make a number from `x`. The read fails, and `choice` is 0.
2. `std::cin` is now in a **failed state**, and the `x` is still waiting in the input.
3. In the failed state every later read fails at once, without waiting for the user.
   So `choice` can never become 2.

The same happens when the input ends: after Ctrl+D (Windows: Ctrl+Z, then Enter), or at
the end of an input file.

## Test the read, clear, ignore, ask again

**`menu.cpp`**
<!-- file: menu.cpp -->
```cpp
#include <iostream>
#include <limits>

int main() {
    while (true) {
        std::cout << "1 = greet, 2 = quit: ";
        int choice = 0;
        if (!(std::cin >> choice)) {            // the read failed
            if (std::cin.eof()) {
                break;                          // the input has ended: stop
            }
            std::cin.clear();                   // make std::cin work again
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   // drop the line
            std::cout << "Please type a number.\n";
            continue;                           // ask again
        }
        if (choice == 2) {
            break;
        }
        if (choice == 1) {
            std::cout << "Salom!\n";
        } else {
            std::cout << "Unknown choice.\n";
        }
    }
}
```

<!-- session: menu -->
```text
1 = greet, 2 = quit: x
Please type a number.
1 = greet, 2 = quit: 1
Salom!
1 = greet, 2 = quit: 2
```

| Code | What it does |
|------|--------------|
| `std::cin >> choice` | A read is also a condition: true when it worked. With `!` in front: "the read failed". |
| `std::cin.eof()` | True when the input has ended. Asking again is useless: stop. |
| `std::cin.clear()` | Switches the failed state off. |
| `std::cin.ignore(...)` | Throws away the rest of the line, with the wrong text in it. The long first part means "no limit" and needs `#include <limits>`. |

Copy this `if` block into every loop that reads a number.

Because a read is a condition, `while (std::cin >> number) { ... }` is a complete loop:
it reads numbers until a read fails.

## Watch out

- `clear()` must come first. In the failed state `ignore()` does nothing.
- Without the `eof()` test the loop runs forever again when the input ends.
- `12abc` is read as 12. The rest, `abc`, makes the next read fail.

## Try it

1. Predict: you delete the `std::cin.ignore(...)` line from `menu.cpp`, and the user
   types `x`. What happens?
2. Make `marks.cpp` from [Loop patterns](../06-loop-patterns/README.md) safe: a wrong line
   prints a message and does not end the list.

<details>
<summary>Answers</summary>

1. `Please type a number.` is printed forever. `clear()` makes `std::cin` work again, but
   the `x` is still in the input, so the next read fails on the same `x`.
2. Replace `std::cin >> mark;` by the `if` block of `menu.cpp`, with `mark` for `choice`,
   and add `#include <limits>`.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)
