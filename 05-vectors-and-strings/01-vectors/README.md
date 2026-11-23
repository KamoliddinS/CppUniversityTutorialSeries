# Vectors

> **Goal:** keep many values of one type in one variable that can grow.

## One name for many values

A hundred scores need one variable, not a hundred. A **vector** is one variable that holds
a whole list of values, and the list can grow.

```text
index      0    1    2
         ┌────┬────┬────┐
scores   │ 72 │ 85 │ 90 │     size() is 3
         └────┴────┴────┘
```

**`scores.cpp`**
<!-- file: scores.cpp -->
```cpp
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> scores = {72, 85, 90};     // a list of three ints

    std::cout << "Size: " << scores.size() << '\n';
    std::cout << "First: " << scores[0] << ", last: " << scores.back() << '\n';

    scores.push_back(64);                       // add at the end
    scores[0] = 75;                             // change the first element
    std::cout << "Size: " << scores.size() << ", first: " << scores[0]
              << ", last: " << scores.back() << '\n';

    scores.pop_back();                          // remove the last element
    std::cout << "Size: " << scores.size() << ", last: " << scores.back() << '\n';

    std::vector<std::string> absent;            // an empty list of strings
    if (absent.empty()) {
        std::cout << "Nobody is absent.\n";
    }
}
```

<!-- output: scores -->
```text
Size: 3
First: 72, last: 90
Size: 4, first: 75, last: 64
Size: 3, last: 90
Nobody is absent.
```

- `<int>` names the type of the **elements**: the values in the list.
- The number in `[ ]` is the **index**. It starts at 0, so the last index is `size() - 1`.
- A function after a dot, such as `scores.size()`, works on the vector before the dot.

## An index that does not exist

Three elements have the indexes 0, 1 and 2. What is `scores[3]`?

**`past_the_end_bug.cpp`**
<!-- file: past_the_end_bug.cpp -->
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores = {72, 85, 90};
    std::cout << "Last score: " << scores[3] << '\n';   // the last index is 2
    std::cout << "Done.\n";
}
```

It builds. One run on Linux printed:

```text
Last score: 0
Done.
```

There is no `scores[3]`, and `[]` does not check the index. Reading past the end is
[undefined behaviour](../../01-first-programs/05-run-errors/README.md): this run got a 0
that was never in the list. Build with the
[sanitizers](../../01-first-programs/06-find-bugs-with-tools/README.md) and the mistake is
reported. The report is long. These lines of it matter:

```text
==2812570==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x50200000001c ...
READ of size 4 at 0x50200000001c thread T0
    #0 0x5f983f6db842 in main .../01-vectors/past_the_end_bug.cpp:6
```

`heap-buffer-overflow` means: the program read outside the vector's memory. `:6` is the line.

`at()` is the form that checks. [`at_bug.cpp`](at_bug.cpp) is the same program with
`scores.at(3)`. It always stops there. With g++ on Linux:

```text
terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 3) >= this->size() (which is 3)
Aborted (core dumped)
```

Read it as: index 3 is not less than the size, which is 3.
[Chapter 13](../../13-exceptions/README.md) explains what `std::out_of_range` is.

## Watch out

- `back()` and `pop_back()` on an empty vector are undefined behaviour too. Ask `empty()` first.
- When an index comes from the user, compare it with `size()` first, or use `at()`.

## Try it

1. Predict `v.size()` and `v.back()` after these lines. Then check with a program.

   ```cpp
   std::vector<int> v = {5, 10};
   v.push_back(15);
   v.pop_back();
   v.pop_back();
   v.push_back(20);
   ```

2. Change `at_bug.cpp` so that it prints the last score, whatever the size of the list is.

<details>
<summary>Answers</summary>

1. The size is 2 and the last element is 20. The list goes
   `5 10` → `5 10 15` → `5 10` → `5` → `5 20`.
2. `scores.at(scores.size() - 1)`, or shorter: `scores.back()`.
</details>

**Next:** [Loop over a vector](../02-loop-over-a-vector/README.md)
