# Exercises · Inheritance

Do them in order. Each exercise has its own folder with a starter file.

## How to check your work

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-11-02 --output-on-failure
```

Run the first command once. The second one checks exercise 2 of chapter 11.

`Passed` means your program printed exactly the expected text. Spaces at the end of a line
do not matter; everything else does. You can also build and run the file yourself and
compare with the example.

| # | Exercise | Kind | Level |
|---|----------|------|-------|
| 1 | [Predict the order](#1--predict-the-order) | predict | warm-up |
| 2 | [Fix the teacher](#2--fix-the-teacher) | fix | warm-up |
| 3 | [Savings account](#3--savings-account) | complete | core |
| 4 | [Which one runs?](#4--which-one-runs) | predict | core |
| 5 | [One person, two names](#5--one-person-two-names) | fix | core |
| 6 | [Manager and team](#6--manager-and-team) | write | stretch |

## 1 · Predict the order

Folder: [`01-predict-the-order`](01-predict-the-order/). Check: `ex-11-01`.

Read [`program.cpp`](01-predict-the-order/program.cpp) **without running it**. A `Bus` is a
`Vehicle` and has an `Engine`. Type the seven lines you expect into `prediction.txt`.
Then run the check.

<details>
<summary>Hint</summary>

Building: the base part, then the members, then the body of the constructor. Destroying:
the reverse. See [Constructors in a hierarchy](../03-constructors-in-a-hierarchy/README.md).
</details>

## 2 · Fix the teacher

Folder: [`02-fix-the-teacher`](02-fix-the-teacher/). Check: `ex-11-02`.

[`exercise.cpp`](02-fix-the-teacher/exercise.cpp) has three mistakes, all of them in the
class `Teacher`. Build it, fix the first error the compiler reports, and build again.
Repeat until the program prints:

```text
Aziz teaches Algorithms
Name: Aziz
```

Change only `Teacher`. Leave `Person` and `main` as they are.

<details>
<summary>Hint</summary>

One word is missing in the first line of the class. The constructor does not say how to
build the `Person` part. And `Teacher` touches a private member of `Person`.
</details>

## 3 · Savings account

Folder: [`03-savings-account`](03-savings-account/). Check: `ex-11-03`.

A `SavingsAccount` is an `Account` with an interest rate. Complete the two functions marked
`TODO` in [`exercise.cpp`](03-savings-account/exercise.cpp):

- `addInterest()` adds `rate_` percent of the balance to the account;
- `print()` prints the line of `Account::print()`, then the rate.

The program reads an owner, a balance and a rate. It prints the account, adds the interest,
and prints the account again. The user types `Dilnoza 2000000 15`. Your program prints:

```text
Dilnoza: 2000000 so'm
  rate: 15%
Dilnoza: 2300000 so'm
  rate: 15%
```

<details>
<summary>Hint</summary>

`balance_` is private in `Account`, so `SavingsAccount` cannot change it directly.
`balance()` reads it and `deposit()` adds to it. Inside `print()`, the name `print` means
the new function: write `Account::print()` to call the original.
</details>

## 4 · Which one runs?

Folder: [`04-which-one-runs`](04-which-one-runs/). Check: `ex-11-04`.

Read [`program.cpp`](04-which-one-runs/program.cpp) **without running it**. Type the seven
lines you expect into `prediction.txt`. Then run the check.

<details>
<summary>Hint</summary>

For every call, look at the type of the variable, reference or pointer in front of the `.`
or the `->`. That type decides. See [Redefine a function](../04-redefine-a-function/README.md).
</details>

## 5 · One person, two names

Folder: [`05-one-person-two-names`](05-one-person-two-names/). Check: `ex-11-05`.

The student office corrects a spelling mistake in the name of a teaching assistant.
[`exercise.cpp`](05-one-person-two-names/exercise.cpp) builds and runs, but the staff card
still shows the old name:

```text
Student 1042: Aziz Karimov
Staff 77: Aziz Karimo
```

Repair the classes so that a `TeachingAssistant` has one name only. Do not change `main`.
The program must print:

```text
Student 1042: Aziz Karimov
Staff 77: Aziz Karimov
```

<details>
<summary>Hint</summary>

How many `Person` parts are inside a `TeachingAssistant`? Three lines must change.
See [Multiple inheritance](../05-multiple-inheritance/README.md).
</details>

## 6 · Manager and team

Folder: [`06-manager-and-team`](06-manager-and-team/). Check: `ex-11-06`.

Write a program for these facts:

- An employee has a name and a salary in so'm.
- A manager **is an** employee.
- A manager **has a** team: a list of employees.

The first line of the input is the manager: a name and a salary. Every following line is one
member of the team. A name is one word. Print the manager, the team, and the sum of all
salaries. Do not print questions.

The user types:

```text
Nodira 9000000
Jasur 5000000
Laziz 4500000
```

Your program prints:

```text
Nodira: 9000000 so'm
Team of 2:
  Jasur: 5000000 so'm
  Laziz: 4500000 so'm
Total: 18500000 so'm
```

Build it like this:

1. A class `Employee` with a function `print()` that prints one line: `NAME: SALARY so'm`.
2. A class `Manager` with its own `print()`. It calls the `print()` of `Employee` for the
   manager's line and for every member of the team.
3. A manager without a team prints `Team of 0:` and no member lines.

<details>
<summary>Hint</summary>

Decide for each fact: inheritance or a member? The team is a `std::vector<Employee>`.
The constructor of `Manager` passes the name and the salary to `Employee`. The salary is
private in `Employee`, so give `Employee` a public function that returns it.
Read the team with `while (std::cin >> name >> salary)`.
</details>

When your program passes: what is lost if you add a `Manager` to the team of another manager?

<details>
<summary>Answer</summary>

The team of the added manager. The vector stores `Employee` objects, so only the `Employee`
part is copied: this is slicing. [Chapter 12](../../12-polymorphism/README.md) shows how one
list can hold objects of different classes.
</details>

**Next chapter:** [12 · Polymorphism](../../12-polymorphism/README.md)
