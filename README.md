# C++ course

A first programming course in C++, taught at Central Asian University.

It starts from zero: no programming experience is needed. Every lesson is one short page
with a small program you can build and run, and every chapter ends with exercises that
check themselves.

## Start here

1. **Set up your computer:** [00 · Getting started](00-getting-started/README.md).
   No time to install anything? Open the course in a ready-made environment:
   on GitHub press **Code → Codespaces → Create codespace**.
2. **Get the course:**

   ```sh
   git clone https://github.com/KamoliddinS/CppUniversityTutorialSeries.git
   ```

3. **Open** [01 · First programs](01-first-programs/README.md) and follow the chapters in order.

## How to use a lesson

1. Read the page. It takes about five minutes.
2. Build and run the example that sits in the lesson's folder:

   ```sh
   g++ -std=c++20 -Wall -Wextra hello.cpp -o hello
   ./hello
   ```

3. Do the "Try it" tasks before you look at the answers.
4. At the end of a chapter, do its exercises and let the computer check them:

   ```sh
   cmake -B build
   ctest --test-dir build -R ex-03-02 --output-on-failure
   ```

   The first command is needed only once. The second checks exercise 2 of chapter 03.

## The chapters

### Part 1: Programs that do something

| # | Chapter | After it you can |
|---|---------|------------------|
| 00 | [Getting started](00-getting-started/README.md) | build a program on your own computer and get the course with Git |
| 01 | [First programs](01-first-programs/README.md) | write, build and run a program, and find out why it fails |
| 02 | [Values and types](02-values-and-types/README.md) | store numbers and text and calculate with them |
| 03 | [Control flow](03-control-flow/README.md) | make decisions, repeat work, and survive wrong input |
| 04 | [Functions](04-functions/README.md) | split a program into small named pieces |
| 05 | [Vectors and strings](05-vectors-and-strings/README.md) | work with lists of values and with text |
| 06 | [Structs and files](06-structs-and-files/README.md) | group data, save it to a file and load it again |

### Part 2: Your own types and memory

| # | Chapter | After it you can |
|---|---------|------------------|
| 07 | [Classes](07-classes/README.md) | write types that protect their data |
| 08 | [Operator overloading](08-operator-overloading/README.md) | make your types work with `+`, `==` and `<<` |
| 09 | [Pointers and memory](09-pointers-and-memory/README.md) | use addresses, and recognise what goes wrong with them |
| 10 | [Resource management](10-resource-management/README.md) | write classes that clean up, copy and move correctly |

### Part 3: Abstraction and the library

| # | Chapter | After it you can |
|---|---------|------------------|
| 11 | [Inheritance](11-inheritance/README.md) | build a class on top of another one |
| 12 | [Polymorphism](12-polymorphism/README.md) | let one call run different code for different objects |
| 13 | [Exceptions](13-exceptions/README.md) | report errors and recover from them |
| 14 | [Templates](14-templates/README.md) | write code that works for many types |
| 15 | [The standard library](15-standard-library/README.md) | pick the right container and let algorithms do the loops |
| 16 | [Rust for C++ programmers](16-rust-for-cpp-programmers/README.md) | (optional) read Rust and compare its rules with C++ |

### More

- [Projects](projects/README.md): a gradebook program that grows with the course, and a binary converter.
- [Appendix](appendix/README.md): number systems, build systems, design principles and other side topics.
- [Glossary](GLOSSARY.md): every key term of the course on one page.

## Found a mistake?

Please tell us. Open an issue with the form **Problem in a lesson**, or fix it yourself and
send a pull request: the lesson [Use Git](00-getting-started/03-use-git/README.md) shows how.

## For teachers

- [Teaching guide](INSTRUCTORS.md): a week-by-week plan, how the checks work, where the solutions are.
- [How this course is written](CONTRIBUTING.md): the rules every lesson follows.

## Licence

The course is released under [CC0 1.0](LICENSE): you may copy, change and reuse it freely.
