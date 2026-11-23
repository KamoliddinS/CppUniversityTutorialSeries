# Default arguments and overloading

> **Goal:** let a call leave out arguments, and give one name to functions that do the same job for different inputs.

## Default arguments

A *default argument* is the value a parameter gets when the call leaves that argument out.

**`line.cpp`**
<!-- file: line.cpp -->
```cpp
#include <iostream>

void drawLine(int length = 20, char symbol = '-');      // the defaults are written here

int main() {
    drawLine();             // 20 times '-'
    drawLine(10);           // 10 times '-'
    drawLine(10, '=');      // 10 times '='
}

void drawLine(int length, char symbol) {                // and not again here
    for (int i = 0; i < length; ++i) {
        std::cout << symbol;
    }
    std::cout << '\n';
}
```

<!-- output: line -->
```text
--------------------
----------
==========
```

- Arguments fill the parameters from the left. So a call can leave out only the last ones,
  and the defaults must be on the last parameters.
- Write the defaults once: in the declaration if there is one, and not again in the definition.

## Overloading

**Overloading** means that several functions share one name. Their parameter lists must
differ in the number of parameters or in their types. For each call the compiler picks
the function that fits the arguments.

**`larger.cpp`**
<!-- file: larger.cpp -->
```cpp
#include <iostream>

int larger(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

double larger(double a, double b) {
    if (a > b) {
        return a;
    }
    return b;
}

int larger(int a, int b, int c) {
    return larger(larger(a, b), c);
}

int main() {
    std::cout << larger(3, 8) << '\n';          // two int values
    std::cout << larger(2.5, 1.5) << '\n';      // two double values
    std::cout << larger(4, 9, 6) << '\n';       // three int values
}
```

<!-- output: larger -->
```text
8
2.5
9
```

## A call that fits two functions

Add one more call to `main`:

<!-- snippet: larger_nocompile.cpp -->
```cpp
    std::cout << larger(3, 4.5) << '\n';        // an int and a double
```

<!-- errors: larger_nocompile -->
```text
larger_nocompile.cpp: In function ‘int main()’:
larger_nocompile.cpp:25:24: error: call of overloaded ‘larger(int, double)’ is ambiguous
   25 |     std::cout << larger(3, 4.5) << '\n';        // an int and a double
      |                  ~~~~~~^~~~~~~~
larger_nocompile.cpp:3:5: note: candidate: ‘int larger(int, int)’
    3 | int larger(int a, int b) {
      |     ^~~~~~
larger_nocompile.cpp:10:8: note: candidate: ‘double larger(double, double)’
   10 | double larger(double a, double b) {
      |        ^~~~~~
```

`3` fits the `int` version and `4.5` fits the `double` version. Neither function is better
for both arguments, so the call is *ambiguous*: it has two possible meanings, and the
compiler does not guess. Give both arguments the same type: `larger(3.0, 4.5)`.

## Watch out

- You cannot skip an argument. `drawLine('=')` builds, but `'='` goes into `length` as the
  number 61, its character code. You get 61 dashes.
- Another return type is not enough. `int half(int)` and `double half(int)` cannot both
  exist: at a call the compiler could not tell them apart.

## Try it

1. Predict the output of `show.cpp`. Then run it.

   **`show.cpp`**
   <!-- file: show.cpp -->
   ```cpp
   #include <iostream>

   void show(int number, int times = 2) {
       for (int i = 0; i < times; ++i) {
           std::cout << number << ' ';
       }
       std::cout << '\n';
   }

   void show(double number) {
       std::cout << "decimal " << number << '\n';
   }

   int main() {
       show(7);
       show(7, 3);
       show(7.5);
       show(1 + 2);
   }
   ```

2. Change `totalCost(int price, int quantity)` from
   [Parameters and return values](../02-parameters-and-return-values/README.md) so that
   `totalCost(12000)` means one piece.

<details>
<summary>Answers</summary>

1. `show(7)` uses the default `2`. `7.5` is a `double`, so the second function runs.
   `1 + 2` is an `int`.

   <!-- output: show -->
   ```text
   7 7
   7 7 7
   decimal 7.5
   3 3
   ```

2. `int totalCost(int price, int quantity = 1)`
</details>

**Next:** [Scope and lifetime](../07-scope-and-lifetime/README.md)
