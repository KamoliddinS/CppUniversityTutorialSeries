# Arrays

> **Goal:** use a list with a fixed size, and say why `std::vector` is still your first choice.

## A list that never grows

A week always has seven days. An **array** is a list with a fixed number of elements. The
standard library has `std::array` for it.

**`week.cpp`**
<!-- file: week.cpp -->
```cpp
#include <array>
#include <iostream>

int main() {
    std::array<int, 7> visitors = {120, 95, 130, 110, 160, 240, 210};   // Monday to Sunday

    int total = 0;
    for (int count : visitors) {
        total += count;
    }
    std::cout << visitors.size() << " days, " << total << " visitors\n";
    std::cout << "Sunday: " << visitors.at(6) << '\n';

    std::array<int, 7> copy = visitors;         // copies all seven elements
    copy[0] = 0;
    std::cout << "Monday: " << visitors[0] << ", in the copy: " << copy[0] << '\n';
}
```

<!-- output: week -->
```text
7 days, 1065 visitors
Sunday: 210
Monday: 120, in the copy: 0
```

- `std::array<int, 7>` means seven `int`s. The size is part of the type:
  `std::array<int, 5>` is a different type.
- It has `size()`, `at()` and `back()`, like a vector.
- There is no `push_back()`. The size cannot change.

## The built-in array

`int days[5]` is the array that C++ got from the older language C. You will meet it in old
code. It is five `int`s in a row and nothing more:

**`builtin_nocompile.cpp`**
<!-- file: builtin_nocompile.cpp -->
```cpp
#include <iostream>

int main() {
    int days[5] = {31, 28, 31, 30, 31};         // a built-in array of five ints
    std::cout << days[1] << '\n';
    std::cout << days.size() << '\n';
}
```

<!-- errors: builtin_nocompile -->
```text
builtin_nocompile.cpp: In function ‘int main()’:
builtin_nocompile.cpp:6:23: error: request for member ‘size’ in ‘days’, which is of non-class type ‘int [5]’
    6 |     std::cout << days.size() << '\n';
      |                       ^~~~
```

| | `std::vector<int>` | `std::array<int, 5>` | `int days[5]` |
|---|---|---|---|
| number of elements | can change | fixed | fixed |
| `size()`, `at()`, `back()` | yes | yes | no |
| copy with `=` | yes | yes | no |

A built-in array cannot be passed to a function like other values: the function gets
neither a copy nor the size.
[Pointers and arrays](../../09-pointers-and-memory/02-pointers-and-arrays/README.md) explains why.

Use `std::vector` by default. Use `std::array` when the size never changes.

## Watch out

- `std::array<int, 5> a;` gives the elements no starting value. Write
  `std::array<int, 5> a = {};` to make them all 0.
- `[]` does no checking in any of the three. An index past the end is undefined behaviour.
- The size of a `std::array` must be known when you build the program. If it is known only
  when the program runs, use a vector.

## Try it

1. Predict the output of `puzzle.cpp`:

   **`puzzle.cpp`**
   <!-- file: puzzle.cpp -->
   ```cpp
   #include <array>
   #include <iostream>

   int main() {
       std::array<int, 4> numbers = {5, 6};
       std::cout << numbers.size() << ' ' << numbers[1] << ' ' << numbers[3] << '\n';
   }
   ```

2. Which type do you choose for (a) the scores that the user types, (b) the number of days
   in each of the 12 months, (c) the names of the students who are present today?

<details>
<summary>Answers</summary>

1. The size comes from the type, not from the list. Elements that get no value from the
   list are 0:

   <!-- output: puzzle -->
   ```text
   4 6 0
   ```

2. (a) and (c): a `std::vector`, because nobody knows the number in advance.
   (b): a `std::array<int, 12>`.
</details>

**Next:** [Grids](../07-grids/README.md)
