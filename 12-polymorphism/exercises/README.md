# Exercises · Polymorphism

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-12-02 --output-on-failure
```

Run the first command once. The second one checks exercise 2 of chapter 12.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. You can also build and run the file yourself and
compare with the example.

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the output](#1--predict-the-output) | predict | warm-up |
| 2 | [Ticket prices](#2--ticket-prices) | fix | warm-up |
| 3 | [More shapes](#3--more-shapes) | complete | core |
| 4 | [Party guests](#4--party-guests) | fix | core |
| 5 | [Payroll](#5--payroll) | write | stretch |

## 1 · Predict the output

Folder: [`01-predict-the-output`](01-predict-the-output/). Check: `ex-12-01`.

Read [`program.cpp`](01-predict-the-output/program.cpp) **without running it**. Type the
output you expect into `prediction.txt`, line for line. Then run the check.

<details>
<summary>Hint</summary>

Ask two questions for every call. Is the function virtual? Is the call made through a pointer
or a reference, or on a copy?
</details>

## 2 · Ticket prices

Folder: [`02-ticket-prices`](02-ticket-prices/). Check: `ex-12-02`.

A museum sells three kinds of ticket. [`exercise.cpp`](02-ticket-prices/exercise.cpp) builds,
but two of the three lines it prints are wrong. In each derived class, one function does not
replace the function of `Ticket` that it should replace. Fix both, so that the program prints:

```text
Full ticket: 20000 so'm
Student ticket: 10000 so'm
Child ticket: 5000 so'm
```

<details>
<summary>Hint</summary>

Write `override` on all four functions of the derived classes and build again. The compiler
names the two functions that override nothing. Compare each one, letter by letter, with the
function in `Ticket`.
</details>

## 3 · More shapes

Folder: [`03-more-shapes`](03-more-shapes/). Check: `ex-12-03`.

[`exercise.cpp`](03-more-shapes/exercise.cpp) has an abstract class `Shape` and one class
that derives from it, `Rectangle`. Follow the four `TODO` comments: write `Square` and
`Triangle`, add one of each to the vector, then print every shape and the total area in one
loop. Do not change `Shape`, `Rectangle` or `print`.

```text
Rectangle: 6
Square: 16
Triangle: 7.5
Total area: 29.5
```

<details>
<summary>Hint</summary>

Use `Rectangle` as the pattern: a constructor, `name()` and `area()` with `override`, and
private data. The loop is the one in
[Polymorphic collections](../05-polymorphic-collections/README.md).
</details>

## 4 · Party guests

Folder: [`04-party-guests`](04-party-guests/). Check: `ex-12-04`.

In [`exercise.cpp`](04-party-guests/exercise.cpp) every guest says hello, and leaves when the
party is over. Malika is a musician: she says "Salom", and she packs her dutar before she
leaves. The program builds without a warning, but a run usually prints this:

```text
Aziz says Hello
Aziz leaves
Malika says Hello
Malika leaves
The party is over
Malika leaves
Aziz leaves
```

Change two lines of the program, so that it prints this instead:

```text
Aziz says Hello
Malika says Salom
The party is over
Malika packs the dutar
Malika leaves
Aziz leaves
```

Do not add or remove any `std::cout`.

<details>
<summary>Hint</summary>

Two guests "leave" in the middle of the party. Which objects are destroyed there, and where
do they come from? Then look at the end: through which type of pointer is the musician
deleted? See [Virtual destructors](../03-virtual-destructors/README.md).
</details>

## 5 · Payroll

Folder: [`05-payroll`](05-payroll/). Check: `ex-12-05`.

A school pays its teachers a fixed salary and its assistants by the hour. Write a program
that reads employees until the input ends. Every line is one of these two:

```text
teacher NAME SALARY
assistant NAME HOURS RATE
```

A name is one word. The numbers are whole numbers; salary and rate are in so'm. An assistant
earns `HOURS * RATE`. Print one line for each employee, in the order of the input, and then
the total. Do not print questions.

The user types:

```text
teacher Malika 9000000
assistant Jasur 60 40000
teacher Aziz 8500000
```

Your program prints:

```text
Malika (teacher): 9000000 so'm
Jasur (assistant): 2400000 so'm
Aziz (teacher): 8500000 so'm
Total: 19900000 so'm
```

Build it like this:

1. An abstract class `Employee` with the name, a virtual destructor and two pure virtual
   functions: `role()` gives `"teacher"` or `"assistant"`, and `pay()` gives the pay in so'm.
2. Two classes that derive from it: `Teacher` and `Assistant`.
3. One `std::vector<std::unique_ptr<Employee>>` that holds every employee.
4. One loop that prints every employee through a function that takes a `const Employee&`.

With no input at all, the program prints only `Total: 0 so'm`.

<details>
<summary>Hint</summary>

Read the first two words of a line with `while (std::cin >> kind >> name)`. Inside the loop,
read the numbers that belong to this kind, then `push_back` a `std::make_unique<Teacher>(...)`
or a `std::make_unique<Assistant>(...)`.
</details>

**Next chapter:** [13 · Exceptions](../../13-exceptions/README.md)
