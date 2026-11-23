# Run errors

> **Goal:** tell a crash from a wrong result, and know that C++ does not check everything for you.

The build worked, so there is a program. It can still go wrong in two ways.

## 1. The program does something illegal

**`divide_by_zero_bug.cpp`**
<!-- file: divide_by_zero_bug.cpp -->
```cpp
#include <iostream>

int main() {
    int sweets = 12;
    int students = 0;
    std::cout << "Each student gets " << sweets / students << " sweets.\n";
    std::cout << "Done.\n";
}
```

It builds without a message. Running it on Linux gives:

```text
Floating point exception (core dumped)
```

The system stopped the program at the division. `Done.` was never printed, and there is no
line number.

Dividing a whole number by zero is **undefined behaviour**: C++ does not check for it and does
not promise what happens. The program may be stopped, may print nonsense, or may seem to work.
You will meet more cases later, such as reading past the end of a list.

## 2. The program runs, but the answer is wrong

**`wrong_average.cpp`**
<!-- file: wrong_average.cpp -->
```cpp
#include <iostream>

int main() {
    int first = 80;
    int second = 90;
    int average = first + second / 2;   // meant: (first + second) / 2
    std::cout << "Average: " << average << '\n';
}
```

<!-- output: wrong_average -->
```text
Average: 125
```

The average of 80 and 90 is 85. The program divides only `second` by 2: `/` groups more
strongly than `+`, so the line means `first + (second / 2)`. This is a **logic error**: the code is valid, but it does not say what you meant.
No tool reports it. You find it by checking results you can work out by hand.

| | Build error | Illegal action | Logic error |
|---|---|---|---|
| Is there a program? | no | yes | yes |
| Who tells you? | compiler or linker | the system, sometimes nobody | nobody |
| How you find it | read the message | [tools](../06-find-bugs-with-tools/README.md) | test with known answers |

## Watch out

- "It ran once" does not mean "it is correct". Try inputs where you know the answer.
- A crash message names no line. The next lesson shows how to get one.

## Try it

1. Fix `wrong_average.cpp` so it prints 85.
2. Now set `second` to 91. What does your fixed program print, and is that the true average?

<details>
<summary>Answers</summary>

1. `int average = (first + second) / 2;`
2. It prints `85`, but the true average is 85.5. Dividing whole numbers drops the part after
   the point. [Arithmetic](../../02-values-and-types/04-arithmetic/README.md) explains this.
</details>

**Next:** [Find bugs with tools](../06-find-bugs-with-tools/README.md)
