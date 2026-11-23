# Exercises · Vectors and strings

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-05-03 --output-on-failure
```

Run the first command once. The second one checks exercise 3 of chapter 05.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. You can also build and run the file yourself and
compare with the example.

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the output](#1--predict-the-output) | predict | warm-up |
| 2 | [Score tools](#2--score-tools) | complete | warm-up |
| 3 | [Guest list](#3--guest-list) | fix | core |
| 4 | [Username](#4--username) | write | core |
| 5 | [Row and column sums](#5--row-and-column-sums) | write | core |
| 6 | [Word count](#6--word-count) | write | stretch |

## 1 · Predict the output

Folder: [`01-predict-the-output`](01-predict-the-output/). Check: `ex-05-01`.

Read [`program.cpp`](01-predict-the-output/program.cpp) **without running it**. Type the
output you expect into `prediction.txt`, line for line. Then run the check.

<details>
<summary>Hint</summary>

Write down the whole vector after every statement. Which of the loops work on copies?
</details>

## 2 · Score tools

Folder: [`02-score-tools`](02-score-tools/). Check: `ex-05-02`.

[`exercise.cpp`](02-score-tools/exercise.cpp) has three functions that are not finished.
Complete them at the `TODO` marks. This exercise reads no input: `main` calls your
functions and prints one line for every check that fails. You are done when it prints
`All checks passed.`

| Function | What it must do |
|----------|-----------------|
| `largest` | return the largest score, also when every score is negative |
| `append` | add every score of `more` to the end of the caller's vector |
| `reversed` | return a new vector with the scores in the opposite order |

<details>
<summary>Hint for <code>reversed</code></summary>

`result` already has the right size. The score that belongs in `result[i]` is at the index
`scores.size() - 1 - i`.
</details>

## 3 · Guest list

Folder: [`03-guest-list`](03-guest-list/). Check: `ex-05-03`.

[`exercise.cpp`](03-guest-list/exercise.cpp) reads a number and then that many full names,
one per line. It should print the names as a numbered list. It builds, but it has three
bugs. Find them and fix them.

The user types:

```text
3
Malika Karimova
Aziz Tursunov
Jasur Aliyev
```

Your program prints:

```text
Guests: 3
1. Malika Karimova
2. Aziz Tursunov
3. Jasur Aliyev
```

<details>
<summary>Hint</summary>

Run the program first. It stops with a message that names an index and a size: read them.
Then ask why the list is empty, and after that why the first name is empty. One bug is from
[Loop over a vector](../02-loop-over-a-vector/README.md), one from
[Vectors and functions](../03-vectors-and-functions/README.md) and one from
[Strings in depth](../04-strings-in-depth/README.md).
</details>

## 4 · Username

Folder: [`04-username`](04-username/). Check: `ex-05-04`.

Read a full name (one line). Print a username for it: the first letter of the first name,
then the last name, all in small letters. A line without a space is a single name: print it
in small letters. A line in the tests never has more than one space.

| The user types | Your program prints |
|----------------|---------------------|
| `Malika Karimova` | `mkarimova` |
| `Aziz` | `aziz` |

<details>
<summary>Hint</summary>

`find(' ')` tells you where the first name ends. Compare its result with
`std::string::npos`. Build the name first. Then make a copy in small letters with
`std::tolower`, as in [Characters](../05-characters/README.md).
</details>

## 5 · Row and column sums

Folder: [`05-row-and-column-sums`](05-row-and-column-sums/). Check: `ex-05-05`.

The first line of the input has the number of rows and the number of columns of a grid.
The whole numbers of the grid follow, row by row. Print the sum of every row on one line
and the sum of every column on the next line.

The user types:

```text
2 3
1 2 3
4 5 6
```

Your program prints:

```text
Rows: 6 15
Columns: 5 7 9
```

<details>
<summary>Hint</summary>

Read with two loops: `std::cin >> grid[r][c]`. For the row sums, the outer loop goes over
the rows. For the column sums, swap the two loops: the outer loop goes over the columns,
and the inner loop adds `grid[r][c]` for every row `r`.
</details>

## 6 · Word count

Folder: [`06-word-count`](06-word-count/). Check: `ex-05-06`.

Read the input word by word (`std::cin >> word`) until it ends. Clean every word: remove
the characters that are not letters and make the letters small. Skip a word that has no
letters at all. Then print every different word once, in alphabetical order, with the
number of times it appears. The last line is `Words:` and the number of words you kept.

The user types:

```text
The cat saw the dog.
The dog saw THE cat!
```

Your program prints:

```text
cat 2
dog 2
saw 2
the 4
Words: 10
```

Complete the function `clean` in [`exercise.cpp`](06-word-count/exercise.cpp) first, and
try it on a few words before you write the rest.

<details>
<summary>Hint</summary>

1. In `clean`, loop with `unsigned char c`. Start with an empty string and add every
   letter you keep with `+=`.
2. The loop `while (std::cin >> word)` stops when the input ends.
3. Sort the vector. Now equal words are next to each other.
4. Go through the sorted vector with an index. Print a word only when it is the first
   element, or when it differs from the element before it.
   `std::ranges::count(words, words[i])` tells you how many times it appears.
</details>

**Next chapter:** [06 · Structs and files](../../06-structs-and-files/README.md)
