# Sort and search

> **Goal:** let the standard library sort, search, count and add up for you.

## The loops are already written

You have written the loops for a sum, a count and a search many times. The standard library
has them ready, as functions called **algorithms**.

**`library.cpp`**
<!-- file: library.cpp -->
```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> scores = {72, 90, 64, 85, 90};

    std::cout << "Largest: " << std::ranges::max(scores) << '\n';
    std::cout << "Smallest: " << std::ranges::min(scores) << '\n';
    std::cout << "Sum: " << std::accumulate(scores.begin(), scores.end(), 0) << '\n';
    std::cout << "Number of 90s: " << std::ranges::count(scores, 90) << '\n';

    if (std::ranges::find(scores, 85) != scores.end()) {    // read: "85 was found"
        std::cout << "Somebody got 85.\n";
    }

    std::ranges::sort(scores);                              // smallest first
    for (int score : scores) {
        std::cout << score << ' ';
    }
    std::cout << '\n';
}
```

<!-- output: library -->
```text
Largest: 90
Smallest: 64
Sum: 401
Number of 90s: 2
Somebody got 85.
64 72 85 90 90
```

| You want | Write | Header |
|----------|-------|--------|
| the smallest first | `std::ranges::sort(v)` | `<algorithm>` |
| is `x` in the list? | `std::ranges::find(v, x) != v.end()` | `<algorithm>` |
| how many times is `x` there? | `std::ranges::count(v, x)` | `<algorithm>` |
| the largest, the smallest | `std::ranges::max(v)`, `std::ranges::min(v)` | `<algorithm>` |
| the sum | `std::accumulate(v.begin(), v.end(), 0)` | `<numeric>` |

- `v.begin(), v.end()` means: from the start of `v` to its end.
- `find` returns the place where `x` is. When `x` is not in the list, it returns `v.end()`.
  So read `!= v.end()` as "found".
  [Iterators](../../15-standard-library/03-iterators/README.md) explains these places.
- Everything from `<algorithm>` in this table also works on a string and on a vector of
  strings.

## The sum has the type of its start

Three days of study: 1.5, 2.5 and 3.5 hours. The sum should be 7.5.

**`hours.cpp`**
<!-- file: hours.cpp -->
```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<double> hours = {1.5, 2.5, 3.5};      // study time on three days

    double wrong = std::accumulate(hours.begin(), hours.end(), 0);      // adds up as an int
    double right = std::accumulate(hours.begin(), hours.end(), 0.0);    // adds up as a double
    std::cout << wrong << ' ' << right << '\n';
}
```

<!-- output: hours -->
```text
6 7.5
```

The third argument of `std::accumulate` is the value the sum starts with, and the sum gets
its type. With `0` the sum is an `int`, and every step drops the part after the point. For
decimal numbers, start with `0.0`.

## Watch out

- `std::ranges::max` and `std::ranges::min` need at least one element. On an empty vector
  they are undefined behaviour. Test `empty()` first.
- `std::ranges::sort` changes the vector itself. The old order is gone.

## Try it

1. Predict the output of `puzzle.cpp`:

   **`puzzle.cpp`**
   <!-- file: puzzle.cpp -->
   ```cpp
   #include <algorithm>
   #include <iostream>
   #include <string>
   #include <vector>

   int main() {
       std::vector<std::string> names = {"Malika", "aziz", "Jasur", "Dilnoza"};
       std::ranges::sort(names);
       for (const std::string& name : names) {
           std::cout << name << ' ';
       }
       std::cout << '\n';
   }
   ```

2. Print the average of `scores` in `library.cpp` as a decimal number.

<details>
<summary>Answers</summary>

1. [Capital letters come before small letters](../04-strings-in-depth/README.md), so `aziz`
   is last:

   <!-- output: puzzle -->
   ```text
   Dilnoza Jasur Malika aziz
   ```

2. `std::accumulate(scores.begin(), scores.end(), 0.0) / scores.size()` gives 80.2.
   With `0` it gives 80: the sum 401 is a whole number, and so is the division.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)
