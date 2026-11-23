# If and else

> **Goal:** run one block of code when a condition is true, and another when it is false.

## if and else

**`pass.cpp`**
<!-- file: pass.cpp -->
```cpp
#include <iostream>

int main() {
    std::cout << "Score (0 to 100): ";
    int score = 0;
    std::cin >> score;

    if (score >= 60) {
        std::cout << "Passed.\n";
        if (score >= 90) {              // tested only when the score is 60 or more
            std::cout << "With distinction.\n";
        }
    } else {
        std::cout << "Not passed.\n";
    }
}
```

<!-- session: pass -->
```text
Score (0 to 100): 95
Passed.
With distinction.
```

- When the condition is true, the first block runs. Otherwise the `else` block runs.
  The `else` part is optional.
- The second `if` is **nested**: it is inside the first block, so it is tested only when
  the first condition is true. A score of 40 never reaches it.

## Many cases: else if

**`grade.cpp`**
<!-- file: grade.cpp -->
```cpp
#include <iostream>

int main() {
    std::cout << "Score (0 to 100): ";
    int score = 0;
    std::cin >> score;

    if (score >= 90) {
        std::cout << "Grade 5: excellent\n";
    } else if (score >= 70) {
        std::cout << "Grade 4: good\n";
    } else if (score >= 60) {
        std::cout << "Grade 3: satisfactory\n";
    } else {
        std::cout << "Grade 2: not passed\n";
    }
}
```

<!-- session: grade -->
```text
Score (0 to 100): 85
Grade 4: good
```

- The conditions are tested from top to bottom. The first true one wins, and the rest of
  the chain is skipped.
- So the order matters: 85 is also `>= 60`, but the chain never gets that far.
- The last `else` takes everything that is left.

To choose between two values, there is a short form: `condition ? a : b`. For example,
`int price = age < 7 ? 0 : 20000;` makes the ticket free for small children.

## Watch out

**`braces_bug.cpp`**
<!-- file: braces_bug.cpp -->
```cpp
#include <iostream>

int main() {
    int score = 40;

    if (score >= 60);
    {
        std::cout << "Passed.\n";
    }

    if (score >= 90)
        std::cout << "Excellent.\n";
        std::cout << "You get a prize.\n";
}
```

The score is 40, but the program prints both lines:

```text
Passed.
You get a prize.
```

- An `if` without braces controls only the next statement. C++ ignores the indentation,
  so `You get a prize.` is always printed.
- A `;` alone is a statement that does nothing. The first `if` controls only that `;`,
  and the block below it always runs.
- Always write the braces, and no `;` after the `)`. g++ warns about both mistakes.

## Try it

1. Predict: in `grade.cpp`, somebody puts the test `score >= 60` and its block first.
   What does the program print for a score of 95?
2. Change `pass.cpp` so that a score below 0 or above 100 prints only `Not a valid score.`
3. Build `braces_bug.cpp`, read the warnings, and fix it.

<details>
<summary>Answers</summary>

1. `Grade 3: satisfactory`. `95 >= 60` is true, so the first block runs and the rest of the
   chain is skipped. Test the highest limit first.
2. Put a new test in front: `if (score < 0 || score > 100) { ... } else if (score >= 60) ...`
3. Delete the `;` after `if (score >= 60)`. Put `{ }` around the two lines under
   `if (score >= 90)`. Now a score of 40 prints nothing.
</details>

**Next:** [Switch](../03-switch/README.md)
