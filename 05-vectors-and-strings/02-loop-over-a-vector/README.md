# Loop over a vector

> **Goal:** visit every element of a vector, with an index or without one.

## With an index

One index picks a student's name from one vector and the score from another.

**`numbered.cpp`**
<!-- file: numbered.cpp -->
```cpp
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> names = {"Aziz", "Malika", "Jasur"};
    std::vector<int> scores = {85, 92, 70};

    for (std::size_t i = 0; i < names.size(); ++i) {
        std::cout << i + 1 << ". " << names[i] << ": " << scores[i] << '\n';
    }
}
```

<!-- output: numbered -->
```text
1. Aziz: 85
2. Malika: 92
3. Jasur: 70
```

- `i` runs from 0 to `size() - 1`. The condition is `i < names.size()`, never `<=`.
- **`std::size_t`** is the type that `size()` returns: a whole-number type that is never
  negative. It comes from `<cstddef>`.

## Without an index

Most loops do not need the index. The **range-based `for`** gives you the elements one by
one. Read `for (int score : scores)` as "for each score in scores".

**`bonus.cpp`**
<!-- file: bonus.cpp -->
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores = {72, 85, 90, 64};

    int sum = 0;
    int largest = scores[0];
    for (int score : scores) {          // score is a copy of the element
        sum += score;
        if (score > largest) {
            largest = score;
        }
    }
    std::cout << "Sum: " << sum << ", largest: " << largest << '\n';

    for (int& score : scores) {         // score is the element itself
        score += 5;
    }
    for (int score : scores) {
        std::cout << score << ' ';
    }
    std::cout << '\n';
}
```

<!-- output: bonus -->
```text
Sum: 311, largest: 90
77 90 95 69
```

| Loop | The loop variable is | Use it to |
|------|----------------------|-----------|
| `for (int x : v)` | a copy of the element | read numbers |
| `for (int& x : v)` | the element itself | change the elements |
| `for (const std::string& name : names)` | the element itself, read-only | read strings without copying them |

The `&` means the same as in a
[function parameter](../../04-functions/04-const-references/README.md). You may write `auto`
in place of the element type, and the compiler fills it in: `for (auto x : v)`.

Sum and largest are the [loop patterns](../../03-control-flow/06-loop-patterns/README.md)
you know. Only the loop header is new.

## Watch out

**`empty_trap.cpp`**
<!-- file: empty_trap.cpp -->
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores;                    // empty
    std::cout << scores.size() - 1 << '\n';     // not -1
}
```

<!-- output: empty_trap -->
```text
18446744073709551615
```

A size is never negative. On an empty vector, `size() - 1` is not -1: it jumps to the
largest value that a `std::size_t` can hold. A loop with `i <= scores.size() - 1` then
reads elements that do not exist: undefined behaviour. Write `i < scores.size()`.

## Try it

1. Predict the output of `puzzle.cpp`:

   **`puzzle.cpp`**
   <!-- file: puzzle.cpp -->
   ```cpp
   #include <iostream>
   #include <vector>

   int main() {
       std::vector<int> numbers = {1, 2, 3};
       for (int n : numbers) {
           n = n * 10;
       }
       for (int& n : numbers) {
           n = n + 1;
       }
       for (int n : numbers) {
           std::cout << n << ' ';
       }
       std::cout << '\n';
   }
   ```

2. In `numbered.cpp`, change `std::size_t` to `int` and build. What does the compiler say?
3. Add a search to the end of `bonus.cpp`: is any score below 70?

<details>
<summary>Answers</summary>

1. The first loop changes copies, so the vector is still `1 2 3`. The second loop adds 1 to
   the elements themselves:

   <!-- output: puzzle -->
   ```text
   2 3 4
   ```

2. `warning: comparison of integer expressions of different signedness`. An `int` can be
   negative and a size cannot. With `std::size_t` both sides have the same type.
3. After the bonus the scores are `77 90 95 69`, so `found` ends as `true`:

   ```cpp
   bool found = false;
   for (int score : scores) {
       if (score < 70) {
           found = true;
       }
   }
   ```
</details>

**Next:** [Vectors and functions](../03-vectors-and-functions/README.md)
