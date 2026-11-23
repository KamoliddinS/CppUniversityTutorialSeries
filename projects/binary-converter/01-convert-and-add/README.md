# Binary converter: Convert and add

> **Goal:** convert numbers between decimal and binary, and add binary numbers, with your own loops over the digits.

## You need

- Chapter [05 · Vectors and strings](../../../05-vectors-and-strings/README.md).
- The appendix page [Number systems and bits](../../../appendix/number-systems-and-bits/README.md).
- The starter [`exercise.cpp`](exercise.cpp). It knows one command: `quit`.

## What to build

| Command | What it does | Example | What it prints |
|---------|--------------|---------|----------------|
| `to-binary <number>` | writes a decimal number in binary | `to-binary 10` | `1010` |
| `to-decimal <binary>` | writes a binary number in decimal | `to-decimal 1010` | `10` |
| `add <binary> <binary>` | adds two binary numbers | `add 1010 11` | `1101` |
| `quit` | ends the program | `quit` | nothing |

When a line cannot be carried out, the program prints one error line and goes on:

| The problem | What it prints |
|-------------|----------------|
| the first word is not a command | `error: unknown command to-hex` |
| `<number>` has a character that is not a digit | `error: 12a is not a decimal number` |
| `<binary>` has a character that is not `0` or `1` | `error: 102 is not a binary number` |
| `<number>` has more than 9 digits, or the `<binary>` of `to-decimal` has more than 31 | `error: 12345678901 is too long` |

## Sample session

Test case 1 types these commands:

**`tests/1.in`**
<!-- file: tests/1.in -->
```text
to-binary 10
to-binary 0
to-binary 255
to-decimal 1010
to-decimal 11111111
add 1010 11
add 1111 1
to-binary 12a
to-binary 12345678901
to-decimal 102
add 101 2
to-hex 255
quit
```

A correct program prints exactly this:

**`tests/1.out`**
<!-- file: tests/1.out -->
```text
1010
0
11111111
10
255
1101
10000
error: 12a is not a decimal number
error: 12345678901 is too long
error: 102 is not a binary number
error: 2 is not a binary number
error: unknown command to-hex
```

Run all five test cases with
`ctest --test-dir build -R ex-binary-converter-01 --output-on-failure`
([How to check a step](../../gradebook/README.md#how-to-check-a-step)).

## Rules

- Print results only: no questions and no greeting. The program reads commands until
  `quit`, or until the input ends.
- Read every number as text, in a `std::string`, and check its characters before you
  convert it. So `-5` and `3.5` are not decimal numbers here: `-` and `.` are not digits.
- Write the conversions yourself, with loops. Do not use `std::bitset`, and do not use
  `std::stoi` with a base.
- The two limits keep every value inside an `int`. A number with 9 digits always fits.
  On most systems the largest `int` is 2 147 483 647: 31 ones in binary.
- `add` has no limit. The tests add numbers with up to 75 digits: too many even for a
  `long long`, which has 64 bits. Add the digits of the two texts, as you do on paper.
- The tests promise three things. Every command has all its arguments. A line has at most
  one mistake. No number starts with a `0` that is not needed.

## Marking

| Criterion | Points |
|-----------|--------|
| The five test cases pass (12 points each) | 60 |
| Your own algorithms: `to-binary`, `to-decimal` and `add` are loops over digits that you wrote, each in a function of its own | 20 |
| Code quality: one function for each job, clear names, no repeated blocks, no warnings from `-Wall -Wextra` | 20 |

## Hints

<details>
<summary>Reading and checking</summary>

- Read the command and its numbers with `std::cin >> word`. After every command, throw
  away the rest of the line
  ([Safe input](../../../03-control-flow/07-safe-input/README.md)).
- Write one function that says whether a text is a decimal number, and one for binary.
  [Characters](../../../05-vectors-and-strings/05-characters/README.md) shows how to test
  a `char`, and that `c - '0'` turns the character `'7'` into the number 7.
</details>

<details>
<summary>The three calculations</summary>

- `to-binary`: divide by 2 until you reach 0. The remainders are the digits, from right to
  left: each new one goes in front, and `std::to_string(number % 2)` is it as text. The
  appendix page does it by hand. The number 0 needs an `if` of its own, because the loop
  does not run for it.
- `to-decimal`: go through the digits from the left. For each one:
  `value = value * 2 + digit`.
- `add`: start at the right end of both texts. One column is the carry, plus a digit of
  the first number if one is left, plus a digit of the second. Put `column % 2` in front
  of the result, and carry `column / 2`. Stop when both texts are used up and the carry
  is 0.
- `add 1 111` and `add 111 1` both print `1000`: the texts can have different lengths.
</details>

**Back to:** [Projects](../../README.md)
