# Write and read files

> **Goal:** save text in a file, read it back, and notice when a file cannot be opened.

## Write

A **file stream** is a variable connected to a file. You use `<<` and `>>` on it as on
`std::cout` and `std::cin`.

**`write_scores.cpp`**
<!-- file: write_scores.cpp -->
```cpp
#include <fstream>
#include <iostream>

int main() {
    std::ofstream out("scores.txt");    // creates the file, or empties an old one
    if (!out) {
        std::cout << "Cannot create scores.txt\n";
        return 1;
    }

    out << "Aziz " << 85 << '\n';       // write with <<, as with std::cout
    out << "Malika " << 92 << '\n';
    out << "Jasur " << 78 << '\n';
    std::cout << "Saved 3 scores.\n";
}
```

<!-- output: write_scores -->
```text
Saved 3 scores.
```

Afterwards `scores.txt` holds:

**`scores.txt`**
<!-- file: scores.txt -->
```text
Aziz 85
Malika 92
Jasur 78
```

- `!out` is true if the file could not be opened. Then `return 1;` ends `main` and reports
  a failure ([Program arguments](../06-program-arguments/README.md)).
- You do not close the file: the stream does it when `out` goes out of scope.

Both kinds of file stream come from `<fstream>`:

| Open with | The file |
|-----------|----------|
| `std::ofstream out("scores.txt");` | is created, or emptied if it exists |
| `std::ofstream out("scores.txt", std::ios::app);` | is created if needed; new text goes after the old text |
| `std::ifstream in("scores.txt");` | must exist; you only read from it |

## Read

**`read_scores.cpp`**
<!-- file: read_scores.cpp -->
```cpp
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream in("scores.txt");
    if (!in) {                          // always test, right after opening
        std::cout << "Cannot open scores.txt\n";
        return 1;
    }

    std::string name;
    int score = 0;
    int total = 0;
    while (in >> name >> score) {       // the loop ends when a read fails
        std::cout << name << " has " << score << '\n';
        total += score;
    }
    std::cout << "Total: " << total << '\n';
}
```

<!-- output: read_scores -->
```text
Aziz has 85
Malika has 92
Jasur has 78
Total: 255
```

The read is the loop condition, as in
[Safe input](../../03-control-flow/07-safe-input/README.md): the loop ends at the first
read that fails, normally at the end of the file.

| The file holds | Loop | One round reads |
|----------------|------|-----------------|
| values with spaces or line ends between them | `while (in >> name >> score)` | the next values |
| lines of text | `while (std::getline(in, line))` | one whole line |

[`read_lines.cpp`](read_lines.cpp) prints the same file with the second loop:

<!-- output: read_lines -->
```text
1: Aziz 85
2: Malika 92
3: Jasur 78
```

## Watch out

**A missing file is not a crash.** This program has no `if (!in)`:

<!-- snippet: missing_file.cpp -->
```cpp
std::ifstream in("marks.txt");      // there is no such file
while (in >> mark) {
    total += mark;
}
```

<!-- output: missing_file -->
```text
Total: 0
```

Every read fails silently. Test right after opening.

**Never loop with `while (!in.eof())`.** `eof()` turns true only when a read has tried to
go past the end. After `78` the line end is still unread, so the loop runs once more:

<!-- snippet: eof_loop_bug.cpp -->
```cpp
while (!in.eof()) {                 // wrong: still false after the last score
    in >> name >> score;            // the fourth read fails and changes nothing
    std::cout << name << " has " << score << '\n';
    total += score;
}
```

```text
Aziz has 85
Malika has 92
Jasur has 78
Jasur has 78
Total: 333
```

With a word where a number belongs, `eof()` never turns true: the loop never ends.

**A plain name such as `"scores.txt"` means a file in the
[current folder](../../00-getting-started/02-use-the-terminal/README.md)**: the folder the
terminal is in, not the folder of the `.cpp` file. If a file "does not exist", look there first.

## Try it

1. `numbers.txt` holds `10 20 x 30`. Predict the output:

   ```cpp
   std::ifstream in("numbers.txt");
   int n = 0;
   int sum = 0;
   while (in >> n) {
       sum += n;
   }
   std::cout << sum << '\n';
   ```

2. Run `write_scores` twice. How many lines does `scores.txt` have? Now open the file with
   `std::ios::app` and run twice again.

<details>
<summary>Answers</summary>

1. `30`. The third read fails at `x` and ends the loop. The `30` in the file is never read.
2. Still 3: every run empties the file first. With `std::ios::app` each run adds 3 lines: 6, then 9.
   Remove `std::ios::app` and run once more to get the 3 lines back.
</details>

**Next:** [Parse lines](../04-parse-lines/README.md)
