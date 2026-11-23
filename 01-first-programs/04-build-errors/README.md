# Build errors

> **Goal:** read an error from the compiler or the linker and find the line to fix.

A build error means no program was made. Nothing is broken: read the message and fix the code.

## Compile error: the code breaks a rule

**`missing_semicolon_nocompile.cpp`**
<!-- file: missing_semicolon_nocompile.cpp -->
```cpp
#include <iostream>

int main() {
    std::cout << "Samarkand\n"
    std::cout << "Bukhara\n";
}
```

<!-- errors: missing_semicolon_nocompile -->
```text
missing_semicolon_nocompile.cpp: In function ‘int main()’:
missing_semicolon_nocompile.cpp:4:31: error: expected ‘;’ before ‘std’
    4 |     std::cout << "Samarkand\n"
      |                               ^
      |                               ;
    5 |     std::cout << "Bukhara\n";
      |     ~~~                        
```

Read the first line like this:

| Piece | Meaning |
|-------|---------|
| `missing_semicolon_nocompile.cpp` | the file |
| `4` | the line |
| `31` | the position in that line |
| `error: expected ';' before 'std'` | what is wrong |

The `^` marks the spot. Here the `;` is missing at the end of line 4.

## Linker error: a piece is missing

**`missing_function_nocompile.cpp`**
<!-- file: missing_function_nocompile.cpp -->
```cpp
#include <iostream>

void greet();   // promised here, but written nowhere

int main() {
    greet();
    std::cout << "Done.\n";
}
```

<!-- errors: missing_function_nocompile -->
```text
ld: program.o: in function `main':
missing_function_nocompile.cpp:(.text+0x9): undefined reference to `greet()'
collect2: error: ld returned 1 exit status
```

There is no line number, and the message comes from `ld`, the linker. `undefined reference`
means: this name was promised, but no file given to `g++` contains its code.

| You see | It is a | Usual cause |
|---------|---------|-------------|
| `file:line:col: error:` | compile error | typo, missing `;` or `)`, misspelled name |
| `undefined reference to ...` | linker error | a `.cpp` file is missing from the `g++` command, or `main` is misspelled |

On macOS the linker says `Undefined symbols` instead of `undefined reference`.

## Watch out

- Fix the **first** error, then build again. Later errors are often caused by the first one.
- The mistake can be on the line *before* the one the compiler reports.
- A **warning** is not an error: the program is still built. Read it anyway.
  [Find bugs with tools](../06-find-bugs-with-tools/README.md) explains why.

## Try it

Each change breaks `hello.cpp` from the [first lesson](../01-hello-world/README.md).
For each one, predict "compile error" or "linker error", then build to check.

1. Remove `#include <iostream>`.
2. Rename `main` to `mian`.
3. Remove the closing `}`.

<details>
<summary>Answers</summary>

1. Compile error: `'cout' is not a member of 'std'`.
2. Linker error: ``undefined reference to `main'``. The code is valid, but a program needs `main`.
   (MinGW on Windows names `WinMain` instead.) You also get a warning about `return`; it goes
   away when the name is `main` again.
3. Compile error: `expected '}' at end of input`.
</details>

**Next:** [Run errors](../05-run-errors/README.md)
