# For loops

> **Goal:** repeat a block a known number of times with `for`.

## Start, condition and step on one line

**`count_up.cpp`**
<!-- file: count_up.cpp -->
```cpp
#include <iostream>

int main() {
    for (int i = 1; i <= 3; ++i) {
        std::cout << "Round " << i << '\n';
    }
    std::cout << "Done.\n";
}
```

<!-- output: count_up -->
```text
Round 1
Round 2
Round 3
Done.
```

| Part | Here | When it runs |
|------|------|--------------|
| start | `int i = 1` | once, before the first round |
| condition | `i <= 3` | before every round; false ends the loop |
| step | `++i` (add 1 to `i`) | after every round |

Round by round:

| Round | `i` | `i <= 3` | Block prints | Step makes `i` |
|-------|-----|----------|--------------|----------------|
| 1 | 1 | true | `Round 1` | 2 |
| 2 | 2 | true | `Round 2` | 3 |
| 3 | 3 | true | `Round 3` | 4 |
| | 4 | false | the loop ends | |

Use `for` when you know the number of rounds before the loop starts. Use `while` when
you do not.

## One round too many, one too few

You want five rounds:

| Start and condition | `i` goes from | Rounds |
|---------------------|---------------|--------|
| `int i = 0; i < 5` | 0 to 4 | 5 |
| `int i = 1; i <= 5` | 1 to 5 | 5 |
| `int i = 1; i < 5` | 1 to 4 | 4: one too few |
| `int i = 0; i <= 5` | 0 to 5 | 6: one too many |

The last two are **off-by-one errors**: `<` and `<=` are mixed up. Check the first and the
last value of `i` by hand.

## Skip a round, leave the loop

**`skip_and_stop.cpp`**
<!-- file: skip_and_stop.cpp -->
```cpp
#include <iostream>

int main() {
    for (int day = 1; day <= 7; ++day) {
        if (day == 3) {
            continue;                   // skip the rest of this round
        }
        if (day == 6) {
            break;                      // leave the loop
        }
        std::cout << "Day " << day << '\n';
    }
    std::cout << "Done.\n";
}
```

<!-- output: skip_and_stop -->
```text
Day 1
Day 2
Day 4
Day 5
Done.
```

`continue` skips the rest of this round and goes on with the step. `break` ends the loop.

## A loop inside a loop

**`seats.cpp`**
<!-- file: seats.cpp -->
```cpp
#include <iostream>

int main() {
    for (int row = 1; row <= 2; ++row) {
        for (int seat = 1; seat <= 4; ++seat) {
            std::cout << row << '-' << seat << ' ';
        }
        std::cout << '\n';              // after every row
    }
}
```

<!-- output: seats -->
```text
1-1 1-2 1-3 1-4
2-1 2-2 2-3 2-4
```

For every row, the inner loop does all its rounds again. `break` and `continue` act only
on the loop they are in: in the inner loop they never end the outer one.

## Watch out

[`scope_nocompile.cpp`](scope_nocompile.cpp) uses `i` after the loop:

<!-- errors: scope_nocompile -->
```text
scope_nocompile.cpp: In function ‘int main()’:
scope_nocompile.cpp:7:32: error: ‘i’ was not declared in this scope
    7 |     std::cout << "Rounds: " << i << '\n';
      |                                ^
```

The loop variable exists only inside the loop
([Scope and lifetime](../../04-functions/07-scope-and-lifetime/README.md) explains why).
If you need a value afterwards, keep it in a variable that you declare before the loop.

## Try it

1. Predict: in `seats.cpp`, you add `if (seat == 3) { break; }` as the first line of the
   inner loop. What is printed?
2. Write a loop that prints `10 8 6 4 2 0`.

<details>
<summary>Answers</summary>

1. `1-1 1-2` and `2-1 2-2`. `break` ends the inner loop only, so the outer loop still does
   both rows.
2. `for (int i = 10; i >= 0; i -= 2) { std::cout << i << ' '; }`
</details>

**Next:** [Loop patterns](../06-loop-patterns/README.md)
