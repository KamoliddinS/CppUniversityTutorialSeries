# Define and call

> **Goal:** write a function and call it wherever its work is needed.

## One job, one name

The receipt below needs a line of dashes in three places. Without a function you write
the same loop three times. A **function** is a named block of code that does one job.

**`receipt.cpp`**
<!-- file: receipt.cpp -->
```cpp
#include <iostream>

void drawLine() {
    for (int i = 0; i < 24; ++i) {
        std::cout << '-';
    }
    std::cout << '\n';
}

int main() {
    drawLine();
    std::cout << "Notebook      12000 so'm\n";
    std::cout << "Pen            3000 so'm\n";
    drawLine();
    std::cout << "Total         15000 so'm\n";
    drawLine();
}
```

<!-- output: receipt -->
```text
------------------------
Notebook      12000 so'm
Pen            3000 so'm
------------------------
Total         15000 so'm
------------------------
```

- The block that starts with `void drawLine()` *defines* the function. Defining runs
  nothing: the program still starts in `main`.
- `drawLine();` *calls* the function. `main` is the *caller*: it waits, the code of
  `drawLine` runs, and then `main` goes on with its next statement.

## Why functions

- The name tells the reader what happens. A loop does not.
- The loop is written once, so a change is made in one place.
- You can test one small function alone.

## The parts of a definition

| Part | In the example | Meaning |
|------|----------------|---------|
| return type | `void` | what the function gives back; `void` means nothing |
| name | `drawLine` | what you write to call it |
| parameter list | `()` | what the function needs from the caller; nothing here |
| body | `{ ... }` | the statements that run at each call |

`main` is a function too: the system calls it when your program starts.

## Watch out

- `drawLine;` without `()` is not a call. It builds with a warning and does nothing.
- The compiler must see a function before the line that calls it. For now, write your
  functions above `main`. [Function declarations](../05-function-declarations/README.md)
  removes this limit.

## Try it

1. Predict the output of `calls.cpp`. Then run it.

   **`calls.cpp`**
   <!-- file: calls.cpp -->
   ```cpp
   #include <iostream>

   void printA() {
       std::cout << "A\n";
   }

   void printB() {
       std::cout << "B\n";
       printA();
   }

   int main() {
       std::cout << "start\n";
       printB();
       printA();
       std::cout << "end\n";
   }
   ```

2. In `receipt.cpp`, draw the lines with `=` instead of `-`. How many places do you change?

<details>
<summary>Answers</summary>

1. A function runs when it is called, not where it is defined. `printB` calls `printA` itself.

   <!-- output: calls -->
   ```text
   start
   B
   A
   A
   end
   ```

2. One: the `'-'` inside `drawLine`. All three lines of the receipt change.
</details>

**Next:** [Parameters and return values](../02-parameters-and-return-values/README.md)
