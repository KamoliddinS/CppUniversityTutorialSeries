# Gradebook, step 5: Errors and the standard library

> **Goal:** report every error with an exception, find students with a `std::map`, and let algorithms sort and filter.

## You need

- Chapters [13 · Exceptions](../../../13-exceptions/README.md),
  [14 · Templates](../../../14-templates/README.md) and
  [15 · The standard library](../../../15-standard-library/README.md).
- Your program from [step 4](../04-kinds-of-assessment/README.md). Copy its five `.cpp`
  and `.h` files into the folder [`starter`](starter/) of this step. Do not copy the
  `.txt` files.

## What to build

Three commands print the table of `report` with other rows or in another order. They do
not change the gradebook.

| Command | What it prints |
|---------|----------------|
| `sort-by <key>` | the whole table, sorted. The key `name` sorts from A to Z, the key `average` puts the highest average first |
| `top <n>` | the table with the `n` highest averages, the highest first |
| `below <limit>` | the table with the students whose average is below the limit |

| The problem | What it prints |
|-------------|----------------|
| the key is not `name` or `average`; `n` is not a whole number from 1 up; the limit is not a number; an argument is missing | `error: usage: ` and the command, for example `error: usage: top <n>` |
| one of the three commands, and there are no students | `error: no students` |
| `load`, and a line of the file breaks a rule: a kind that is not `homework`, `project` or `exam`, a score outside 0 to 100, a name for the second time | `error: bad data in bad-kind.txt` |

After `error: bad data ...` the gradebook is as it was before the `load`.

Inside the program three things change. The tests cannot see them, but the marking does:

| Part | What changes |
|------|--------------|
| Errors | Write a class `GradebookError`, derived from `std::runtime_error`. A function that cannot do its work throws one, with the text that follows `error: `. `main` catches it in one place and prints the error line. No function returns `false` for a failure any more. |
| Lookup | Find a student by name in a `std::map`, not with a loop. |
| Sorting and filtering | Use algorithms with lambdas, such as `std::sort` and `std::erase_if`. Write no sorting loop of your own. |

## Sample session

Test case 1 types these commands:

**`tests/1.in`**
<!-- file: tests/1.in -->
```text
load group-b.txt
add Aziz 88
add-exam Aziz 91
report
sort-by average
sort-by name
top 2
below 80
below 50
load bad-kind.txt
count
top zero
sort-by score
quit
```

A correct program prints exactly this:

**`tests/1.out`**
<!-- file: tests/1.out -->
```text
Name        Scores  Average
Laziz            4    75.00
Nodira           3    85.00
Jasur            1   100.00
Aziz             2    89.50
Name        Scores  Average
Jasur            1   100.00
Aziz             2    89.50
Nodira           3    85.00
Laziz            4    75.00
Name        Scores  Average
Aziz             2    89.50
Jasur            1   100.00
Laziz            4    75.00
Nodira           3    85.00
Name        Scores  Average
Jasur            1   100.00
Aziz             2    89.50
Name        Scores  Average
Laziz            4    75.00
Name        Scores  Average
error: bad data in bad-kind.txt
students: 4
error: usage: top <n>
error: usage: sort-by <key>
```

Run all eleven test cases with `ctest --test-dir build -R ex-gradebook-05 --output-on-failure`
([How to check a step](../README.md#how-to-check-a-step)).

## Rules

- Students with the same average stay in the order in which they were added.
- `top <n>` with more than the number of students prints them all.
- `below <limit>` keeps the order in which the students were added. The limit may be a
  decimal number, as in `below 59.5`. When nobody is below it, only the first line of the
  table is printed.
- A command that fails prints the error line and nothing else.
- The tests promise that a line has at most one mistake.

## Marking

| Criterion | Points |
|-----------|--------|
| The eleven test cases pass (shared equally) | 50 |
| Errors: every error is a `GradebookError`, thrown where the problem is found and printed by one `catch` in `main`; a `load` that fails changes nothing | 20 |
| Library: lookup by name with `std::map`; sorting and filtering with algorithms and lambdas | 10 |
| Code quality: short functions, `const` where nothing changes, clear names, no warnings from `-Wall -Wextra` | 20 |

## Hints

<details>
<summary>Exceptions</summary>

- Start with the errors. Turn one function at a time from "returns `false`" into "throws",
  and run test cases 4 to 9 after each change: they come from steps 1 to 4.
- Get the value first, then print it. In `std::cout << "average: " << book.classAverage()`
  the text `average: ` is already printed when `classAverage()` throws.
- A constructor cannot return `false`, but it can throw. Check the score in the
  constructor of `Assessment`, and no wrong score can exist anywhere
  ([Your own exceptions](../../../13-exceptions/04-your-own-exceptions/README.md)).
- For `load`, read the file into a second `Gradebook`. When every line is in, replace the
  real one: `*this = std::move(loaded);`. If a line throws, the second gradebook is
  destroyed and the real one was never touched
  ([Stack unwinding](../../../13-exceptions/03-stack-unwinding/README.md)).
- `load` may catch a `GradebookError` and throw a new one with the text `bad data in ...`.
</details>

<details>
<summary>The standard library</summary>

- Keep the vector of students. Add a `std::map<std::string, std::size_t>` that gives the
  index of each name in the vector
  ([Maps and sets](../../../15-standard-library/02-maps-and-sets/README.md)).
- For the three new commands, first collect one small struct for each student: name,
  number of scores, average. Sort or filter that vector, then print it. `report` can
  print the same vector unsorted.
- `std::stable_sort` is called like `std::sort` from
  [Algorithms](../../../15-standard-library/05-algorithms/README.md). It keeps equal
  elements in their old order.
- One function template can read an argument of any type from the line:
  `readArgument<int>(words, usage)`
  ([Function templates](../../../14-templates/01-function-templates/README.md)).
</details>

**Back to:** [Gradebook](../README.md)
