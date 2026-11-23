# Exercises · Classes

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-07-03 --output-on-failure
```

Run the first command once. The second one checks exercise 3 of chapter 07.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. You can also build and run the file yourself and
compare with the example.

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the output](#1--predict-the-output) | predict | warm-up |
| 2 | [Fix the class](#2--fix-the-class) | fix | warm-up |
| 3 | [Car park](#3--car-park) | complete | core |
| 4 | [Marks](#4--marks) | write | core |
| 5 | [Three files](#5--three-files) | fix | core |
| 6 | [Bank](#6--bank) | write | stretch |

## 1 · Predict the output

Folder: [`01-predict-the-output`](01-predict-the-output/). Check: `ex-07-01`.

Read [`program.cpp`](01-predict-the-output/program.cpp) **without running it**. Type the
output you expect into `prediction.txt`, line for line. Then run the check.

<details>
<summary>Hint</summary>

Find the closing brace where each lamp's life ends. Objects are destroyed in the reverse
order of their creation.
</details>

## 2 · Fix the class

Folder: [`02-fix-the-class`](02-fix-the-class/). Check: `ex-07-02`.

[`exercise.cpp`](02-fix-the-class/exercise.cpp) has four mistakes. Build it, fix the first
problem the compiler reports, and build again. Repeat until the program prints:

```text
O'tkan kunlar: 2 left
No copies left.
O'tkan kunlar: 0 left
```

Keep `copies_` private: `main` must use the member functions of the class.

<details>
<summary>Hint</summary>

One mistake is in the first line of the constructor, one is at the end of the class, and one
is about `const` (it needs a change in two lines). The last one is a line in `main` that touches private data: which member
function does the job of that line?
</details>

## 3 · Car park

Folder: [`03-car-park`](03-car-park/). Check: `ex-07-03`.

The class `CarPark` in [`exercise.cpp`](03-car-park/exercise.cpp) counts the cars in a car
park. Its invariant is `0 <= cars_ && cars_ <= places_`, but the class does not keep it yet.
Complete the four `TODO` parts. Do not change `main`.

The input is the number of places, then the words `in` (a car drives in) and `out` (a car
drives out). For the input `2 in in in out` the program prints:

```text
in: 1 free
in: 0 free
in: refused
out: 1 free
```

<details>
<summary>Hint</summary>

In `enter` and `leave`, test first and change `cars_` only when the test allows it, as
`withdraw` does in [From struct to class](../01-from-struct-to-class/README.md).
</details>

## 4 · Marks

Folder: [`04-marks`](04-marks/). Check: `ex-07-04`.

In [`exercise.cpp`](04-marks/exercise.cpp), `report` and `main` are finished, but the class
they use is missing. Write the class `Marks`. It keeps the marks of one student in a private
`std::vector<int>`.

| Member function | What it does |
|-----------------|--------------|
| `add(mark)` | stores the mark and returns `true`. A mark below 0 or above 100 is not stored, and the result is `false` |
| `count()` | returns how many marks are stored |
| `best()` | returns the highest mark, or 0 when there are none |
| `average()` | returns the average as a `double`, or 0 when there are none |

For the input `90 75 101 60 -5 88 86` the program prints:

```text
Ignored: 101
Ignored: -5
Count: 5
Best: 90
Average: 79.8
```

<details>
<summary>Hint</summary>

`report` receives a `const Marks&`. Which of your member functions must be `const`?
</details>

## 5 · Three files

Folder: [`05-three-files/starter`](05-three-files/starter/). Check: `ex-07-05`.

This program is split into `main.cpp`, `thermostat.cpp` and `thermostat.h`. The header is
correct. The two `.cpp` files have four mistakes, so the program does not build. Fix them.
To build by hand, open a terminal in the `starter` folder:

```sh
g++ -std=c++20 -Wall -Wextra main.cpp thermostat.cpp -o thermostat
```

The input is the starting temperature, then the keys `+` (warmer) and `-` (cooler). The
thermostat stays between 16 and 30 degrees. For the input `29 + + + -` the program prints:

```text
Start: 29
30
30
30
29
```

<details>
<summary>Hint</summary>

Two mistakes are `#include` lines: one is missing, and one has the wrong kind of brackets.
The other two are first lines of member functions in `thermostat.cpp`: compare each with its
declaration in the header.
</details>

## 6 · Bank

Folder: [`06-bank`](06-bank/). Check: `ex-07-06`.

Write a small bank in [`exercise.cpp`](06-bank/exercise.cpp). The class `Account`:

- has private data: the owner's name, the account number and the balance in so'm;
- never lets the balance go below zero;
- numbers the accounts itself: 1, 2, 3, ... Use a static member for that, and a static
  member function `count()` that returns how many accounts were opened;
- marks every member function that only reads as `const`.

`main` keeps the accounts in a `std::vector<Account>` and reads commands until the input ends.

| Command | What it does |
|---------|--------------|
| `open NAME AMOUNT` | opens an account with that balance. A negative amount counts as 0 |
| `deposit N AMOUNT` | adds the amount to account `N`. An amount that is not positive is ignored |
| `withdraw N AMOUNT` | takes the amount from account `N`. If the balance is too small, it changes nothing and prints `Not enough money.` |
| `list` | prints one line for every account: number, owner, balance |

If account `N` does not exist, `deposit` and `withdraw` print `No such account.` After the
last command, the program prints how many accounts were opened. Names are single words, and
the tests withdraw positive amounts only. For this input:

```text
open Malika 50000
open Jasur 0
withdraw 1 80000
deposit 2 30000
deposit 5 100
list
```

the program prints:

```text
Not enough money.
No such account.
1. Malika: 50000 so'm
2. Jasur: 30000 so'm
Accounts: 2
```

<details>
<summary>Hint</summary>

Read the command word first: `while (std::cin >> command)`. Then read what that command
needs. Account `N` is the element with index `N - 1`.

Count in the constructor only, and do not write a destructor. The vector copies accounts and
destroys the copies, so a destructor that counts down gives a wrong number.
</details>

**Next chapter:** [08 · Operator overloading](../../08-operator-overloading/README.md)
