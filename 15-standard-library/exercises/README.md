# Exercises · The standard library

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-15-02 --output-on-failure
```

Run the first command once. The second one checks exercise 2 of chapter 15.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. You can also build and run the file yourself and
compare with the example.

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the output](#1--predict-the-output) | predict | warm-up |
| 2 | [Price check](#2--price-check) | fix | warm-up |
| 3 | [Class report](#3--class-report) | complete | core |
| 4 | [Balanced brackets](#4--balanced-brackets) | write | core |
| 5 | [Leaderboard](#5--leaderboard) | write | stretch |

## 1 · Predict the output

Folder: [`01-predict-the-output`](01-predict-the-output/). Check: `ex-15-01`.

Read [`program.cpp`](01-predict-the-output/program.cpp) **without running it**. Type the
output you expect into `prediction.txt`, line for line. Then run the check.

<details>
<summary>Hint</summary>

Three questions decide the output. In which order does a loop visit a map? What does `[]`
do when the key is missing? When does `[step]` take its copy?
</details>

## 2 · Price check

Folder: [`02-price-check`](02-price-check/). Check: `ex-15-02`.

[`exercise.cpp`](02-price-check/exercise.cpp) reads product names. It should print the
price of each one, then the number of products the shop sells. Water (`suv`) costs 0 so'm,
but the shop does sell it. The program builds and runs, but its output is wrong in two
places. Find the cause and fix it.

When the user types `non qand suv`, the fixed program prints:

```text
non: 4000 so'm
qand: not sold here
suv: 0 so'm
3 products
```

<details>
<summary>Hint</summary>

Both mistakes have one cause: the program asks a question with `[]`. See "Watch out" in
[Maps and sets](../02-maps-and-sets/README.md).
</details>

## 3 · Class report

Folder: [`03-class-report`](03-class-report/). Check: `ex-15-03`.

Complete the three `TODO` parts of [`exercise.cpp`](03-class-report/exercise.cpp). The
program reads a pass mark. It prints the group with the highest score first (equal scores
in alphabetical order), then how many students passed (a score of at least the pass mark),
then the first student in that order who is below the pass mark.

When the user types `60`, your program prints:

```text
Malika 95
Nodira 95
Aziz 72
Dilnoza 72
Jasur 58
Laziz 41
passed: 4
first below: Jasur
```

With `40` the last two lines are `passed: 6` and `nobody below`.

<details>
<summary>Hint</summary>

In part 1, compare the names only when the two scores are equal. The lambdas of parts 2
and 3 must capture `passMark`. In part 3, compare the result with `group.end()` before you
use it. See [Algorithms](../05-algorithms/README.md).
</details>

## 4 · Balanced brackets

Folder: [`04-balanced-brackets`](04-balanced-brackets/). Check: `ex-15-04`.

Read one line of text. Print `balanced` if every opening bracket `(`, `[` or `{` is closed
by the matching bracket `)`, `]` or `}` in the right order. Otherwise print `not balanced`.
All other characters do not matter.

| The user types | Your program prints |
|----------------|---------------------|
| `(a + b) * [c - d]` | `balanced` |
| `(]` | `not balanced` |
| `x) + (y` | `not balanced` |

<details>
<summary>Hint</summary>

Push every opening bracket on a `std::stack<char>`. For a closing bracket, the top of the
stack must be its partner: then pop it. Two more cases are not balanced: a closing bracket
arrives when the stack is empty, and the stack is not empty at the end of the line.
</details>

## 5 · Leaderboard

Folder: [`05-leaderboard`](05-leaderboard/). Check: `ex-15-05`.

Each input line has a player's name and the points from one game. A player can appear many
times. Print a numbered table with the total points of every player: the highest total
first, equal totals in alphabetical order. The last line is the number of players.

When the user types these six lines:

```text
Aziz 3
Malika 1
Jasur 3
Aziz 1
Malika 3
Nodira 0
```

your program prints:

```text
1. Aziz 4
2. Malika 4
3. Jasur 3
4. Nodira 0
players: 4
```

<details>
<summary>Hint</summary>

Add the points up in a `std::map<std::string, int>`. A map is always sorted by its keys, so
you cannot sort it by total. Copy the entries into a vector of structs (a name and a total)
and sort that with a lambda.
</details>

**Next chapter:** [16 · Rust for C++ programmers](../../16-rust-for-cpp-programmers/README.md)
