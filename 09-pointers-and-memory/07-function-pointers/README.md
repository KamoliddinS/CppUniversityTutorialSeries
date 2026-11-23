# Function pointers

> **Goal:** store the address of a function in a pointer, and pass a function to another function.

## A function has an address too

The code of a function sits in memory as well, so a function has an address. A pointer
can hold it.

**`operation.cpp`**
<!-- file: operation.cpp -->
```cpp
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int (*operation)(int, int) = add;       // operation points to the function add
    std::cout << operation(2, 3) << '\n';

    operation = multiply;                   // now it points to multiply
    std::cout << operation(2, 3) << '\n';
}
```

<!-- output: operation -->
```text
5
6
```

- Read `int (*operation)(int, int)` from the name outwards: `operation` is a pointer to a
  function that takes two `int`s and returns an `int`. This is a **function pointer**.
- The name of a function turns into a pointer to the function, much as the name of an
  array turns into a pointer.
- `operation(2, 3)` calls the function that the pointer holds at that moment.

## Pass a function to a function

`sortBy` knows how to sort, but not which order you want. The caller chooses the order by
passing a function.

**`sort_by.cpp`**
<!-- file: sort_by.cpp -->
```cpp
#include <cstddef>
#include <iostream>
#include <vector>

using Compare = bool (*)(int, int);     // a pointer to a function that compares two ints

bool smallerFirst(int a, int b) {
    return a < b;
}

bool largerFirst(int a, int b) {
    return a > b;
}

// Sorts values. comesFirst(a, b) says whether a must stand before b.
void sortBy(std::vector<int>& values, Compare comesFirst) {
    for (std::size_t i = 0; i < values.size(); ++i) {
        for (std::size_t j = i + 1; j < values.size(); ++j) {
            if (comesFirst(values[j], values[i])) {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
}

void print(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> numbers = {35, 12, 48, 21};
    sortBy(numbers, smallerFirst);
    print(numbers);
    sortBy(numbers, largerFirst);
    print(numbers);
}
```

<!-- output: sort_by -->
```text
12 21 35 48
48 35 21 12
```

- `using Compare = bool (*)(int, int);` gives the pointer type a short name. Without it the
  parameter would be `bool (*comesFirst)(int, int)`.
- One `sortBy` gives two orders. A third order needs only a third small function.

Lambdas ([chapter 15](../../15-standard-library/04-lambdas/README.md)) are the usual modern
way to pass a small function.

## Watch out

- The brackets around `*operation` matter. `int* operation(int, int);` declares a function
  that returns an `int*`.
- The function must match the pointer type exactly. A `Compare` does not accept a function
  that takes two `double`s.
- A function pointer can be `nullptr`. Calling it then is undefined behaviour.

## Try it

1. Predict what this program prints.

   **`apply.cpp`**
   <!-- file: apply.cpp -->
   ```cpp
   #include <iostream>

   int twice(int x) {
       return 2 * x;
   }

   int square(int x) {
       return x * x;
   }

   int applyTwice(int (*f)(int), int value) {
       return f(f(value));
   }

   int main() {
       std::cout << applyTwice(twice, 3) << ' ' << applyTwice(square, 3) << '\n';
   }
   ```

2. Write `bool lastDigitFirst(int a, int b)`, which compares the last digits (`a % 10`).
   Pass it to `sortBy`.

<details>
<summary>Answers</summary>

1. `applyTwice(twice, 3)` is `twice(twice(3))`: 6, then 12. With `square`: 9, then 81.

   <!-- output: apply -->
   ```text
   12 81
   ```

2. The body is `return a % 10 < b % 10;`. The numbers come out as `21 12 35 48`.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)
