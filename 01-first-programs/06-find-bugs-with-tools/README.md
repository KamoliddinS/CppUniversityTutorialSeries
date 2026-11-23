# Find bugs with tools

> **Goal:** use warnings, sanitizers and a debugger to find a bug instead of guessing.

## 1. Warnings: the compiler points at suspicious code

Always build with `-Wall -Wextra`.

**`uninitialized_bug.cpp`**
<!-- file: uninitialized_bug.cpp -->
```cpp
#include <iostream>

int main() {
    int total;
    total = total + 5;
    std::cout << "Total: " << total << '\n';
}
```

<!-- errors: uninitialized_bug -->
```text
uninitialized_bug.cpp: In function ‘int main()’:
uninitialized_bug.cpp:5:11: warning: ‘total’ is used uninitialized [-Wuninitialized]
    5 |     total = total + 5;
      |     ~~~~~~^~~~~~~~~~~
uninitialized_bug.cpp:4:9: note: ‘total’ was declared here
    4 |     int total;
      |         ^~~~~
```

The program is built, but `total` never got a starting value. Reading it is undefined
behaviour: any number may come out. Treat every warning as a bug until you understand it.

## 2. Sanitizers: the program checks itself while it runs

Add `-g -fsanitize=address,undefined` when you build
[`divide_by_zero_bug.cpp`](divide_by_zero_bug.cpp):

```sh
g++ -std=c++20 -Wall -Wextra -g -fsanitize=address,undefined divide_by_zero_bug.cpp -o demo
./demo
```

The first line of the report:

```text
divide_by_zero_bug.cpp:6:49: runtime error: division by zero
```

Now the crash has a file and a line. Sanitizers work on Linux, macOS and in the course's
dev container. MinGW on Windows does not have them.

## 3. The debugger: run one line at a time

**`wrong_discount.cpp`**
<!-- file: wrong_discount.cpp -->
```cpp
#include <iostream>

int main() {
    int price = 12000;      // one notebook, in so'm
    int quantity = 3;
    int discount = 10;      // percent

    int total = price * quantity;
    int saved = discount / 100 * total;
    total = total - saved;

    std::cout << "To pay: " << total << " so'm\n";
}
```

<!-- output: wrong_discount -->
```text
To pay: 36000 so'm
```

Three notebooks cost 36000 so'm, so 10% off should give 32400. To see where it goes wrong:

1. Open the file in VS Code and click left of line 9. A red dot appears: a **breakpoint**.
2. Press **F5**. The program runs and stops at that line.
3. Press **F10** to run one line. Look at the **Variables** panel after each step.

After line 9, `saved` is `0`, not `3600`. That line is the bug.

Without VS Code, build with `-g`, so the debugger knows the line numbers, and start
`gdb ./wrong_discount`:

| Command | Meaning |
|---------|---------|
| `break 9` | stop at line 9 |
| `run` | start the program |
| `next` | run one line |
| `print saved` | show a variable |
| `quit` | leave (answer `y` if it asks) |

On macOS the debugger is `lldb`. There you stop at line 9 with `b 9`.

## Try it

1. Why is `saved` zero? Fix line 9 so the program prints 32400.
2. Give `total` a starting value in `uninitialized_bug.cpp` and check that the warning is gone.

<details>
<summary>Answer to 1</summary>

`discount / 100` is `10 / 100`. Both are whole numbers, so the result is `0`, and `0 * total`
is `0`. Multiply first: `int saved = total * discount / 100;`
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)
