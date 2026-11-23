# Hello, world

> **Goal:** write a C++ program, build it and run it.

## The program

**`hello.cpp`**
<!-- file: hello.cpp -->
```cpp
#include <iostream>

int main() {
    std::cout << "Hello, world!\n";
}
```

| Part | What it does |
|------|--------------|
| `#include <iostream>` | brings in the tools for printing |
| `int main() { ... }` | the function where every program starts |
| `std::cout << "..."` | sends the text to the screen |
| `\n` | ends the line |
| `;` | ends a statement |

When `main` reaches its closing `}`, the program ends and reports success.

## Build it, then run it

Open a terminal in this folder and type:

```sh
g++ -std=c++20 -Wall -Wextra hello.cpp -o hello
./hello
```

<!-- output: hello -->
```text
Hello, world!
```

The first command **builds**: `g++` reads `hello.cpp` and writes a program named `hello`.
The second command **runs** that program. On Windows PowerShell, run it with `.\hello.exe`.

| Option | Meaning |
|--------|---------|
| `-std=c++20` | use the C++20 version of the language |
| `-Wall -Wextra` | warn me about suspicious code |
| `-o hello` | name the program `hello` |

## Watch out

- C++ is case-sensitive. `Main` and `Std::cout` do not work.
- If you change the code, build again. Running alone starts the old program.

## Try it

1. Change the text so the program prints your name. Build and run.
2. Add a second line that prints the name of your city.
3. Delete one `;`, build, and read what the compiler says. Then put it back.

**Next:** [Output and input](../02-output-and-input/README.md)
