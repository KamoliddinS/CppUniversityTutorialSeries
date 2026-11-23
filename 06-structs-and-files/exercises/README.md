# Exercises · Structs and files

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-06-03 --output-on-failure
```

Run the first command once. The second one checks exercise 3 of chapter 06.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. You can also build and run the file yourself and
compare with the example.

Exercises 5 and 6 read a data file from their own folder. The check puts a copy next to
your program. When you run the program yourself, start it in the exercise folder.

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the output](#1--predict-the-output) | predict | warm-up |
| 2 | [Fix the build](#2--fix-the-build) | fix | warm-up |
| 3 | [Travel log](#3--travel-log) | fix | core |
| 4 | [Parse a product](#4--parse-a-product) | complete | core |
| 5 | [Numbered copy](#5--numbered-copy) | write | core |
| 6 | [Exam report](#6--exam-report) | write | stretch |

## 1 · Predict the output

Folder: [`01-predict-the-output`](01-predict-the-output/). Check: `ex-06-01`.

Read [`program.cpp`](01-predict-the-output/program.cpp) **without running it**. Type the
output you expect into `prediction.txt`, line for line. Then run the check.

<details>
<summary>Hint</summary>

Three questions decide the answer. Is `black` a copy of `green`, or the same tea? Does the
loop change the teas in `menu`, or copies of them? Which items does `std::setw(8)` apply to?
</details>

## 2 · Fix the build

Folder: [`02-fix-the-build`](02-fix-the-build/). Check: `ex-06-02`.

[`exercise.cpp`](02-fix-the-build/exercise.cpp) has five mistakes. Build it, fix the first
error the compiler reports, and build again. Repeat until it prints:

```text
Malika orders 3 large teas.
Size number: 2
```

<details>
<summary>Hint</summary>

g++ reports the first error for line 14, but the mistake is above it: look at how the
struct ends. The other four are: an enum value without `Size::`, values in the wrong order,
the name of the type where a variable belongs, and an enum used as a number.
</details>

## 3 · Travel log

Folder: [`03-travel-log`](03-travel-log/). Check: `ex-06-03`.

[`exercise.cpp`](03-travel-log/exercise.cpp) saves three stops of a trip in `trip.txt`,
adds a fourth one, and prints the list. It builds and runs, but it has two bugs. It prints:

```text
1. Khiva
2. Khiva
Stops: 2
```

Fix it so that it prints:

```text
1. Tashkent
2. Samarkand
3. Bukhara
4. Khiva
Stops: 4
```

<details>
<summary>Hint</summary>

Where did the first three stops go? Look at how `addStop` opens the file. Then look at the
loop that reads. Both bugs are described in
[Write and read files](../03-write-and-read-files/README.md).
</details>

## 4 · Parse a product

Folder: [`04-parse-a-product`](04-parse-a-product/). Check: `ex-06-04`.

Each line of input describes a product: name, price of one piece, quantity. `main` is
finished. Complete the function `parseProduct` in
[`exercise.cpp`](04-parse-a-product/exercise.cpp). It splits one line, fills a `Product`
and returns `true`. If the line does not have three fields, it returns `false`.

| The user types | Your program prints |
|----------------|---------------------|
| `Bread,4500,3` | `Bread: 3 x 4500 = 13500` |
| `Sugar,14000` | `Skipped: Sugar,14000` |
| `Rice,22000,2` | `Rice: 2 x 22000 = 44000` |
| (the input ends) | `Total: 57500 so'm` |

<details>
<summary>Hint</summary>

[Parse lines](../04-parse-lines/README.md) does the same for a student. Read all three
fields first, then test the string stream once. When you try the program by hand, end the
input with Ctrl+D (Windows: Ctrl+Z, then Enter).
</details>

## 5 · Numbered copy

Folder: [`05-numbered-copy`](05-numbered-copy/). Check: `ex-06-05`.

[`cities.txt`](05-numbered-copy/cities.txt) holds ten cities, one on each line. Write a
program that does three things, in this order:

1. It writes every line into a new file, `numbered.txt`, with its number in front. The
   number is 2 characters wide. A dot and a space follow it.
2. It reads `numbered.txt` and prints it on the screen.
3. It prints how many lines it copied.

```text
 1. Tashkent
 2. Samarkand
 3. Bukhara
 4. Khiva
 5. Andijan
 6. Namangan
 7. Fergana
 8. Nukus
 9. Termez
10. Kokand
10 lines copied
```

<details>
<summary>Hint</summary>

If only `10 lines copied` appears, you read `numbered.txt` too early: the text was still
waiting in the stream, not yet in the file. A stream closes its file when its variable goes out of scope. So do
the copying in a function of its own, and read `numbered.txt` after that function has
returned.
</details>

## 6 · Exam report

Folder: [`06-exam-report`](06-exam-report/). Check: `ex-06-06`.

[`exam.csv`](06-exam-report/exam.csv) holds one student on each line: name, comma, score.
One line is broken. Read the file into a `std::vector<Student>` and print this report:

```text
Skipped: this line is broken
Name      Score  Result
Aziz         85  good
Malika       92  excellent
Jasur        55  fail
Dilnoza      71  good
Laziz        63  pass
Nodira       86  excellent
Students: 6
Average: 75.3
```

- A line without a comma is reported with `Skipped:` and is not stored.
- The name is on the left, 10 wide. The score is on the right, 5 wide. Two spaces and the
  result follow.
- The result is `excellent` for 86 or more, `good` for 71 or more, `pass` for 56 or more,
  and `fail` for less. Work it out as a `Result` (the enum in the starter) and turn it into
  text with a function.
- The average has one decimal.

<details>
<summary>Hint</summary>

Work in small steps, and build and run after each one: read the lines and print them;
store them in the vector; print the table; print the last two lines. The three functions
named in the starter keep `main` short. Each one has a model in this chapter:
[Enums](../02-enums/README.md), [Parse lines](../04-parse-lines/README.md) and
[Format output](../05-format-output/README.md).
</details>

**Next chapter:** [07 · Classes](../../07-classes/README.md)
