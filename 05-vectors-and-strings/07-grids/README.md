# Grids

> **Goal:** store a table of values as a vector of vectors, and visit it with two loops.

## A table is a list of rows

A **grid** is a table of values with rows and columns: the seats of a hall, a game board, a
timetable. You store it as a vector of rows, where each row is a vector too.

**`seats.cpp`**
<!-- file: seats.cpp -->
```cpp
#include <cstddef>
#include <iostream>
#include <vector>

int main() {
    // 3 rows with 4 seats each; 0 means free
    std::vector<std::vector<int>> seats(3, std::vector<int>(4, 0));

    seats[0][1] = 1;                // row 0, seat 1 is taken
    seats[2][3] = 1;                // row 2, seat 3 is taken

    for (std::size_t r = 0; r < seats.size(); ++r) {
        std::cout << "Row " << r << ":";
        for (std::size_t c = 0; c < seats[r].size(); ++c) {
            std::cout << ' ' << seats[r][c];
        }
        std::cout << '\n';
    }
}
```

<!-- output: seats -->
```text
Row 0: 0 1 0 0
Row 1: 0 0 0 0
Row 2: 0 0 0 1
```

Read the long line from the inside. `std::vector<int>(4, 0)` is one row: four elements,
all 0. The `3` in front of it makes three copies of that row.

| Code | Meaning |
|------|---------|
| `seats.size()` | the number of rows |
| `seats[r]` | row `r`: a whole `std::vector<int>` |
| `seats[r].size()` | the number of elements in row `r` |
| `seats[r][c]` | element `c` of row `r`: the row comes first |

The outer loop takes the rows one by one. The inner loop walks through one row.

## Rows can have different lengths

Each row is its own vector, so it has its own size.

**`homework.cpp`**
<!-- file: homework.cpp -->
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> points = {
        {8, 10, 7},         // Aziz handed in three tasks
        {9, 6},             // Malika handed in two
        {10, 10, 9, 8}      // Jasur handed in four
    };

    for (const std::vector<int>& row : points) {    // each row is a vector
        int sum = 0;
        for (int value : row) {
            sum += value;
        }
        std::cout << row.size() << " tasks, " << sum << " points\n";
    }
}
```

<!-- output: homework -->
```text
3 tasks, 25 points
2 tasks, 15 points
4 tasks, 37 points
```

## Watch out

- Use round brackets for a row: `std::vector<int>(4, 0)` is four zeros, but
  `std::vector<int>{4, 0}` is the two elements 4 and 0.
- The row comes first. `seats[3][0]` asks for a fourth row that does not exist: undefined
  behaviour, as always with `[]`.
- Ask each row for its own size, as `seats[r].size()` does. A fixed number breaks when the
  rows have different lengths.

## Try it

1. Predict the output of `puzzle.cpp`:

   **`puzzle.cpp`**
   <!-- file: puzzle.cpp -->
   ```cpp
   #include <iostream>
   #include <vector>

   int main() {
       std::vector<std::vector<int>> grid(2, std::vector<int>(3, 7));
       grid[1][0] = 0;
       grid[0].push_back(5);

       for (const std::vector<int>& row : grid) {
           for (int value : row) {
               std::cout << value << ' ';
           }
           std::cout << '\n';
       }
   }
   ```

2. Change `seats.cpp` so that it also prints how many seats are free.

<details>
<summary>Answers</summary>

1. Both rows start as `7 7 7`. One element of row 1 changes, and row 0 grows by one:

   <!-- output: puzzle -->
   ```text
   7 7 7 5
   0 7 7
   ```

2. Count inside the inner loop, and print `freeSeats` after the loops. The answer is 10.

   ```cpp
   if (seats[r][c] == 0) {
       ++freeSeats;
   }
   ```
</details>

**Next:** [Sort and search](../08-sort-and-search/README.md)
