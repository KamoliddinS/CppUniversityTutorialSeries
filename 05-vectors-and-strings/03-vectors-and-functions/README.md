# Vectors and functions

> **Goal:** pass a vector to a function and get one back, without copying it by mistake.

## A plain parameter is a copy

Every student should get 5 bonus points. What does this program print?

**`lost_bonus.cpp`**
<!-- file: lost_bonus.cpp -->
```cpp
#include <iostream>
#include <vector>

void addBonus(std::vector<int> scores, int bonus) {     // by value: a copy
    for (int& score : scores) {
        score += bonus;
    }
}

int main() {
    std::vector<int> scores = {72, 45, 90};
    addBonus(scores, 5);
    for (int score : scores) {
        std::cout << score << ' ';
    }
    std::cout << '\n';
}
```

<!-- output: lost_bonus -->
```text
72 45 90
```

Nobody got the bonus. `addBonus` received a copy of the whole vector and changed the copy.
The copy was thrown away when the function ended. A vector follows the same rule as an `int`:
[by value means a copy](../../04-functions/03-pass-by-value-and-by-reference/README.md).
For a vector the copy is also slow, because every element is copied.

## Three ways that work

**`score_tools.cpp`**
<!-- file: score_tools.cpp -->
```cpp
#include <iostream>
#include <vector>

int total(const std::vector<int>& scores) {               // only reads
    int sum = 0;
    for (int score : scores) {
        sum += score;
    }
    return sum;
}

void addBonus(std::vector<int>& scores, int bonus) {      // changes the caller's vector
    for (int& score : scores) {
        score += bonus;
    }
}

std::vector<int> passed(const std::vector<int>& scores) { // makes a new vector
    std::vector<int> result;
    for (int score : scores) {
        if (score >= 60) {
            result.push_back(score);
        }
    }
    return result;
}

int main() {
    std::vector<int> scores = {72, 45, 90};
    addBonus(scores, 5);
    std::cout << "Total: " << total(scores) << '\n';

    std::vector<int> good = passed(scores);
    std::cout << good.size() << " of " << scores.size() << " passed\n";
}
```

<!-- output: score_tools -->
```text
Total: 222
2 of 3 passed
```

| The function | Write | What happens |
|--------------|-------|--------------|
| only reads the list | parameter `const std::vector<int>& scores` | no copy; a change does not compile |
| changes the caller's list | parameter `std::vector<int>& scores` | no copy; the changes stay |
| makes a new list | return type `std::vector<int>` | the caller receives the list |

Returning a vector is normal and cheap. The elements of `result` are not copied one by one:
the whole list is given to `good`.

## Watch out

- A missing `&` is not an error. The program builds and works on a copy, without any message.
- Write `const` when the function only reads. Then the compiler stops a change that you
  did not mean to make.

## Try it

1. Predict the output of `puzzle.cpp`:

   **`puzzle.cpp`**
   <!-- file: puzzle.cpp -->
   ```cpp
   #include <iostream>
   #include <vector>

   void removeLast(std::vector<int> numbers) {
       numbers.pop_back();
   }

   void addZero(std::vector<int>& numbers) {
       numbers.push_back(0);
   }

   int main() {
       std::vector<int> numbers = {1, 2, 3};
       removeLast(numbers);
       addZero(numbers);
       std::cout << numbers.size() << ' ' << numbers.back() << '\n';
   }
   ```

2. Write a function `readNumbers` that reads whole numbers until the input ends and
   returns them all in a vector.

<details>
<summary>Answers</summary>

1. `removeLast` removes an element from its own copy. `addZero` has a reference, so it adds
   to the vector in `main`:

   <!-- output: puzzle -->
   ```text
   4 0
   ```

2. Start with an empty vector and let it grow. A read is also a
   [condition](../../03-control-flow/07-safe-input/README.md): the loop stops when the
   input ends or is not a number.

   ```cpp
   std::vector<int> readNumbers() {
       std::vector<int> numbers;
       int number = 0;
       while (std::cin >> number) {
           numbers.push_back(number);
       }
       return numbers;
   }
   ```
</details>

**Next:** [Strings in depth](../04-strings-in-depth/README.md)
