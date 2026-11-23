# Recursion

> **Goal:** write a function that calls itself, and make sure that it stops.

## A function that calls itself

"5 factorial", written 5!, is 5 · 4 · 3 · 2 · 1. That is the same as 5 · 4!: the problem
contains a smaller copy of itself. **Recursion** means that a function solves such a
problem by calling itself.

**`factorial.cpp`**
<!-- file: factorial.cpp -->
```cpp
#include <iostream>

int factorial(int n) {
    if (n <= 1) {
        return 1;                       // base case: no further call
    }
    return n * factorial(n - 1);        // recursive case: a smaller problem
}

int main() {
    std::cout << "3! = " << factorial(3) << '\n';
    std::cout << "5! = " << factorial(5) << '\n';
}
```

<!-- output: factorial -->
```text
3! = 6
5! = 120
```

- The **base case**, `n <= 1`, answers at once without another call. That is where the
  calls stop.
- The recursive case calls the function again, for a smaller problem.

## What `factorial(3)` does

Every call has its own `n`. A call waits until the call it made returns.

| Call | Its own `n` | Waits for | Then returns |
|------|-------------|-----------|--------------|
| `factorial(3)` | 3 | `factorial(2)` | 3 * 2 = 6 |
| `factorial(2)` | 2 | `factorial(1)` | 2 * 1 = 2 |
| `factorial(1)` | 1 | nothing: base case | 1 |

The calls are made from the top row down. The results come back from the bottom row up.

## Recursion or a loop?

The same function with a loop:

<!-- snippet: factorial_loop.cpp -->
```cpp
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}
```

<!-- no-output: factorial_loop -->

It gives the same results with no waiting calls. When a job only repeats one step, a
loop is simpler. Recursion is the better tool when a problem splits into smaller problems
of the same kind, such as a folder that contains folders.

## Watch out

Without a base case every call makes another call, and none of them returns.

<!-- snippet: factorial_bug.cpp -->
```cpp
int factorial(int n) {
    return n * factorial(n - 1);        // no base case
}
```

<!-- errors: factorial_bug -->
```text
factorial_bug.cpp: In function ‘int factorial(int)’:
factorial_bug.cpp:3:5: warning: infinite recursion detected [-Winfinite-recursion]
    3 | int factorial(int n) {
      |     ^~~~~~~~~
factorial_bug.cpp:4:25: note: recursive call
    4 |     return n * factorial(n - 1);        // no base case
      |                ~~~~~~~~~^~~~~~~
```

Each waiting call needs a little memory, and the memory for calls, the *stack*, is
limited. Built with the course's `g++` command, the calls fill it and the system stops the
program. On Linux you see:

```text
Segmentation fault (core dumped)
```

This is a *stack overflow*. Built with the
[sanitizers](../../01-first-programs/06-find-bugs-with-tools/README.md), the program
says so itself: `AddressSanitizer: stack-overflow`. The crash is not promised: for C++,
calls that never end are undefined behaviour. With the option `-O2`, for example, g++
turns this program into a loop that never stops.

## Try it

1. Predict the output of `down_up.cpp`. Then run it.

   **`down_up.cpp`**
   <!-- file: down_up.cpp -->
   ```cpp
   #include <iostream>

   void step(int n) {
       if (n == 0) {
           return;                         // base case: nothing to do
       }
       std::cout << "down " << n << '\n';
       step(n - 1);
       std::cout << "up " << n << '\n';
   }

   int main() {
       step(2);
   }
   ```

2. In `factorial.cpp`, change the base case to `if (n == 1)` and call `factorial(0)`.
   What happens?

<details>
<summary>Answers</summary>

1. Each call prints `down`, waits for the next call, and prints `up` after that call returns.

   <!-- output: down_up -->
   ```text
   down 2
   down 1
   up 1
   up 2
   ```

2. `Segmentation fault`, and no warning this time. The calls go on with 0, -1, -2 and
   never reach the base case. A base case must catch every input.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)
