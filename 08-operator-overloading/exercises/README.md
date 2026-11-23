# Exercises · Operator overloading

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-08-02 --output-on-failure
```

Run the first command once. The second one checks exercise 2 of chapter 08.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. You can also build and run the file yourself and
compare with the example.

Exercise 3 reads no input. Its `main` uses your operators and prints one line for every
check that fails. You are done when it prints `All checks passed.`

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the output](#1--predict-the-output) | predict | warm-up |
| 2 | [Fix the build](#2--fix-the-build) | fix | warm-up |
| 3 | [Minus and times](#3--minus-and-times) | complete | core |
| 4 | [Late bus](#4--late-bus) | fix | core |
| 5 | [Study time](#5--study-time) | write | core |
| 6 | [Study week](#6--study-week) | write | stretch |

## 1 · Predict the output

Folder: [`01-predict-the-output`](01-predict-the-output/). Check: `ex-08-01`.

Read [`program.cpp`](01-predict-the-output/program.cpp) **without running it**. Type the
output you expect into `prediction.txt`, line for line. Then run the check.

<details>
<summary>Hint</summary>

Ask two questions about each operator. Does it change the object? Does it return the
object itself or a copy? `(malika += 2)` is whatever `operator+=` returns.
</details>

## 2 · Fix the build

Folder: [`02-fix-the-build`](02-fix-the-build/). Check: `ex-08-02`.

[`exercise.cpp`](02-fix-the-build/exercise.cpp) has four mistakes, and each of them stops
the build. Fix the first problem that the build reports, and build again. Do not change
`main`. In the end the program prints:

```text
One bag: 2 kg 250 g
Four bags: 9 kg 0 g
```

<details>
<summary>Hint</summary>

Each mistake answers one of these questions wrongly:

- May a function outside the class use private data?
  ([Stream operators](../04-stream-operators/README.md))
- Does `+` promise to leave its object unchanged, so that it works on a const object?
  ([Operators are functions](../01-operators-are-functions/README.md))
- Which operand stands on the left of `*`?
  ([Arithmetic operators](../02-arithmetic-operators/README.md))
- What does `operator<<` return, so that the next `<<` works?
</details>

## 3 · Minus and times

Folder: [`03-minus-and-times`](03-minus-and-times/). Check: `ex-08-03`.

The `Money` class in [`exercise.cpp`](03-minus-and-times/exercise.cpp) has `+=` and `+`.
Five more operators are there, but they do nothing yet. Complete them at the `TODO` marks.

| Operator | What it must do |
|----------|-----------------|
| `a -= b` | subtract `b` from `a` itself, and return `a` |
| `a *= 3` | make `a` itself three times as large, and return `a` |
| `a - b` | return a new `Money`; `a` and `b` do not change |
| `a * 3` and `3 * a` | return a new `Money`; `a` does not change |

| Expression | Result |
|------------|--------|
| `Money(20000, 0) - Money(16001, 25)` | `Money(3998, 75)` |
| `2 * Money(12500, 50)` | `Money(25001, 0)` |

<details>
<summary>Hint</summary>

`+=` and `+` in the file show the pattern: the member changes the object, and the
non-member copies its first operand and uses the member on the copy. For `3 * a`, call
the function you have just written: `return m * count;`.
</details>

## 4 · Late bus

Folder: [`04-late-bus`](04-late-bus/). Check: `ex-08-04`.

[`exercise.cpp`](04-late-bus/exercise.cpp) builds without a warning, but three of its
operators do the wrong thing. Find them and fix them. Do not change `main`. The program
must print:

```text
The buses leave at 6:30 and 7:15.
At 6:50 you still catch the second bus.
One minute later: 6:50 -> 6:51
```

<details>
<summary>Hint</summary>

Run the program and compare it with the three lines above. Each line shows one bug.

1. May `first + 45` change `first`? ([Arithmetic operators](../02-arithmetic-operators/README.md))
2. Which member must `<` look at first? ([Comparison operators](../03-comparison-operators/README.md))
3. Which value does `now++` give back? ([Index and increment](../05-index-and-increment/README.md))
</details>

## 5 · Study time

Folder: [`05-study-time`](05-study-time/). Check: `ex-08-05`.

Aziz writes down how long he studies: one line for each session, with the hours and the
minutes. Write a program that reads sessions until the input ends. Then it prints the
total time and the longest session.

Write a class `Duration` for this. It stores one number, the minutes, and has:

| Part | What it does |
|------|--------------|
| `Duration(int hours, int minutes)` | the constructor |
| `operator+=` | adds another `Duration` to this one |
| `operator==` and `operator<=>` | compare two durations; let the compiler write them |
| `operator<<` | prints a duration like this: `2 h 5 min` |
| `operator>>` | reads two numbers: the hours, then the minutes |

The user types:

```text
1 20
0 45
2 10
```

Your program prints:

```text
Total: 4 h 15 min
Longest: 2 h 10 min
```

The minutes can be 60 or more: `1 80` is the same duration as `2 20`.

<details>
<summary>Hint</summary>

Start `total` and `longest` as `Duration(0, 0)`. The loop is
`while (std::cin >> session)`: your `operator>>` returns the stream, and the stream is the
condition. [Stream operators](../04-stream-operators/README.md) has an `operator>>` for
`Money` that you can use as a model.
</details>

## 6 · Study week

Folder: [`06-study-week`](06-study-week/). Check: `ex-08-06`.

Now each line starts with the day: `1` for Monday up to `7` for Sunday. The hours and the
minutes follow. Several lines can name the same day. Skip a line with any other day number.

Copy your `Duration` from exercise 5 into
[`exercise.cpp`](06-study-week/exercise.cpp), and add:

| Part | What it does |
|------|--------------|
| class `Week` | holds seven `Duration`s; each starts as `0 h 0 min` |
| `operator[]` of `Week`, in two versions | `week[0]` is the time of Monday, `week[6]` the time of Sunday |
| `Duration total(const Week& week)` | a function that returns the sum of the seven days |

Print the seven days, the total, and the day with the longest time. If two days have the
same time, print the earlier one.

The user types:

```text
1 1 20
3 2 0
1 0 45
9 5 0
6 3 30
```

Your program prints:

```text
Mon: 2 h 5 min
Tue: 0 h 0 min
Wed: 2 h 0 min
Thu: 0 h 0 min
Fri: 0 h 0 min
Sat: 3 h 30 min
Sun: 0 h 0 min
Total: 7 h 35 min
Longest day: Sat
```

<details>
<summary>Hint</summary>

Keep the seven durations in a `std::vector<Duration>` member. The constructor
`Week() : days_(7, Duration(0, 0)) {}` fills it with seven empty days. Read with
`while (std::cin >> day >> time)`: first an `int`, then a `Duration`. Day 1 belongs in
`week[0]`. `total` gets a const `Week`, so it needs the `const` version of `operator[]`.
</details>

**Next chapter:** [09 · Pointers and memory](../../09-pointers-and-memory/README.md)
