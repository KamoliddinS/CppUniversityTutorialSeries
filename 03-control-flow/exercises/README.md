# Exercises · Control flow

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-03-02 --output-on-failure
```

Run the first command once. The second one checks exercise 2 of chapter 03.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. Print only results, no questions such as `Age: `.

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the output](#1--predict-the-output) | predict | warm-up |
| 2 | [Ticket price](#2--ticket-price) | fix | warm-up |
| 3 | [Calculator](#3--calculator) | complete | core |
| 4 | [Stairs](#4--stairs) | write | core |
| 5 | [Marks report](#5--marks-report) | write | core |
| 6 | [Wallet](#6--wallet) | write | stretch |

## 1 · Predict the output

Folder: [`01-predict-the-output`](01-predict-the-output/). Check: `ex-03-01`.

Read [`program.cpp`](01-predict-the-output/program.cpp) **without running it**. Type the
output you expect into `prediction.txt`, line for line. Then run the check.

<details>
<summary>Hint</summary>

Write a trace table for each loop: one row for every round, one column for every variable.
</details>

## 2 · Ticket price

Folder: [`02-ticket-price`](02-ticket-price/). Check: `ex-03-02`.

[`exercise.cpp`](02-ticket-price/exercise.cpp) reads an age and should print the price of a
museum ticket. It builds, but it has three mistakes. Find them and fix them.

| The user types an age | The program prints |
|-----------------------|--------------------|
| younger than 7 | `Free entry` |
| 7 to 17 | `Price: 10000 so'm` |
| 18 to 64 | `Price: 25000 so'm` |
| 65 or older | `Free entry` |

<details>
<summary>Hint</summary>

Build the file yourself with `-Wall -Wextra`: g++ points at one of the mistakes. For the
other two, try one age from every row of the table. Can an age be below 7 **and** above 64?
Which test of the chain does the age 12 reach first?
</details>

## 3 · Calculator

Folder: [`03-calculator`](03-calculator/). Check: `ex-03-03`.

[`exercise.cpp`](03-calculator/exercise.cpp) reads a whole number, an operator and another
whole number, and prints the result. Only `+` works. Complete the `switch`.

| The user types | Your program prints |
|----------------|---------------------|
| `7 + 5` | `12` |
| `7 - 5` | `2` |
| `7 * 6` or `7 x 6` | `42` |
| `7 / 2` | `3` |
| `7 / 0` | `Cannot divide by zero` |
| `7 ? 2` | `Unknown operator` |

<details>
<summary>Hint</summary>

Two labels can share one block. Test `b` before you divide.
</details>

## 4 · Stairs

Folder: [`04-stairs`](04-stairs/). Check: `ex-03-04`.

Read a whole number `n` (at least 1). Print stairs with `n` steps: line 1 has one `#`,
line 2 has two, and so on. When the user types `3`, your program prints:

```text
#
##
###
```

<details>
<summary>Hint</summary>

The outer loop counts the lines. The inner loop prints the `#` characters of one line: it
runs as many rounds as the number of that line.
</details>

## 5 · Marks report

Folder: [`05-marks-report`](05-marks-report/). Check: `ex-03-05`.

Read whole-number marks from 1 to 100 until the user types `0`. Then print how many marks
there are, their average, the lowest and the highest mark, and `All passed` or
`Not all passed`. A mark below 60 is a fail. When the user types `80 55 90 85 0`, your
program prints:

```text
Marks: 4
Average: 77.5
Lowest: 55
Highest: 90
Not all passed
```

When the first number is `0`, there are no marks: print only `No marks`.

<details>
<summary>Hint</summary>

These are the four [loop patterns](../06-loop-patterns/README.md). Start the lowest and the
highest mark from the first mark, not from 0. The average of the example is 77.5, not 77:
see [Conversions](../../02-values-and-types/05-conversions/README.md).
</details>

## 6 · Wallet

Folder: [`06-wallet`](06-wallet/). Check: `ex-03-06`.

Write a program that keeps the balance of a wallet. The balance starts at 0. The program
reads one command per line until the command `0`, or until the input ends.

| The line | What the program does |
|----------|-----------------------|
| `1 AMOUNT` | adds `AMOUNT` to the balance |
| `2 AMOUNT` | takes `AMOUNT` from the balance; if there is not enough money, it prints `Not enough money` and changes nothing |
| `3` | prints `Balance: ` and the balance |
| `0` | stops reading |
| another number | prints `Unknown command` |
| does not start with a number | prints `Wrong input` and skips the rest of that line |

At the end the program prints `Final balance: ` and the balance. `AMOUNT` is always a
whole number above 0.

The user types:

```text
1 20000
abc
2 50000
7
3
2 5000
0
```

Your program prints:

```text
Wrong input
Not enough money
Unknown command
Balance: 20000
Final balance: 15000
```

<details>
<summary>Hint</summary>

Read the command with the `if` block from [Safe input](../07-safe-input/README.md). One
test has no `0` at the end, so the loop must also stop when the input ends.
</details>

**Next chapter:** [04 · Functions](../../04-functions/README.md)
