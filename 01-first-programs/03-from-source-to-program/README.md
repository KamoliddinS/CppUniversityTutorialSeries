# From source to program

> **Goal:** say what happens between typing `g++` and seeing a program you can run.

## Three steps

```text
hello.cpp  ──►  compile  ──►  hello.o  ──►  link  ──►  hello
 (source)                    (object)                (program)
```

| Step | What happens | It fails when |
|------|--------------|---------------|
| **Compile** | Each `.cpp` file is checked and translated into machine code. The result is an *object file*. | the code breaks the rules of the language |
| **Link** | The object files and the library code (the code behind `std::cout`, for example) are joined into one program. | a piece that was promised cannot be found |
| **Run** | The system loads the program and calls `main`. | the program does something illegal |

`g++` does the first two steps in one command. `#include <iostream>` is handled just
before compiling: the line is replaced by the contents of that library file.

## A program in two files

Real programs have many source files. Each is compiled alone; the linker joins them.

**`two_files/main.cpp`**
<!-- file: two_files/main.cpp -->
```cpp
#include <iostream>

void greet();   // a promise: greet is written in another file

int main() {
    greet();
    std::cout << "Back in main.\n";
}
```

**`two_files/greeting.cpp`**
<!-- file: two_files/greeting.cpp -->
```cpp
#include <iostream>

void greet() {
    std::cout << "Hello from greeting.cpp!\n";
}
```

In the folder `two_files`, give both files to `g++`:

```sh
g++ -std=c++20 -Wall -Wextra main.cpp greeting.cpp -o two_files
./two_files
```

<!-- output: two_files -->
```text
Hello from greeting.cpp!
Back in main.
```

`main.cpp` only promises that `greet` exists. The linker finds it in the code from `greeting.cpp`.
(`greet` is a *function*, a named block of code. [Chapter 4](../../04-functions/README.md) is about them.)

## Watch out

- A `.cpp` file is text. Only the built program can run.
- Each time you edit a source file, you must build again.

## Try it

1. Build with `main.cpp` only: `g++ -std=c++20 main.cpp -o two_files`. Which step fails, and why?
2. See the steps one by one: `g++ -std=c++20 -c main.cpp` only compiles and makes `main.o`.
   Do the same for `greeting.cpp`, then link the two: `g++ main.o greeting.o -o two_files`.

<details>
<summary>Answer to 1</summary>

Linking fails with ``undefined reference to `greet()'``. Compiling `main.cpp` works, because the
promise `void greet();` is enough for the compiler. The linker then looks for the real code and
cannot find it.
</details>

**Next:** [Build errors](../04-build-errors/README.md)
