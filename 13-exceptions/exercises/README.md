# Exercises · Exceptions

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-13-02 --output-on-failure
```

Run the first command once. The second one checks exercise 2 of chapter 13.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. You can also build and run the file yourself and
compare with the example.

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the output](#1--predict-the-output) | predict | warm-up |
| 2 | [Skip the bad lines](#2--skip-the-bad-lines) | fix | warm-up |
| 3 | [Plug the leak](#3--plug-the-leak) | fix | core |
| 4 | [Out of stock](#4--out-of-stock) | complete | core |
| 5 | [Parse a score](#5--parse-a-score) | write | core |
| 6 | [Bus tickets](#6--bus-tickets) | write | stretch |

## 1 · Predict the output

Folder: [`01-predict-the-output`](01-predict-the-output/). Check: `ex-13-01`.

Read [`program.cpp`](01-predict-the-output/program.cpp) **without running it**. Type the
output you expect into `prediction.txt`, line for line. Then run the check.

<details>
<summary>Hint</summary>

A `Step` prints one line when it is created and one when it is destroyed. Ask for every
function: which objects are alive when the exception leaves it?
</details>

## 2 · Skip the bad lines

Folder: [`02-skip-the-bad-lines`](02-skip-the-bad-lines/). Check: `ex-13-02`.

Every input line should be a whole number. [`exercise.cpp`](02-skip-the-bad-lines/exercise.cpp)
should add up the good lines and report each bad one. It builds, but it has two bugs:
it stops at the first bad line, and it never prints `too large`.

| The user types | Your program prints |
|----------------|---------------------|
| `12000`<br>`abc`<br>`3000`<br>`99999999999`<br>`500` | `not a number: abc`<br>`too large: 99999999999`<br>`Total: 15500` |

<details>
<summary>Hint</summary>

After a handler, the program goes on *below* the `try` block. Where must the `try` block be
so that the loop continues? For the second bug, read the warning that g++ prints.
</details>

## 3 · Plug the leak

Folder: [`03-plug-the-leak`](03-plug-the-leak/). Check: `ex-13-03`.

[`exercise.cpp`](03-plug-the-leak/exercise.cpp) opens the report `timetable` and never closes
it. Find out why. Then change `printReport` so that every report is closed. Do not change
`Report` or `main`. The program must print:

```text
open grades
print grades: 4 pages
close grades
open timetable
close timetable
error: not enough paper
```

<details>
<summary>Hint</summary>

Stack unwinding destroys local objects, but a raw pointer has no destructor. Let an object
own the report. See [Stack unwinding](../03-stack-unwinding/README.md).
</details>

## 4 · Out of stock

Folder: [`04-out-of-stock`](04-out-of-stock/). Check: `ex-13-04`.

A shop starts with 10 somsa. Every number in the input is one order. Complete the three
`TODO` parts of [`exercise.cpp`](04-out-of-stock/exercise.cpp): write the exception class
`OutOfStock`, throw it when an order is too large, and catch it in `main`.

| The user types | Your program prints |
|----------------|---------------------|
| `4`<br>`8`<br>`6`<br>`1` | `sold 4, 6 left`<br>`refused: not enough somsa, 2 missing`<br>`sold 6, 0 left`<br>`refused: not enough somsa, 1 missing` |

<details>
<summary>Hint</summary>

`BalanceTooLow` in [Your own exceptions](../04-your-own-exceptions/README.md) has the same
shape. A refused order must not change the stock.
</details>

## 5 · Parse a score

Folder: [`05-parse-a-score`](05-parse-a-score/). Check: `ex-13-05`.

In [`exercise.cpp`](05-parse-a-score/exercise.cpp), write the function

```cpp
std::optional<int> parseScore(const std::string& text);
```

It returns the score when `text` is a whole number from 0 to 100, and no value for every
other text. It never throws. This exercise checks itself: `main` calls `parseScore` and
prints `ok` or `WRONG` for each case. You are done when it prints `0 wrong`.
(The checks do not use text such as `12abc`, which `std::stoi` reads as 12.)

| Call | Result |
|------|--------|
| `parseScore("87")` | `87` |
| `parseScore("101")` | no value |
| `parseScore("abc")` | no value |

<details>
<summary>Hint</summary>

`std::stoi` throws for `abc` and for a number that is too large. Catch that inside
`parseScore` and return `std::nullopt`.
</details>

## 6 · Bus tickets

Folder: [`06-bus-tickets`](06-bus-tickets/). Check: `ex-13-06`.

A small bus has the seats 1 to 4. The program reads commands until the input ends:
`book SEAT NAME` gives a seat to a passenger, and `who SEAT` asks who sits there.

| The user types | Your program prints |
|----------------|---------------------|
| `book 2 Aziz` | `seat 2: Aziz` |
| `book 2 Malika` | `error: seat 2 is taken` |
| `book 7 Jasur` | `error: no such seat` |
| `who 2` | `seat 2: Aziz` |
| `who 3` | `seat 3: free` |

Write the four `TODO` parts of [`exercise.cpp`](06-bus-tickets/exercise.cpp):

1. The exception class `SeatTaken`. It stores the seat number.
2. `Bus::book` throws `std::out_of_range("no such seat")` or a `SeatTaken`.
3. `Bus::passenger` returns a `std::optional`: a free seat is normal, not an error.
   For a seat that does not exist, such as `who 0`, it throws `std::out_of_range("no such seat")`.
4. `main` answers the commands and prints one `error:` line for each exception.
   It goes on with the next command.

<details>
<summary>Hint</summary>

Put the `try` block inside the loop. Print the text of `std::out_of_range` with `e.what()`,
and build the other error line from `e.seat()`.
</details>

**Next chapter:** [14 · Templates](../../14-templates/README.md)
