# Pass by value and by reference

> **Goal:** decide whether a function works on a copy of your variable or on the variable itself.

## By value: the function gets a copy

Malika has 80 points and should get 5 more.

**`by_value.cpp`**
<!-- file: by_value.cpp -->
```cpp
#include <iostream>

void addBonus(int score) {          // by value: score is a copy
    score = score + 5;
    std::cout << "in addBonus: " << score << '\n';
}

int main() {
    int malika = 80;
    addBonus(malika);
    std::cout << "in main:     " << malika << '\n';
}
```

<!-- output: by_value -->
```text
in addBonus: 85
in main:     80
```

The bonus is lost. This is **pass by value**: the parameter is a new variable that starts
as a copy of the argument. The function changed only its copy. Memory holds two variables:

| Name | Address | Value |
|------|---------|-------|
| `malika` (the caller's variable) | `0x1000` | `80` |
| `score` (the function's parameter) | `0x2000` | `85` |

## By reference: the function gets the original

Change one thing: write `&` after the type of the parameter.

<!-- snippet: by_reference.cpp -->
```cpp
void addBonus(int& score) {         // by reference: score is the caller's variable
```

<!-- output: by_reference -->
```text
in addBonus: 85
in main:     85
```

Now `score` is a **reference**: another name for the caller's variable. No copy is made.
Memory holds one variable with two names:

| Name | Address | Value |
|------|---------|-------|
| `malika` (the caller's variable) and `score` (the function's parameter) | `0x1000` | `85` |

## Two classic uses

**`swap_and_split.cpp`**
<!-- file: swap_and_split.cpp -->
```cpp
#include <iostream>

void swapValues(int& a, int& b) {
    int old = a;
    a = b;
    b = old;
}

void splitMinutes(int total, int& hours, int& minutes) {
    hours = total / 60;
    minutes = total % 60;
}

int main() {
    int aziz = 70;
    int jasur = 95;
    swapValues(aziz, jasur);
    std::cout << "Aziz " << aziz << ", Jasur " << jasur << '\n';

    int hours = 0;
    int minutes = 0;
    splitMinutes(135, hours, minutes);
    std::cout << "135 minutes = " << hours << " h " << minutes << " min\n";
}
```

<!-- output: swap_and_split -->
```text
Aziz 95, Jasur 70
135 minutes = 2 h 15 min
```

- `swapValues` must change two variables of the caller. By value it would swap two copies.
- `return` gives back one value. `splitMinutes` gives back two, through its reference
  parameters.

## Watch out

- The call looks the same both ways: `addBonus(malika)`. Only the function's first line
  tells you whether your variable can change.
- A reference parameter needs a variable. `addBonus(80)` does not compile.
  [Const references](../04-const-references/README.md) shows the message.

## Try it

1. Predict the output of `add_one.cpp`. Then run it.

   **`add_one.cpp`**
   <!-- file: add_one.cpp -->
   ```cpp
   #include <iostream>

   void addOne(int a, int& b) {
       a = a + 1;
       b = b + 1;
       std::cout << "inside: " << a << ' ' << b << '\n';
   }

   int main() {
       int x = 5;
       int y = 5;
       addOne(x, y);
       std::cout << "after:  " << x << ' ' << y << '\n';
       addOne(y, x);
       std::cout << "after:  " << x << ' ' << y << '\n';
   }
   ```

2. Remove both `&` from `swapValues` and run `swap_and_split.cpp` again. What does the
   first line show now?

<details>
<summary>Answers</summary>

1. Only `b` is a reference. Inside the function both numbers grow. After the call only
   the variable in the second place has changed: first `y`, then `x`.

   <!-- output: add_one -->
   ```text
   inside: 6 6
   after:  5 6
   inside: 7 6
   after:  6 6
   ```

2. `Aziz 70, Jasur 95`. The function now swaps its own two copies. It still builds, and
   there is no warning.
</details>

**Next:** [Const references](../04-const-references/README.md)
