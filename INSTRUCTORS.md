# Teaching guide

This page is for the people who teach the course or maintain it.

## What is in the repository

| Folder or file | What it is |
|----------------|------------|
| `00-…` to `16-…` | the chapters; each has lessons and an `exercises/` folder |
| `projects/` | the Gradebook (five steps) and the Binary converter |
| `appendix/` | optional side topics |
| `GLOSSARY.md` | all key terms, generated from the chapter pages |
| `tools/check.py` | checks every lesson, example and exercise |
| `CMakeLists.txt` | builds every example and runs the exercise checks |
| `.github/workflows/` | the automatic checks that run on GitHub |
| `.devcontainer/`, `.vscode/` | a ready-made environment and editor settings |

## A plan for fifteen weeks

One chapter is about one week: two lessons' worth of class time plus a lab on the exercises.

| Week | Chapters | Project step due |
|------|----------|------------------|
| 1 | 00 Getting started, 01 First programs | |
| 2 | 02 Values and types | |
| 3 | 03 Control flow | |
| 4 | 04 Functions | |
| 5 | 05 Vectors and strings | Gradebook 1 |
| 6 | 06 Structs and files | Gradebook 2 |
| 7 | 07 Classes | |
| 8 | 08 Operator overloading, review | Gradebook 3 |
| 9 | 09 Pointers and memory | |
| 10 | 10 Resource management | |
| 11 | 11 Inheritance | |
| 12 | 12 Polymorphism | Gradebook 4 |
| 13 | 13 Exceptions | |
| 14 | 14 Templates, 15 The standard library (lessons 1 to 3) | |
| 15 | 15 The standard library (lessons 4 to 6), review | Gradebook 5 |

Chapter 16 (Rust) and the appendix are for self-study. The Binary converter is a spare
assignment that fits after chapter 05.

## How a lesson is meant to be taught

1. State the goal (the first line of the page).
2. Type the example live, or open it, and ask the class to **predict the output** before you run it.
3. Break it on purpose in the way "Watch out" describes, and read the message together.
4. Give five minutes for "Try it".

The pages are short on purpose. They are what a student rereads later, not a script.

## Checks

Run this before you push. It needs Linux or macOS (or the dev container), Python 3.9+ and g++ 13+.

```sh
python3 tools/check.py
python3 tools/check.py 07-classes
python3 tools/check.py --fix
```

Without a folder it checks everything. `--fix` refreshes the code and output blocks in the
pages, and the glossary.

It builds every example with warnings as errors, runs it under the sanitizers, compares
the output shown in each page with the real output, checks every link between pages, and
checks that every exercise has a starter that fails and a solution that passes.

On GitHub the same checks run on every push and pull request:

| Workflow | What it does |
|----------|--------------|
| CI | `tools/check.py`, spelling, and a build of all examples on Linux, macOS and Windows |
| Exercise results | in a student's copy: a table of which exercises pass (never fails) |
| External links | once a week: are links to other websites still alive |
| Site | builds the website; publishes it once you switch that on |

The macOS and Windows jobs build with the compilers students use there (Apple clang, MinGW g++).
Treat a failure there as a real portability problem in an example.

## Exercises and solutions

- Every task has tests. Students check a task with
  `ctest --test-dir build -R ex-03-02 --output-on-failure` (after `cmake -B build`).
- Solutions are **not** in this repository. They are in the folder `solutions/`, which
  git ignores here and which is its own repository. Push it to a **private** repository
  and give access to the teaching staff:

  ```sh
  cd solutions
  git remote add origin <address of your private repository>
  git push -u origin main
  ```

- With `solutions/` in place, `tools/check.py` also builds every solution and runs it
  against the tests, so an exercise can never become unsolvable without you noticing.
  The private repository has its own workflow that does this on GitHub.
- A project step builds on the student's own code from the step before. Hand out the
  solution of a step after its deadline so that nobody stays stuck.

### Automatic feedback and grading

- A student who forks the course and pushes their work gets a results table from the
  "Exercise results" workflow, under the **Actions** tab of their fork.
- For graded work, use the course as a template in GitHub Classroom, or ask for the
  fork's link: the results table is the evidence. The tests check behaviour only, so
  read the code for the marks on quality. Each project step has a marking table.

## The website

The pages can be published as a searchable site:

1. In the repository settings open **Pages** and set the source to **GitHub Actions**.
2. Under **Secrets and variables → Actions → Variables** add `DEPLOY_SITE` with the value `true`.
3. Run the **Site** workflow, or push to `main`.

To preview it on your own computer, install [mdBook](https://github.com/rust-lang/mdBook/releases)
and run `python3 tools/build_site.py --serve`.

## Where the old lessons went

| Old folder | Now in |
|------------|--------|
| `1.Introduction` | 00 Getting started, 01 First programs; "Why C++" is in the appendix |
| `2.C++ProgramStructure` | 01 First programs, 02 Values and types; namespaces, number systems and two's complement are in the appendix; `main` arguments are in 06 |
| `3.C++DataStorageBasics` | 02 (variables, types, constants), 05 (vectors, arrays), 06 (structs) |
| `4.StatementsOperators` | 02 (arithmetic, conversions), 03 (comparisons, logic); bit operators are in the appendix |
| `5.ControllingProgramFlow` | 03 Control flow; the range-based `for` is in 05 |
| `6.CharacterStrings` | 05 Vectors and strings; C-style strings are a short part of 09 |
| `7.Functions` | 04 Functions |
| `8.PointerReferences` | 09 Pointers and memory |
| `9.OOP` | 07 Classes; copying and moving are in 10 |
| `10.OpertorOverloading` | 08 Operator overloading; the assignment operators are in 10 |
| `11.Inheritance`, `12.Polymorphism` | 11 and 12 |
| `13.SmartPointers` | 10 Resource management |
| `14.ExceptionHandling` | 13 Exceptions |
| `15.IOStreams` | 06 Structs and files |
| `16.STL`, `17.LambdaExperessions` | 14 Templates, 15 The standard library |
| `18.RustTutorial` | 16 Rust for C++ programmers, shortened to a bridge from C++ |
| `DummyTopics` | appendix (design principles, licences) |
| `Projects` | `projects/`: the Gradebook in five steps and the Binary converter; the car rental project was retired |

## Changing the course

Read [How this course is written](CONTRIBUTING.md) first. In short: one idea per lesson,
at most 400 words, code and output are pulled from real files, and `tools/check.py` must pass.
