# Exercises · Rust for C++ programmers

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

These exercises are not part of the `ctest` checks of the C++ chapters. Each `exercise.rs`
ends with tests: functions marked `#[test]` that call your code and compare the result
with `assert_eq!`. Open a terminal in the folder of the exercise, then build the tests and
run them:

```sh
rustc --edition 2024 --test exercise.rs -o check
./check
```

- `test result: ok` means that every test passed.
- A failed test shows `left`, what your code returned, and `right`, what was expected.
- On Windows PowerShell, run `.\check.exe`.
- Without `--test` you get the program itself: `rustc --edition 2024 exercise.rs`, then
  `./exercise`.
- The starters of exercises 4 and 5 build with warnings such as `unused variable`. Each
  warning points at a function that is not written yet.

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the output](#1--predict-the-output) | predict | warm-up |
| 2 | [Make it compile](#2--make-it-compile) | fix | warm-up |
| 3 | [Canteen order](#3--canteen-order) | complete | core |
| 4 | [Sum the numbers](#4--sum-the-numbers) | write | core |
| 5 | [Stock report](#5--stock-report) | write | stretch |

## 1 · Predict the output

Folder: [`01-predict-the-output`](01-predict-the-output/).

Read [`program.rs`](01-predict-the-output/program.rs) **without running it**. Type the
output you expect into `prediction.txt`, line for line. Then build the program, run it and
compare:

```sh
rustc --edition 2024 program.rs
./program
```

<details>
<summary>Hint</summary>

A value is dropped when its owner goes out of scope. Who owns Aziz after `greet(aziz)`?
</details>

## 2 · Make it compile

Folder: [`02-make-it-compile`](02-make-it-compile/).

[`exercise.rs`](02-make-it-compile/exercise.rs) does not compile. It has three mistakes: one
in `label`, one in `total` and one in `repeat_first`. Build it, fix the first error the
compiler reports, and build again. Do not change the tests, and keep the parameter types of
these three functions. The finished program prints:

```text
Dilnoza (7 letters)
repeated: 4000
total: 17000
```

<details>
<summary>Hint</summary>

Read the `help:` and `note:` parts of each message. In `label`: the function `letters` does
not need to own the name. In `repeat_first`: a `u32` is `Copy`, so you can keep the number
instead of a reference to it.
</details>

## 3 · Canteen order

Folder: [`03-canteen-order`](03-canteen-order/).

Complete the three `TODO` parts of [`exercise.rs`](03-canteen-order/exercise.rs): the two
missing arms in `label`, and the methods `total` and `highest_price`. The finished program
prints:

```text
bread: 4000 so'm
tea (sugar: 2): 4000 so'm
plov (portions: 3): 105000 so'm
total: 113000 so'm
highest price: 105000 so'm
```

<details>
<summary>Hint</summary>

The function `price` shows how an arm takes the number out of a variant.
`format!("tea (sugar: {sugar})")` builds a `String` the way `println!` prints one. For the
two methods, loop over `&self.dishes` and call `price`, or use `.iter().map(...)` with
`.sum()` and `.max()`.
</details>

## 4 · Sum the numbers

Folder: [`04-sum-the-numbers`](04-sum-the-numbers/).

Write the bodies of the three functions in [`exercise.rs`](04-sum-the-numbers/exercise.rs).
Each one gets a list of words as a `&[&str]`: a slice of borrowed texts.

| Function | For `["12", "x", "30", "7.5"]` | For `["12", "30"]` |
|----------|--------------------------------|--------------------|
| `sum_all` | the `Err` that `"x"` gives | `Ok(42)` |
| `sum_valid` | `42` | `42` |
| `first_bad` | `Some(1)` | `None` |

<details>
<summary>Hint</summary>

`word.parse::<i32>()` gives a `Result`. In `sum_all`, `?` passes the error on. In
`sum_valid`, `unwrap_or(0)` turns a bad word into `0`. In `first_bad`, loop with
`for position in 0..words.len()`. As in C++, `return Some(position);` leaves the function
at once.
</details>

## 5 · Stock report

Folder: [`05-stock-report`](05-stock-report/).

A shop keeps its stock as lines such as `bread 4000 12`: the name, the price of one piece
and the number of pieces. Write the six bodies marked `todo!()` in
[`exercise.rs`](05-stock-report/exercise.rs). The comment above each one says what it must
do. The finished program prints:

```text
skipped "tea 3000 many": BadNumber("many")
bread: 12 x 4000 so'm
plov: 4 x 35000 so'm
stock value: 188000 so'm
most expensive: plov
```

<details>
<summary>Hint</summary>

Work from top to bottom, and run the tests after each function. `number` is a `match` on
`text.parse::<u32>()`. In `parse_item`, check `words.len()` first. Then `words[0]` is the
name as a `&str`, and `String::from` makes the `String` that an `Item` owns. Functions 4
and 5 are one iterator chain each: `map`, then `collect` or `sum`. In `most_expensive`,
keep the best item so far in an `Option<&Item>` that starts as `None`.
</details>

This is the last chapter. Back to the [course overview](../../README.md).
