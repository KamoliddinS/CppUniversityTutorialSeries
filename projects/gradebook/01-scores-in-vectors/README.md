# Gradebook, step 1: Scores in vectors

> **Goal:** write a program that keeps names and scores in two vectors and carries out commands on them.

## You need

- Chapters [03 · Control flow](../../../03-control-flow/README.md),
  [04 · Functions](../../../04-functions/README.md) and
  [05 · Vectors and strings](../../../05-vectors-and-strings/README.md).
- The starter [`exercise.cpp`](exercise.cpp). It knows two commands: `count` and `quit`.

## What to build

| Command | What it does | What it prints |
|---------|--------------|----------------|
| `add <name> <score>` | adds a student with one score | nothing |
| `list` | shows all students, in the order they were added | one line for each student: `Aziz: 85` |
| `show <name>` | shows one student | `Aziz: 85` |
| `count` | counts the students | `students: 3` |
| `average` | calculates the average of all scores | `average: 82.33` |
| `best` | finds the student with the highest score | `best: Malika` |
| `quit` | ends the program | nothing |

When a line cannot be carried out, the program prints one error line and goes on:

| The problem | What it prints |
|-------------|----------------|
| the first word is not a command | `error: unknown command remove` |
| the score of `add` is not a number | `error: usage: add <name> <score>` |
| `show` gets a name that is not in the gradebook | `error: unknown student Laziz` |
| `list`, `average` or `best`, and there are no students | `error: no students` |

**Usage** means "this is how to use the command". The text after `usage:` is the command
as the first table shows it.

## Sample session

Test case 1 types these commands:

**`tests/1.in`**
<!-- file: tests/1.in -->
```text
list
add Aziz 85
add Malika 92
add Jasur 70
list
count
average
best
show Malika
show Laziz
add Laziz abc
remove Jasur
quit
```

A correct program prints exactly this:

**`tests/1.out`**
<!-- file: tests/1.out -->
```text
error: no students
Aziz: 85
Malika: 92
Jasur: 70
students: 3
average: 82.33
best: Malika
Malika: 92
error: unknown student Laziz
error: usage: add <name> <score>
error: unknown command remove
```

Run all six test cases with `ctest --test-dir build -R ex-gradebook-01 --output-on-failure`
([How to check a step](../README.md#how-to-check-a-step)).

## Rules

- Keep the names in a `std::vector<std::string>` and the scores in a `std::vector<int>`.
  `scores[i]` is the score of `names[i]`.
- A name is one word. A score is a whole number.
- The average is a decimal number with two digits after the point. The line
  `std::cout << std::fixed << std::setprecision(2);` in the starter does that for the
  whole program. [Chapter 06](../../../06-structs-and-files/README.md) explains it.
- When two students share the highest score, `best` prints the one who was added first.
- One wrong line gives one error line, however many words the line has.
- The tests promise three things. Every command has all its arguments. No name is added
  twice. A score is a number from 0 to 100, or a word such as `abc`.

## Marking

| Criterion | Points |
|-----------|--------|
| The six test cases pass (10 points each) | 60 |
| Two vectors that stay together: both are created in `main` and passed to functions by reference, and they always have the same size | 20 |
| Code quality: one function for each job, clear names, no repeated blocks, no warnings from `-Wall -Wextra` | 20 |

## Hints

<details>
<summary>Reading the commands</summary>

- Read the command with `std::cin >> command`. For `add`, read the name and the score with
  `>>` too.
- When the score cannot be read, `std::cin` is in the failed state. Call `std::cin.clear()`
  first ([Safe input](../../../03-control-flow/07-safe-input/README.md)).
- After every command, throw away the rest of the line with `std::cin.ignore(...)`, as in
  that lesson. Without it, `remove Aziz` gives two errors: one for `remove`, one for `Aziz`.
</details>

<details>
<summary>The calculations</summary>

- Every `names.push_back(...)` needs a `scores.push_back(...)` next to it.
- The average of 85 and 90 is 87.50, not 87.00
  ([Conversions](../../../02-values-and-types/05-conversions/README.md)).
- For `best`, remember the index of the highest score so far. Replace it only when a score
  is higher: `>`, not `>=` ([Loop patterns](../../../03-control-flow/06-loop-patterns/README.md)).
- `show` needs a search: a loop that stops at the first name that matches.
</details>

**Next step:** [Structs and files](../02-structs-and-files/README.md)
