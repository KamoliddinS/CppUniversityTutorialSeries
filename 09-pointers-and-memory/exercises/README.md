# Exercises · Pointers and memory

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-09-02 --output-on-failure
```

Run the first command once. The second one checks exercise 2 of chapter 09.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. You can also build and run the file yourself and
compare with the example.

Exercise 2 reads no input. Its `main` calls your functions and prints one line for every
check that fails. You are done when it prints `All checks passed.`

The check does not look for memory bugs. So build exercises 3 and 5 with the sanitizer as
well, and make sure that no report appears:

```sh
g++ -std=c++20 -Wall -Wextra -g -fsanitize=address,undefined exercise.cpp -o exercise
./exercise
```

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the pointers](#1--predict-the-pointers) | predict | warm-up |
| 2 | [Pointer tools](#2--pointer-tools) | complete | core |
| 3 | [Two memory bugs](#3--two-memory-bugs) | fix | core |
| 4 | [Calculator](#4--calculator) | write | core |
| 5 | [Growing list](#5--growing-list) | complete | stretch |

## 1 · Predict the pointers

Folder: [`01-predict-the-pointers`](01-predict-the-pointers/). Check: `ex-09-01`.

Read [`program.cpp`](01-predict-the-pointers/program.cpp) **without running it**. Draw a
memory table (Name, Address, Value) on paper and update it line by line. Type the output
you expect into `prediction.txt`, line for line. Then run the check.

<details>
<summary>Hint</summary>

Make up the addresses, for example `0x1000` for `a`. After `q = p;` both pointers hold the
same address, so they change the same variable.
</details>

## 2 · Pointer tools

Folder: [`02-pointer-tools`](02-pointer-tools/). Check: `ex-09-02`.

[`exercise.cpp`](02-pointer-tools/exercise.cpp) has two functions that are not finished.
Complete them at the `TODO` marks. Do not change `check` and `main`.

| Function | What it must do |
|----------|-----------------|
| `swapValues(a, b)` | swap the two `int`s that the pointers `a` and `b` point to |
| `findFirst(values, size, target)` | return a pointer to the first of the `size` elements that is equal to `target`, or `nullptr` when there is none |

| Call | Result |
|------|--------|
| `swapValues(&x, &y)` with `x` = 3 and `y` = 8 | `x` is 8, `y` is 3 |
| `findFirst(prices, 5, 1200)` with the prices `700 1200 500 1200 900` | `prices + 1`, the address of `prices[1]` |
| `findFirst(prices, 5, 800)` | `nullptr` |

<details>
<summary>Hint</summary>

A swap needs a third variable that keeps one value for a moment. For `findFirst`, walk with
a pointer as in [Pointers and arrays](../02-pointers-and-arrays/README.md), and return that pointer.
</details>

## 3 · Two memory bugs

Folder: [`03-two-memory-bugs`](03-two-memory-bugs/). Check: `ex-09-03`.

[`exercise.cpp`](03-two-memory-bugs/exercise.cpp) should read a count, then that many whole
numbers, and print the numbers in reverse order. It builds, but it has two memory bugs.

Build it with the sanitizer and run it. The report names the bug and the line. Fix that
bug, then build and run again to find the second one.

| The user types | Your program prints |
|----------------|---------------------|
| `4`, then `10 20 30 40` | `40 30 20 10` |

<details>
<summary>Hint</summary>

The first report says `heap-buffer-overflow` and `READ`: which element does the loop read
first? The second report says `double-free`: who owns the array, `main` or `printReversed`?
</details>

## 4 · Calculator

Folder: [`04-calculator`](04-calculator/). Check: `ex-09-04`.

Every input line holds a whole number, an operator and another whole number. Print the
result of each line. For an operator that is not `+`, `-` or `*`, print `unknown operator`.

Use a function pointer. In [`exercise.cpp`](04-calculator/exercise.cpp), write `add`,
`subtract` and `multiply`, and a function `choose` that returns a pointer to the right one,
or `nullptr` for an unknown symbol.

| The user types | Your program prints |
|----------------|---------------------|
| `6 * 7` | `42` |
| `10 - 4` | `6` |
| `8 / 2` | `unknown operator` |

<details>
<summary>Hint</summary>

`Operation` is the alias at the top of the starter file. `return add;` gives back the
address of the function `add`. In `main`, test the pointer before you call it.
</details>

## 5 · Growing list

Folder: [`05-growing-list`](05-growing-list/). Check: `ex-09-05`.

Read whole numbers until the input ends. Nobody tells you how many will come, so keep them
in a heap array that grows: when it is full, create an array twice as large, copy the
numbers, and delete the old array. `std::vector` works like this inside.

Complete [`exercise.cpp`](05-growing-list/exercise.cpp): write `grow` and `largest`, then
finish `main`. For the input `4 8 15 16 23 42` the program prints:

```text
Count: 6
Reversed: 42 23 16 15 8 4
Largest: 42
```

When there are no numbers, the last line is `Largest: none`.

<details>
<summary>Hint</summary>

In `grow` the order matters: create the new array, copy, delete the old array, return the
new one. In `main`, store what `grow` returns in `values`, because the old address is no
longer valid. The sanitizer tells you when a `delete[]` is missing or comes twice.
</details>

Here you had to remember every `delete[]` yourself. The next chapter shows how a class can
do that for you.

**Next chapter:** [10 · Resource management](../../10-resource-management/README.md)
