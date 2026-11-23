# Exercises · Values and types

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
ctest --test-dir build -R ex-02-03 --output-on-failure
```

This checks exercise 3 of chapter 02.

`Passed` means your program printed exactly the expected text. If there is no `build` folder
yet, run `cmake -B build` once.

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the output](#1--predict-the-output) | predict | warm-up |
| 2 | [Hours, minutes, seconds](#2--hours-minutes-seconds) | complete | warm-up |
| 3 | [Wrong percentage](#3--wrong-percentage) | fix | core |
| 4 | [Email address](#4--email-address) | write | core |
| 5 | [Market receipt](#5--market-receipt) | write | stretch |

## 1 · Predict the output

Folder: [`01-predict-the-output`](01-predict-the-output/). Check: `ex-02-01`.

Read [`program.cpp`](01-predict-the-output/program.cpp) **without running it**. Type the
output you expect into `prediction.txt`, line for line. Then run the check.

<details>
<summary>Hint</summary>

Look at the types on both sides of every `/`. Two whole numbers give a whole number.
</details>

## 2 · Hours, minutes, seconds

Folder: [`02-hours-minutes-seconds`](02-hours-minutes-seconds/). Check: `ex-02-02`.

[`exercise.cpp`](02-hours-minutes-seconds/exercise.cpp) reads a number of seconds and prints
it as hours, minutes and seconds. The hours are already right. Complete the two `TODO` lines.

| The user types | Your program prints |
|----------------|---------------------|
| `3725` | `3725 s = 1 h 2 min 5 s` |

<details>
<summary>Hint</summary>

`total % secondsPerHour` is the number of seconds left after the full hours. How many full
minutes fit into them?
</details>

## 3 · Wrong percentage

Folder: [`03-wrong-percentage`](03-wrong-percentage/). Check: `ex-02-03`.

[`exercise.cpp`](03-wrong-percentage/exercise.cpp) reads how many answers were correct and
how many questions a test had. It should print the result in percent. It builds and runs,
but it prints `0%` for almost every input. Find out why and fix it.

| The user types | Your program prints |
|----------------|---------------------|
| `7 8` | `7 of 8 is 87.5%` |

<details>
<summary>Hint</summary>

What is `7 / 8` when both numbers are `int`? See [Conversions](../05-conversions/README.md).
</details>

## 4 · Email address

Folder: [`04-email-address`](04-email-address/). Check: `ex-02-04`.

Read a first name and a last name, one word each. Print the email address
`first.last@example.com`, and on the next line the number of characters in it.
Do not print questions.

| The user types | Your program prints |
|----------------|---------------------|
| `malika karimova` | `malika.karimova@example.com`, then `27 characters` |

<details>
<summary>Hint</summary>

Build the whole address in one `std::string` with `+`. Then `.size()` gives its length.
</details>

## 5 · Market receipt

Folder: [`05-market-receipt`](05-market-receipt/). Check: `ex-02-05`.

At the market you buy one product by weight. Read the name of the product (a whole line),
the price of one kilogram in so'm, and the weight in grams. Print four lines:

1. the name, a comma, and the weight in kilograms;
2. `Cost`: price × grams / 1000;
3. `Discount`: 10 percent of the cost;
4. `To pay`: the cost minus the discount, rounded down to a full 100 so'm.

The user types:

```text
Namangan apples
18000
2750
```

Your program prints:

```text
Namangan apples, 2.75 kg
Cost: 49500 so'm
Discount: 4950 so'm
To pay: 44500 so'm
```

Every amount of money is a whole number. In the tests, price × grams stays below two
billion. Give the fixed numbers 1000, 10 and 100 names.

<details>
<summary>Hint</summary>

- Keep the money in `int` variables. A `double` prints a large amount as `1.125e+06`.
- Multiply first, then divide. `grams / 1000 * price` loses the grams above a full kilogram.
- Only the kilograms need a `double`. Convert before you divide.
- `amount % 100` is the part above the last full hundred.
</details>

**Next chapter:** [03 · Control flow](../../03-control-flow/README.md)
