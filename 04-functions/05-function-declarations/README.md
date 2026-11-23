# Function declarations

> **Goal:** call a function that is defined later in the file.

## The compiler has not seen it yet

Until now every function was written above `main`. Here `main` comes first:

**`average_nocompile.cpp`**
<!-- file: average_nocompile.cpp -->
```cpp
#include <iostream>

int main() {
    std::cout << average(80, 91) << '\n';
}

double average(int first, int second) {
    return (first + second) / 2.0;
}
```

<!-- errors: average_nocompile -->
```text
average_nocompile.cpp: In function ‘int main()’:
average_nocompile.cpp:4:18: error: ‘average’ was not declared in this scope
    4 |     std::cout << average(80, 91) << '\n';
      |                  ^~~~~~~
```

The compiler reads a file from top to bottom. At the call in `main` it has not seen
`average` yet.

## Declare first, define later

**`average.cpp`**
<!-- file: average.cpp -->
```cpp
#include <iostream>

double average(int first, int second);      // declarations: these functions exist
void printReport(int first, int second);

int main() {
    printReport(80, 91);
    printReport(60, 75);
}

void printReport(int first, int second) {   // definitions: the bodies
    std::cout << first << " and " << second << ": " << average(first, second) << '\n';
}

double average(int first, int second) {
    return (first + second) / 2.0;
}
```

<!-- output: average -->
```text
80 and 91: 85.5
60 and 75: 67.5
```

| | Looks like | Says |
|---|------------|------|
| **declaration** | the first line of the function, then `;` | this function exists: its name, its parameters and its return type |
| **definition** | the first line, then the body in `{ }` | what the function does |

- A call needs only the declaration above it. So `main` can come first, and the functions
  below it can call each other in any order: `printReport` calls `average`, which is
  defined later.
- The promise `void greet();` in
  [From source to program](../../01-first-programs/03-from-source-to-program/README.md)
  was a declaration. Another word for it is *prototype*.

## Watch out

- The declaration and the definition must agree in name, parameter types and return type.
  With other parameter types you define a different function. The declared one then has
  no body, and the linker reports `undefined reference`.
- Do not forget the `;` after a declaration. The message, `expected initializer`, names
  the line after it.

## Try it

Start from `average.cpp` each time. Compile error or linker error? Predict, then build.

1. Delete the declaration of `average` at the top.
2. Delete the definition of `average` at the bottom.
3. Change the first line of that definition to `double average(double first, double second)`.

<details>
<summary>Answers</summary>

1. Compile error in `printReport`: `'average' was not declared in this scope`.
2. Linker error: `undefined reference to 'average(int, int)'`. The promise was not kept.
3. The same linker error. The call uses the declared `average(int, int)`, and the function
   at the bottom is now a different one.
</details>

**Next:** [Default arguments and overloading](../06-default-arguments-and-overloading/README.md)
