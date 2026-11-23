# Gradebook, step 2: Structs and files

> **Goal:** give every student several scores, print them as a table, and keep the gradebook in a file.

## You need

- Chapter [06 · Structs and files](../../../06-structs-and-files/README.md).
- Your program from [step 1](../01-scores-in-vectors/README.md). Copy its functions into
  the starter [`exercise.cpp`](exercise.cpp) of this folder.

## What to build

A student can now have several scores. Every command of step 1 still works.

| Command | What it does | What it prints |
|---------|--------------|----------------|
| `add-score <name> <score>` | gives a student one more score | nothing |
| `list` and `show <name>` | as before, with all scores of a student | `Aziz: 85 90 78` |
| `average` | calculates the average of the students' averages | `average: 89.67` |
| `best` | finds the student with the highest average | `best: Malika` |
| `report` | prints a table: name, number of scores, average | see the sample session |
| `save <file>` | writes all students to a text file | nothing |
| `load <file>` | replaces all students by the students in the file | nothing |

| The problem | What it prints |
|-------------|----------------|
| `add-score` gets a name that is not in the gradebook | `error: unknown student Laziz` |
| an argument is missing, or a score is not a number | `error: usage: ` and the command, for example `error: usage: add-score <name> <score>` |
| `save` or `load` cannot open the file | `error: cannot open missing.txt` |
| `report`, and there are no students | `error: no students` |

### The table

In every line of `report` the name is left-aligned in 12 characters, the number of scores
is right-aligned in 6, and the average is right-aligned in 9. The first line has the words
`Name`, `Scores` and `Average` in the same columns.

### The file

`save` writes one line for each student: the name, then the scores, with one space between
them, as in this file:

**`group-a.txt`**
<!-- file: group-a.txt -->
```text
Aziz 85 90 78
Malika 92 98
Jasur 64 70 58 81
Dilnoza 100
```

## Sample session

Test case 1 types these commands:

**`tests/1.in`**
<!-- file: tests/1.in -->
```text
add Aziz 85
add-score Aziz 90
add-score Aziz 78
add Malika 92
add-score Malika 98
list
report
average
best
save autumn.txt
add Jasur 64
count
load autumn.txt
count
add-score Laziz 70
add-score Aziz
load missing.txt
quit
```

A correct program prints exactly this:

**`tests/1.out`**
<!-- file: tests/1.out -->
```text
Aziz: 85 90 78
Malika: 92 98
Name        Scores  Average
Aziz             3    84.33
Malika           2    95.00
average: 89.67
best: Malika
students: 3
students: 2
error: unknown student Laziz
error: usage: add-score <name> <score>
error: cannot open missing.txt
```

Run all seven test cases with `ctest --test-dir build -R ex-gradebook-02 --output-on-failure`
([How to check a step](../README.md#how-to-check-a-step)).

## Rules

- Describe a student with the struct `Student` of the starter: a name and a vector of
  scores. Keep the students in one `std::vector<Student>`.
- A line with a missing argument is wrong on its own: the next line must still be carried
  out. So read a whole line first, then take its words from a `std::istringstream`, as the
  starter does.
- A `load` that cannot open its file changes nothing.
- The tests promise four things. No name is added twice. Every score is from 0 to 100.
  The files are correct. A line has at most one mistake.

## Marking

| Criterion | Points |
|-----------|--------|
| The seven test cases pass (shared equally) | 60 |
| Struct and file: one `Student` struct replaces the two vectors, `save` writes the format of `group-a.txt`, and a saved file loads back to the same gradebook | 20 |
| Code quality: one function for each job, clear names, no repeated blocks, no warnings from `-Wall -Wextra` | 20 |

## Hints

<details>
<summary>Where to start</summary>

- First change your step 1 functions from two vectors to one `std::vector<Student>`.
  Test case 6 is the long session of step 1: make it pass before you add anything new.
- Pass the string stream on to your functions by reference, for example
  `void runAdd(std::vector<Student>& students, std::istringstream& words)`. A stream
  cannot be copied.
- `if (!(words >> name >> score))` is true when an argument is missing and when the score
  is not a number. Both get the usage line.
</details>

<details>
<summary>The table and the file</summary>

- The table needs `std::left`, `std::right` and `std::setw`
  ([Format output](../../../06-structs-and-files/05-format-output/README.md)).
- For `load`, read the file line by line. In each line, read the name, then the scores
  with `while (words >> score)` ([Parse lines](../../../06-structs-and-files/04-parse-lines/README.md)).
- Open the file first. Remove the old students only when that worked.
- Every student has at least one score, so an average never divides by zero.
</details>

**Next step:** [A gradebook class](../03-a-gradebook-class/README.md)
