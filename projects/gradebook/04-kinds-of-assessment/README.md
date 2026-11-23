# Gradebook, step 4: Kinds of assessment

> **Goal:** store scores of different kinds as objects of different classes, and let virtual functions calculate a weighted final grade.

## You need

- Chapters [10 · Resource management](../../../10-resource-management/README.md),
  [11 · Inheritance](../../../11-inheritance/README.md) and
  [12 · Polymorphism](../../../12-polymorphism/README.md).
- Your program from [step 3](../03-a-gradebook-class/README.md). Copy `main.cpp`,
  `gradebook.h` and `gradebook.cpp` into the folder [`starter`](starter/) of this step.
  Do not copy the `.txt` files: this step has its own.

## What to build

A score now belongs to an assessment: a piece of work that gets a score. There are three
kinds. Each kind has a weight: the number of times its score counts in the final grade.

| Kind | Added with | Weight |
|------|------------|--------|
| homework | `add` and `add-score`, as before | 1 |
| project | `add-project` | 2 |
| exam | `add-exam` | 3 |

| Command | What it does | What it prints |
|---------|--------------|----------------|
| `add-project <name> <score>` | gives a student a project score | nothing |
| `add-exam <name> <score>` | gives a student an exam score | nothing |
| `final-grade <name>` | calculates the weighted average of a student | `Aziz: 70.00` |

For a student with homework 80 and 90, project 70 and exam 60:

```text
80*1 + 90*1 + 70*2 + 60*3     490
-------------------------  =  ---  =  70.00
    1  +  1  +  2  +  3        7
```

Everything else stays as it was. `list`, `show`, `report`, `average` and `best` do not look
at the kind: for them every score counts once. The new commands print the error lines you
know: `unknown student`, `usage` and the line for a score outside 0 to 100.

### The file

`save` now writes the kind in front of every score, as in this file:

**`starter/group-b.txt`**
<!-- file: starter/group-b.txt -->
```text
Laziz homework 70 homework 80 project 90 exam 60
Nodira exam 95 project 85 homework 75
Jasur homework 100
```

### The base class

It is written for you:

**`starter/assessment.h`**
<!-- file: starter/assessment.h -->
```cpp
// Gradebook, step 4: Kinds of assessment
#ifndef ASSESSMENT_H
#define ASSESSMENT_H

#include <memory>
#include <string>

// One score of a student. The derived classes say what kind of work the score is for
// and how much it counts.
class Assessment {
public:
    explicit Assessment(int score);
    virtual ~Assessment() = default;

    int score() const;
    virtual std::string kind() const = 0;   // the word used in commands and files
    virtual int weight() const = 0;         // how many times the score counts in the final grade

private:
    int score_ = 0;
};

// TODO: the classes Homework, Project and Exam. Each one is derived from Assessment.

// Creates an assessment of the kind with this name. Returns nullptr for any other word.
std::unique_ptr<Assessment> makeAssessment(const std::string& kind, int score);

#endif
```

## Sample session

Test case 1 types these commands:

**`tests/1.in`**
<!-- file: tests/1.in -->
```text
add Aziz 80
add-score Aziz 90
add-project Aziz 70
add-exam Aziz 60
list
report
final-grade Aziz
add Malika 100
add-exam Malika 50
final-grade Malika
final-grade Jasur
add-exam Jasur 80
add-exam Aziz 120
add-project Malika
quit
```

A correct program prints exactly this:

**`tests/1.out`**
<!-- file: tests/1.out -->
```text
Aziz: 80 90 70 60
Name        Scores  Average
Aziz             4    75.00
Aziz: 70.00
Malika: 62.50
error: unknown student Jasur
error: unknown student Jasur
error: the score must be from 0 to 100
error: usage: add-project <name> <score>
```

Run all nine test cases with `ctest --test-dir build -R ex-gradebook-04 --output-on-failure`
([How to check a step](../README.md#how-to-check-a-step)).

## Rules

- Write the classes `Homework`, `Project` and `Exam`. Each is derived from `Assessment`
  and overrides `kind()` and `weight()`.
- A student owns its assessments in a `std::vector<std::unique_ptr<Assessment>>`.
  The program has no `new` and no `delete`.
- The final grade asks every assessment for its `weight()`. That calculation has no `if`
  on the kind.
- Only `makeAssessment` turns a word such as `exam` into an object. `load` uses it.
- The tests promise two things. The files are correct. A line has at most one mistake.

## Marking

| Criterion | Points |
|-----------|--------|
| The nine test cases pass (shared equally) | 50 |
| Polymorphism: three classes derived from the abstract `Assessment`, with `override`; the final grade is calculated through virtual calls only | 20 |
| Ownership: `std::unique_ptr` in a vector, no `new` and no `delete`, no leak reported by the sanitizers | 10 |
| Code quality: short functions, `const` where nothing changes, clear names, no warnings from `-Wall -Wextra` | 20 |

## Hints

<details>
<summary>Where to start</summary>

- In `Student`, replace `std::vector<int> scores` by the vector of
  `std::unique_ptr<Assessment>`, and store every score as a `Homework`.
- Change `save` and `load` to the new file format. `group-a.txt` of this step holds the
  same students as before, all with homework.
- Now make test cases 4 to 8 pass: they come from steps 1 to 3. Then add the two new kinds.
</details>

<details>
<summary>Objects and ownership</summary>

- A `Student` with a `std::unique_ptr` inside cannot be copied. Move it into the vector:
  `students_.push_back(std::move(student));`. Loop with `const Student&`
  ([unique_ptr](../../../10-resource-management/05-unique-ptr/README.md)).
- A function with a parameter `std::unique_ptr<Assessment> assessment` takes the object
  over. Call it with `std::make_unique<Exam>(score)` or with the result of `makeAssessment`.
- `makeAssessment` returns `nullptr` for a word that is not a kind. Test for that before you
  store the pointer.
- In a loop over the assessments, `assessment->weight()` runs the function of the real
  class ([Polymorphic collections](../../../12-polymorphism/05-polymorphic-collections/README.md)).
</details>

**Next step:** [Errors and the standard library](../05-errors-and-library/README.md)
