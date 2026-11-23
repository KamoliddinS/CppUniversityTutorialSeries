# 01 · First programs

After this chapter you can write a small program, build it, run it, and find out why it
does not work.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Hello, world](01-hello-world/README.md) | write, build and run a program |
| 2 | [Output and input](02-output-and-input/README.md) | print values and read what the user types |
| 3 | [From source to program](03-from-source-to-program/README.md) | say what the compiler and the linker do |
| 4 | [Build errors](04-build-errors/README.md) | read a compiler or linker message |
| 5 | [Run errors](05-run-errors/README.md) | tell a crash from a wrong result |
| 6 | [Find bugs with tools](06-find-bugs-with-tools/README.md) | use warnings, sanitizers and the debugger |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| source file | a text file with C++ code, such as `hello.cpp` |
| compiler | the tool that checks source code and translates it to machine code (`g++`) |
| linker | the tool that joins compiled pieces into one program |
| build | compile and link: make a program from source files |
| statement | one instruction; most end with `;` |
| compile error | the code breaks a rule of the language, so no program is made |
| linker error | a promised piece of code cannot be found, so no program is made |
| logic error | the program runs but gives the wrong result |
| undefined behaviour | something C++ does not check; anything may happen |
| warning | a compiler message about code that is legal but probably wrong |
| breakpoint | a line where the debugger stops the program |
