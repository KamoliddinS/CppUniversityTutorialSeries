# Exercises · Functions

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-04-02 --output-on-failure
```

Run the first command once. The second one checks exercise 2 of chapter 04.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. You can also build and run the file yourself and
compare with the example.

Exercises 3 and 5 read no input. Their `main` calls your functions and prints one line for
every check that fails. You are done when it prints `All checks passed.`

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the output](#1--predict-the-output) | predict | warm-up |
| 2 | [Fix the build](#2--fix-the-build) | fix | warm-up |
| 3 | [Days in a month](#3--days-in-a-month) | complete | core |
| 4 | [Wrong report](#4--wrong-report) | fix | core |
| 5 | [Sum of digits](#5--sum-of-digits) | complete | core |
| 6 | [Receipt](#6--receipt) | write | stretch |

## 1 · Predict the output

Folder: [`01-predict-the-output`](01-predict-the-output/). Check: `ex-04-01`.

Read [`program.cpp`](01-predict-the-output/program.cpp) **without running it**. Type the
output you expect into `prediction.txt`, line for line. Then run the check.

<details>
<summary>Hint</summary>

Look at the first line of each function. Which one works on a copy, and which one on the
caller's variable? What does `show()` print when the call gives it nothing?
</details>

## 2 · Fix the build

Folder: [`02-fix-the-build`](02-fix-the-build/). Check: `ex-04-02`.

[`exercise.cpp`](02-fix-the-build/exercise.cpp) has four mistakes. Three of them stop the
build: fix the first problem that the build reports, and build again. The fourth mistake
gives only a warning. Read it: the program does not work until you fix that too. Keep the
three lines inside `main` as they are. In the end the program prints:

```text
Tickets to Bukhara: 2, price 90000 so'm
Tickets to Khiva: 1, price 45000 so'm
```

<details>
<summary>Hint</summary>

The mistakes come from three lessons:
[Function declarations](../05-function-declarations/README.md),
[Parameters and return values](../02-parameters-and-return-values/README.md) (two of them)
and [Const references](../04-const-references/README.md). If you add a declaration, think
about where the default argument belongs:
[Default arguments and overloading](../06-default-arguments-and-overloading/README.md).
</details>

## 3 · Days in a month

Folder: [`03-days-in-a-month`](03-days-in-a-month/). Check: `ex-04-03`.

[`exercise.cpp`](03-days-in-a-month/exercise.cpp) has two functions that are not finished.
Complete them at the `TODO` marks.

| Function | What it must do |
|----------|-----------------|
| `isLeapYear(year)` | return `true` for a leap year: a year that can be divided by 4, but not by 100, unless it can also be divided by 400 |
| `daysInMonth(month, year)` | return the number of days in that month, or 0 when `month` is not a number from 1 to 12. Months 4, 6, 9 and 11 have 30 days; month 2 has 28, or 29 in a leap year; the others have 31 |

| Call | Result |
|------|--------|
| `isLeapYear(1900)` | `false` |
| `isLeapYear(2000)` | `true` |
| `daysInMonth(2, 2024)` | `29` |
| `daysInMonth(4, 2026)` | `30` |

<details>
<summary>Hint</summary>

`return` ends the function at once, so you can deal with one case after the other. In
`isLeapYear`, start with the most special case: `if (year % 400 == 0) { return true; }`.
</details>

## 4 · Wrong report

Folder: [`04-wrong-report`](04-wrong-report/). Check: `ex-04-04`.

[`exercise.cpp`](04-wrong-report/exercise.cpp) reads scores until the input ends. Every
score gets 5 bonus points, but no score goes above 100. The report ends with the number of
students and the best score. The program builds without a warning, but its numbers are
wrong. Find the two bugs and fix them.

The user types:

```text
70 98 85
```

Your program prints:

```text
with bonus: 75
new best: 75
with bonus: 100
new best: 100
with bonus: 90
students: 3
best: 100
```

<details>
<summary>Hint</summary>

Run the program and compare its output with the example, line by line. Does `addBonus`
work on the caller's `score` or on a copy? How many variables are named `best`? See
[Pass by value and by reference](../03-pass-by-value-and-by-reference/README.md) and
[Scope and lifetime](../07-scope-and-lifetime/README.md).
</details>

## 5 · Sum of digits

Folder: [`05-sum-of-digits`](05-sum-of-digits/). Check: `ex-04-05`.

Complete `digitSum` in [`exercise.cpp`](05-sum-of-digits/exercise.cpp). It returns the sum
of the digits of a number that is 0 or more. Use recursion: the function calls itself, and
it has no loop.

| Call | Result |
|------|--------|
| `digitSum(7)` | `7` |
| `digitSum(472)` | `13`, because 4 + 7 + 2 = 13 |

<details>
<summary>Hint</summary>

`number % 10` is the last digit, and `number / 10` is the number without its last digit.
So the digit sum of 472 is 2 plus the digit sum of 47. Which numbers need no further call?
That is your base case.
</details>

## 6 · Receipt

Folder: [`06-receipt`](06-receipt/). Check: `ex-04-06`.

Write a program for a shop. Each line of the input is one item: a name (one word), the
price of one piece in so'm, and the number of pieces. Read items until the input ends.
Print one row for each item, then the total, the discount and the amount to pay. A total
of 100000 so'm or more gets a discount of 10%: the total divided by 10, as a whole number.
Below that the discount is 0.

The user types:

```text
notebook 12000 3
pen 3000 5
bag 150000 1
```

Your program prints:

```text
notebook: 36000 so'm
pen: 15000 so'm
bag: 150000 so'm
--------------------
Total: 201000 so'm
Discount: 20100 so'm
====================
To pay: 180900 so'm
```

[`exercise.cpp`](06-receipt/exercise.cpp) already declares four functions. Use them in
`main`, and define them below `main`:

| Function | What it must do |
|----------|-----------------|
| `itemCost` | return the price times the quantity |
| `printRow` | print one line: the label, `: `, the amount and ` so'm` |
| `drawLine` | print `symbol` `length` times, then end the line |
| `applyDiscount` | work out the discount and the amount to pay, and store them in the caller's two variables |

<details>
<summary>Hint</summary>

A read is also a condition ([Safe input](../../03-control-flow/07-safe-input/README.md)),
so the loop can be `while (std::cin >> name >> price >> quantity)`: it ends when the input
ends. Create `discount` and `toPay` in `main` before you call `applyDiscount`. Every line
of the receipt except the two drawn lines is one call of `printRow`. The second drawn line
is `drawLine(20, '=')`.
</details>

**Next chapter:** [05 · Vectors and strings](../../05-vectors-and-strings/README.md)
