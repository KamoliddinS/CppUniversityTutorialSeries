# Scope and lifetime

> **Goal:** say where a name can be used and how long its variable exists.

## A variable ends with its block

The last line of this program tries to print `square` once more:

**`block_nocompile.cpp`**
<!-- file: block_nocompile.cpp -->
```cpp
#include <iostream>

int main() {
    for (int i = 1; i <= 3; ++i) {
        int square = i * i;
        std::cout << square << '\n';
    }
    std::cout << "last: " << square << '\n';
}
```

<!-- errors: block_nocompile -->
```text
block_nocompile.cpp: In function ‘int main()’:
block_nocompile.cpp:8:30: error: ‘square’ was not declared in this scope
    8 |     std::cout << "last: " << square << '\n';
      |                              ^~~~~~
```

`square` is declared inside the `{ }` of the loop. Two things end at that `}`:

- its **scope**: the part of the code where the name can be used;
- its **lifetime**: the time during which the variable exists. Every round of the loop
  makes a new `square`.

The body of a function is a block too. Its parameters and variables are *local*: their
names cannot be used in another function.

## The same name twice

**`wrong_price.cpp`**
<!-- file: wrong_price.cpp -->
```cpp
#include <iostream>

int main() {
    int price = 20000;
    bool isStudent = true;

    if (isStudent) {
        int price = 10000;          // a second variable with the same name
        std::cout << "Student price: " << price << " so'm\n";
    }
    std::cout << "To pay: " << price << " so'm\n";
}
```

<!-- output: wrong_price -->
```text
Student price: 10000 so'm
To pay: 20000 so'm
```

The student should pay 10000. The `int` in the block creates a second `price`. Inside the
block that name hides the outer one: this is called *shadowing*. The outer `price` never
changes.

## `static`: a local variable that stays

**`counter.cpp`**
<!-- file: counter.cpp -->
```cpp
#include <iostream>

void visit() {
    int normal = 0;             // created again at every call
    static int kept = 0;        // created only once
    ++normal;
    ++kept;
    std::cout << "normal: " << normal << "   static: " << kept << '\n';
}

int main() {
    visit();
    visit();
    visit();
}
```

<!-- output: counter -->
```text
normal: 1   static: 1
normal: 1   static: 2
normal: 1   static: 3
```

`normal` and `kept` have the same scope, the body of `visit`, but not the same lifetime.
`kept` is created once and exists until the program ends, so it keeps its value between calls.

| Variable | Scope | Lifetime |
|----------|-------|----------|
| local variable, parameter | from its declaration to the `}` of its block | the same |
| `static` local variable | like a local variable | created once; exists until the program ends |
| global variable | from its declaration to the end of the file | the whole run of the program |

A *global variable* is declared outside all functions, so every function below it can read
and change it. Avoid global variables: when one holds a wrong value, any function may be
the cause.

## Watch out

- g++ reports shadowing only when you add `-Wshadow` to the build command.
- The `= 0` of a `static` variable is done once, not at every call.

## Try it

1. Predict the output of `names.cpp`. Then run it.

   **`names.cpp`**
   <!-- file: names.cpp -->
   ```cpp
   #include <iostream>

   int nextNumber() {
       static int number = 0;
       number += 10;
       return number;
   }

   int main() {
       int number = 1;
       for (int i = 0; i < 2; ++i) {
           int number = nextNumber();
           std::cout << number << ' ';
       }
       std::cout << number << '\n';
   }
   ```

2. Fix `wrong_price.cpp` so that the student pays 10000.

<details>
<summary>Answers</summary>

1. There are three variables named `number`. The `static` one in `nextNumber` keeps
   growing. The one in the loop shadows the one in `main`, which stays 1.

   <!-- output: names -->
   ```text
   10 20 1
   ```

2. Delete the word `int` in the block. Then `price = 10000;` is an assignment to the
   outer `price`.
</details>

**Next:** [Recursion](../08-recursion/README.md)
