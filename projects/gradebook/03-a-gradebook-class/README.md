# Gradebook, step 3: A gradebook class

> **Goal:** rebuild the gradebook around a class that protects its data, in a program of three files.

## You need

- Chapters [07 · Classes](../../../07-classes/README.md) and
  [08 · Operator overloading](../../../08-operator-overloading/README.md).
- Your program from [step 2](../02-structs-and-files/README.md).
- The starter in the folder [`starter`](starter/). All `.cpp` files in it are built together.

## What to build

The program prints what it printed in step 2. Two things that it accepted until now are
errors:

| The problem | What it prints |
|-------------|----------------|
| a score below 0 or above 100, in `add` or `add-score` | `error: the score must be from 0 to 100` |
| `add` gets a name that is already in the gradebook | `error: duplicate student Aziz` |

A command that prints an error changes nothing.

The code moves into three files:

| File | What it holds |
|------|---------------|
| [`gradebook.h`](starter/gradebook.h) | the struct `Student` and the class `Gradebook`: written for you |
| [`gradebook.cpp`](starter/gradebook.cpp) | the bodies of their functions: you write them |
| [`main.cpp`](starter/main.cpp) | reads a line, calls a member function, prints the answer or the error line |

**`starter/gradebook.h`**
<!-- file: starter/gradebook.h -->
```cpp
// Gradebook, step 3: A gradebook class
#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    std::vector<int> scores;
};

double average(const Student& student);

// Prints a student as "Aziz: 85 90 78", without a line end.
std::ostream& operator<<(std::ostream& out, const Student& student);

// Keeps the students and protects them. Its rules: a name is in the gradebook only once,
// and every score is from 0 to 100.
class Gradebook {
public:
    // These four return false, and change nothing, when they cannot do their work.
    bool addStudent(const std::string& name, int score);    // the name must be new
    bool addScore(const std::string& name, int score);      // the name must be known
    bool save(const std::string& fileName) const;
    bool load(const std::string& fileName);

    bool hasStudent(const std::string& name) const;
    std::size_t size() const;

    // Call these three only when their question has an answer:
    const Student& student(const std::string& name) const;  // needs a known name
    double classAverage() const;                            // needs at least one student
    std::string bestName() const;                           // needs at least one student

    void printList(std::ostream& out) const;
    void printReport(std::ostream& out) const;

private:
    // Returns the position of the student with this name, or students_.size() if there is none.
    std::size_t find(const std::string& name) const;

    std::vector<Student> students_;
};

#endif
```

## Sample session

Test case 1 types these commands:

**`tests/1.in`**
<!-- file: tests/1.in -->
```text
add Aziz 85
add Malika 92
add Aziz 70
add Jasur 101
add Jasur -1
add-score Malika 150
add-score Aziz 100
add-score Malika 0
list
report
count
```

A correct program prints exactly this:

**`tests/1.out`**
<!-- file: tests/1.out -->
```text
error: duplicate student Aziz
error: the score must be from 0 to 100
error: the score must be from 0 to 100
error: the score must be from 0 to 100
Aziz: 85 100
Malika: 92 0
Name        Scores  Average
Aziz             2    92.50
Malika           2    46.00
students: 2
```

Run all eight test cases with `ctest --test-dir build -R ex-gradebook-03 --output-on-failure`
([How to check a step](../README.md#how-to-check-a-step)).

## Rules

- The data of `Gradebook` is private. No code outside the class can put a wrong score or a
  second `Aziz` into it, and neither can a file that `load` reads.
- `operator<<` prints a student as `Aziz: 85 90 78`. `list` and `show` use it.
- `main.cpp` has no `std::vector` and opens no file. It reads, calls and prints.
- You may add private functions. You may also change the header if your design needs it:
  the tests look only at what the program prints.
- The tests promise two things. The files are correct. A line has at most one mistake.

## Marking

| Criterion | Points |
|-----------|--------|
| The eight test cases pass (shared equally) | 50 |
| The class protects its data: the data is private, and every way into the gradebook checks the name and the score | 20 |
| Three files with clear jobs: `main.cpp` only reads, calls and prints; `operator<<` prints a student | 10 |
| Code quality: short functions, `const` where nothing changes, clear names, no warnings from `-Wall -Wextra` | 20 |

## Hints

<details>
<summary>Where to start</summary>

- Move first, change later. Turn your step 2 functions into the member functions of
  `gradebook.cpp`, and make test cases 2 to 7 pass: they come from steps 1 and 2. Then
  add the two new rules.
- A function that you call but have not written yet gives a linker error:
  `undefined reference to 'Gradebook::addStudent(...)'`
  ([Headers and source files](../../../07-classes/06-headers-and-source-files/README.md)).
- Build by hand inside `starter`: `g++ -std=c++20 -Wall -Wextra *.cpp -o gradebook`.
</details>

<details>
<summary>The class</summary>

- `addStudent` and `addScore` answer only `true` or `false`. To choose the error line,
  `main.cpp` asks `book.hasStudent(name)` afterwards.
- Let `load` add every student with `addStudent` and `addScore`. Then a file cannot break
  the rules.
- The average of the whole class is called `classAverage`, not `average`. A member function
  named `average` would hide the free function `average(student)` inside the class, and the
  call would not compile: `no matching function for call to 'Gradebook::average(const Student&) const'`.
- `operator<<` prints no line end and returns `out`
  ([Stream operators](../../../08-operator-overloading/04-stream-operators/README.md)).
</details>

**Next step:** [Kinds of assessment](../04-kinds-of-assessment/README.md)
