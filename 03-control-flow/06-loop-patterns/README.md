# Loop patterns

> **Goal:** write the four loops that most programs are made of: sum, count, largest, search.

## Four patterns

| Pattern | Before the loop | In every round |
|---------|-----------------|----------------|
| sum | `sum = 0` | add the value to `sum` |
| count | `count = 0` | add 1 to `count` |
| largest, smallest | `largest` = the first value | if the value is larger, keep it in `largest` |
| search | `found = false` | if the value fits, set `found = true` |

## Sum, count and search

**`marks.cpp`**
<!-- file: marks.cpp -->
```cpp
#include <iostream>

int main() {
    double sum = 0.0;                   // double: sum / count keeps the decimals
    int count = 0;
    bool anyFailed = false;

    while (true) {
        std::cout << "Mark (0 to finish): ";
        int mark = 0;
        std::cin >> mark;
        if (mark == 0) {
            break;
        }
        sum += mark;                    // sum: add every value
        ++count;                        // count: add 1 for every value
        if (mark < 60) {
            anyFailed = true;           // search: remember that one was found
        }
    }

    if (count != 0) {
        std::cout << count << " marks, average " << sum / count << '\n';
    }
    if (anyFailed) {
        std::cout << "Somebody did not pass.\n";
    }
}
```

<!-- session: marks -->
```text
Mark (0 to finish): 80
Mark (0 to finish): 55
Mark (0 to finish): 90
Mark (0 to finish): 0
3 marks, average 75
Somebody did not pass.
```

- `0` is a **sentinel**: a special value that marks the end of the data. It must be a
  value that real data cannot have.
- `anyFailed` is a **flag**: a `bool` that remembers that something happened.
- No marks, no average: the test `count != 0` protects the division.

A **trace table** follows the variables round by round. Write one when a loop gives a
wrong result.

| Typed | `sum` | `count` | `anyFailed` |
|-------|-------|---------|-------------|
| (start) | 0 | 0 | false |
| 80 | 80 | 1 | false |
| 55 | 135 | 2 | true |
| 90 | 225 | 3 | true |
| 0 | the loop ends | | |

## Largest: start from the first value

**`warmest.cpp`**
<!-- file: warmest.cpp -->
```cpp
#include <iostream>

int main() {
    constexpr int nights = 5;
    std::cout << "Temperatures of " << nights << " nights: ";

    int warmest = 0;
    std::cin >> warmest;                // the first value is the warmest so far

    for (int night = 2; night <= nights; ++night) {
        int temperature = 0;
        std::cin >> temperature;
        if (temperature > warmest) {
            warmest = temperature;      // a warmer one: remember it
        }
    }
    std::cout << "Warmest night: " << warmest << " degrees\n";
}
```

<!-- session: warmest -->
```text
Temperatures of 5 nights: -8 -3 -11 -5 -6
Warmest night: -3 degrees
```

The loop starts at night 2: the first night is already in `warmest`.

## Watch out

- Do not start the largest value from 0. With `int warmest = 0;` and a loop over all five
  nights, the answer here would be 0: a temperature that nobody typed. The smallest value
  has the same trap.
- Give `sum`, `count` and the flag their starting values **before** the loop. Inside the
  loop they would start again in every round.

## Try it

1. Predict with a trace table: what does `marks.cpp` print for 70, 40, 100, 0?
2. Change `warmest.cpp` so that it finds the coldest night.

<details>
<summary>Answers</summary>

1. `3 marks, average 70` and `Somebody did not pass.` The sum is 210, the count is 3, and
   the flag becomes true at 40.
2. Rename `warmest` to `coldest` and change `>` to `<`: `if (temperature < coldest)`.
</details>

**Next:** [Safe input](../07-safe-input/README.md)
