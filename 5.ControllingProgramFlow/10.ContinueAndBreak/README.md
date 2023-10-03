
# The `continue` and `break` Statements in C++

## Objective
In this lesson, we will explore two important control flow statements in C++: `continue` and `break`. These statements allow you to control the flow of your program within loops, making your code more efficient and flexible.

## The `continue` Statement
The `continue` statement is used within loops (e.g., `for`, `while`, `do-while`) to skip the current iteration and move to the next iteration. It is particularly useful when you want to avoid executing some part of the loop's code under certain conditions.

### Syntax
```cpp
for (int i = 0; i < n; i++) {
    if (condition) {
        continue; // Skip the current iteration
    }
    // Code to be executed
}
```

- `condition`: The condition under which you want to skip the current iteration.

### Example
```cpp
#include <iostream>

int main() {
    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            continue; // Skip iteration when i equals 3
        }
        std::cout << "Number: " << i << std::endl;
    }

    return 0;
}
```

In this example, the `continue` statement skips the iteration when `i` equals 3, resulting in the number 3 being omitted from the output.

## The `break` Statement
The `break` statement is used to exit a loop prematurely when a certain condition is met. It allows you to terminate the loop before it reaches its normal exit condition.

### Syntax
```cpp
for (int i = 0; i < n; i++) {
    if (condition) {
        break; // Exit the loop
    }
    // Code to be executed
}
```

- `condition`: The condition that triggers the exit from the loop.

### Example
```cpp
#include <iostream>

int main() {
    int i = 1;
    while (true) {
        if (i > 5) {
            break; // Exit the loop when i exceeds 5
        }
        std::cout << "Number: " << i << std::endl;
        i++;
    }

    return 0;
}
```

In this example, the `break` statement is used to exit the `while` loop when `i` exceeds 5, preventing an infinite loop.

## Common Use Cases
- **`continue` Statement**: It is used when you want to skip certain iterations of a loop based on a condition. For example, skipping processing for invalid data in a collection.

- **`break` Statement**: It is used when you want to exit a loop early based on a specific condition. For example, stopping a search or iteration when the desired result is found.

## Conclusion
The `continue` and `break` statements are valuable control flow constructs in C++. They provide you with the ability to fine-tune the behavior of loops, making your code more efficient and expressive.


