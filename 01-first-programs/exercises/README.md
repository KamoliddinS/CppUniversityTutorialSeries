# Exercises · First programs

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-01-02 --output-on-failure
```

Run the first command once. The second one checks exercise 2 of chapter 01.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. You can also build and run the file yourself and
compare with the example.

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the output](#1--predict-the-output) | predict | warm-up |
| 2 | [Fix the build](#2--fix-the-build) | fix | warm-up |
| 3 | [Business card](#3--business-card) | complete | core |
| 4 | [Next year](#4--next-year) | write | core |
| 5 | [Wrong average](#5--wrong-average) | fix | stretch |

## 1 · Predict the output

Folder: [`01-predict-the-output`](01-predict-the-output/). Check: `ex-01-01`.

Read [`program.cpp`](01-predict-the-output/program.cpp) **without running it**. Type the
output you expect into `prediction.txt`, line for line. Then run the check.

## 2 · Fix the build

Folder: [`02-fix-the-build`](02-fix-the-build/). Check: `ex-01-02`.

[`exercise.cpp`](02-fix-the-build/exercise.cpp) has four mistakes. Build it, fix the first
problem the build reports, and build again. Repeat until it prints:

```text
Registan Square is in Samarkand.
It has three madrasahs.
The oldest was finished in 1420.
```

<details>
<summary>Hint</summary>

Three mistakes are compile errors. The last one is a linker error: look at the name of the
function the program starts in.
</details>

## 3 · Business card

Folder: [`03-business-card`](03-business-card/). Check: `ex-01-03`.

Complete [`exercise.cpp`](03-business-card/exercise.cpp) so it prints exactly this card:

```text
+----------------------+
| Aziz Karimov         |
| Student, Tashkent    |
| Year: 2026           |
+----------------------+
```

Print `2026` as a number, not as part of the text.

## 4 · Next year

Folder: [`04-next-year`](04-next-year/). Check: `ex-01-04`.

Read a full name (one whole line) and an age. Print one sentence. Do not print questions.

| The user types | Your program prints |
|----------------|---------------------|
| `Malika Karimova`, then `19` | `Malika Karimova will be 20 next year.` |

<details>
<summary>Hint</summary>

A name can contain a space, so `std::cin >> name` is not enough. See
[Output and input](../02-output-and-input/README.md).
</details>

## 5 · Wrong average

Folder: [`05-wrong-average`](05-wrong-average/). Check: `ex-01-05`.

[`exercise.cpp`](05-wrong-average/exercise.cpp) reads three whole numbers and should print
their average. It builds and runs, but the answer is wrong. Find the logic error and fix it.
(The numbers in the tests always add up to a multiple of 3.)

| The user types | Your program prints |
|----------------|---------------------|
| `10 20 30` | `Average: 20` |

**Next chapter:** [02 · Values and types](../../02-values-and-types/README.md)
