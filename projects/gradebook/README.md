# Gradebook

One program that grows with the course. It keeps the students of a group and their scores,
and it answers questions about them. You build it in five steps. Each step uses what the
chapters before it taught, and adds to your program of the step before.

## How the program works

The gradebook has no menu and asks no questions. It reads **commands**, one per line, and
prints only results:

| You type | The program prints |
|----------|--------------------|
| `add Aziz 85` | nothing |
| `add Malika 92` | nothing |
| `average` | `average: 88.50` |
| `show Laziz` | `error: unknown student Laziz` |
| `quit` | nothing: the program ends |

These rules hold in every step:

1. The program reads commands until `quit`, or until the input ends.
2. It prints results only: no questions and no greeting. Then its output can be compared
   with the expected output.
3. A line that cannot be carried out prints one line that starts with `error: `, and the
   program goes on with the next line. An empty line prints nothing.
4. A decimal number is printed with two digits after the point: `88.50`.
5. Every command keeps working in all later steps.

## The steps

| Step | Do it after | What it adds |
|------|-------------|--------------|
| 1 · [Scores in vectors](01-scores-in-vectors/README.md) | [05 · Vectors and strings](../../05-vectors-and-strings/README.md) | names and scores in two vectors: `add`, `list`, `show`, `count`, `average`, `best` |
| 2 · [Structs and files](02-structs-and-files/README.md) | [06 · Structs and files](../../06-structs-and-files/README.md) | several scores for each student, a report table, `save` and `load` |
| 3 · [A gradebook class](03-a-gradebook-class/README.md) | [07 · Classes](../../07-classes/README.md) and [08 · Operator overloading](../../08-operator-overloading/README.md) | the same program, built around a class that refuses wrong data |
| 4 · [Kinds of assessment](04-kinds-of-assessment/README.md) | [10 · Resource management](../../10-resource-management/README.md), [11 · Inheritance](../../11-inheritance/README.md) and [12 · Polymorphism](../../12-polymorphism/README.md) | homework, project and exam scores that count differently: `final-grade` |
| 5 · [Errors and the standard library](05-errors-and-library/README.md) | [13 · Exceptions](../../13-exceptions/README.md), [14 · Templates](../../14-templates/README.md) and [15 · The standard library](../../15-standard-library/README.md) | errors as exceptions, lookup with `std::map`: `sort-by`, `top`, `below` |

You carry your own code forward: step 2 starts from your program of step 1, and so on.
If you could not finish a step, ask your teacher. After the deadline of a step the teacher
can hand out its solution, so that everybody can start the next step.

## How to check a step

Every step folder holds a **starter**: the files you begin with. It also holds
**test cases**: `tests/1.in` is what is typed, and `tests/1.out` is exactly what a correct
program prints for it.

From the top folder of the course:

```sh
cmake -B build
ctest --test-dir build -R ex-gradebook-01 --output-on-failure
```

Run the first command once, and again when you add a new `.cpp` file. The second one runs
every test case of step 1. For another step, change the number: `ex-gradebook-02`.

`Passed` means that your program printed the expected output, character for character.
Only spaces at the end of a line do not matter.

You can also build the program yourself, in the folder of the step, and give it a test
case. In steps 1 and 2:

```sh
g++ -std=c++20 -Wall -Wextra exercise.cpp -o gradebook
./gradebook < tests/1.in
```

From step 3 on, the program has several files in the folder `starter`:

```sh
cd starter
g++ -std=c++20 -Wall -Wextra *.cpp -o gradebook
./gradebook < ../tests/1.in
```

`< tests/1.in` gives the file to the program as if you typed it. In Windows PowerShell,
write `Get-Content tests/1.in | .\gradebook.exe`. A test case that uses `save` leaves a
small `.txt` file in the folder. You can delete it.

## When is a step done?

Every step page ends with a marking table. Its rows are the **acceptance criteria** of the
step: the things that must be true before the step counts as done. The test cases check
what the program prints. Your teacher reads the code for the other rows.
