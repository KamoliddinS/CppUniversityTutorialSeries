# Why C++ is fast

> **Goal:** time the same calculation in C++ and in Python, and say where the difference comes from.

## One calculation, two languages

Each Fibonacci number is the sum of the two before it: 0, 1, 1, 2, 3, 5, 8, ...
Both programs compute one with [recursion](../../04-functions/08-recursion/README.md).
The method is wasteful on purpose: `fib(27)` makes more than 600 000 calls.

**`fib.cpp`**
<!-- file: fib.cpp -->
```cpp
#include <iostream>

int fib(int n) {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    constexpr int n = 27;   // raise this to 35 when you measure the time
    std::cout << "fib(" << n << ") = " << fib(n) << '\n';
}
```

<!-- output: fib -->
```text
fib(27) = 196418
```

The same steps in Python, with the same output:

**`fib.py`**
<!-- file: fib.py -->
```python
def fib(n):
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)


n = 27  # raise this to 35 when you measure the time
print(f"fib({n}) = {fib(n)}")
```

## Measure it

Change `27` to `35` in both files: that makes about 30 million calls. Build the C++
program twice, then time three runs:

```sh
g++ -std=c++20 -Wall -Wextra fib.cpp -o fib_plain
g++ -std=c++20 -Wall -Wextra -O2 fib.cpp -o fib_fast
time ./fib_plain
time ./fib_fast
time python3 fib.py
```

`time` prints how long a command took: look for `real` (on macOS: `total`). In PowerShell,
write the last three lines like this and read `TotalSeconds`:

```powershell
Measure-Command { .\fib_plain.exe }
Measure-Command { .\fib_fast.exe }
Measure-Command { python fib.py }
```

If Python is not installed, get it from [python.org](https://www.python.org/downloads/).

The numbers differ on every computer, but expect this order: `fib_fast` is the fastest,
`fib_plain` needs a few times longer, and Python usually tens of times longer.

## Where the difference comes from

| | C++ | Python |
|---|-----|--------|
| Who runs your code? | the processor: the compiler made machine code beforehand | an **interpreter**: a program that reads your code and carries it out step by step |
| What is `n`? | an `int`: the compiler knows its type | an object: its type is checked at each use |
| What does `n - 1` cost? | one or two machine instructions | many |

`-O2` tells the compiler to **optimise**: to find machine code that gives the same result
in fewer steps. Without it, `g++` translates each statement directly, which is what a
debugger needs.

## What the result means

This test measures one kind of work: millions of small function calls. Other programs give
other ratios, so time your own program before you decide.

C++ gives your own code the full speed of the machine, so game engines and browsers are
written in it. Python is still a good choice for many jobs: many programs mostly wait for
a file, the network or the user, and Python code is quicker to write. Many of its fast
libraries are themselves written in C and C++.

## Watch out

- The option is `-O2`, with a capital letter O. `-o2` means "name the program `2`" and
  optimises nothing.
- If a program gives a different result with `-O2`, it almost always has undefined
  behaviour, such as a variable without a starting value.

## Try it

1. Time each program a few times, because times change from run to run. How many times
   longer than `fib_fast` does Python need? And `fib_plain`?
2. A Python program downloads a file in 10 seconds and counts its lines in 0.1 seconds.
   You rewrite it in C++. About how long does it run now?

<details>
<summary>Answers</summary>

1. On one test computer: about 45 times and about 4 times. Yours will differ.
2. Still about 10 seconds: only the 0.1 seconds can get shorter. Find the slow part first.
</details>
