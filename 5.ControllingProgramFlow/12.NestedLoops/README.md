
# Nested Loops in C++

## Objective
In this lesson, we will explore the concept of nested loops in C++. Nested loops are loops within other loops, and they are a powerful tool for solving complex problems and working with multi-dimensional data structures.

## What Are Nested Loops?
Nested loops, as the name suggests, are loops that are placed inside other loops. They allow you to perform repetitive tasks within repetitive tasks. In C++, you can nest loops of different types, such as `for`, `while`, or `do-while`, within one another.

### Syntax
The basic syntax of a nested loop looks like this:

```cpp
for (int i = 0; i < outer_limit; i++) {
    // Outer loop code

    for (int j = 0; j < inner_limit; j++) {
        // Inner loop code
    }
}
```

- The outer loop controls the execution of the entire set of inner loops.
- The inner loop performs a specific task repeatedly for each iteration of the outer loop.

## Example: Multiplication Table
One common use of nested loops is to generate a multiplication table. Here's an example that prints a multiplication table for numbers 1 to 5:

```cpp
#include <iostream>

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            std::cout << i << " x " << j << " = " << (i * j) << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

In this example, we have an outer loop that iterates through numbers 1 to 5 (`i`), and an inner loop that iterates through numbers 1 to 5 (`j`). For each combination of `i` and `j`, we calculate and print the product.

## Common Use Cases
Nested loops are used in various scenarios, including:
- **Multi-dimensional Data**: Accessing and processing multi-dimensional arrays or matrices.
- **Patterns and Shapes**: Creating patterns and shapes using loops within loops.
- **Search and Comparison**: Comparing elements in nested data structures.
- **Simulation**: Modeling complex scenarios that involve multiple iterations.

## Loop Control Statements in Nested Loops
You can use loop control statements like `break` and `continue` in nested loops to alter their behavior:
- **`break`**: Exits the innermost loop when a certain condition is met.
- **`continue`**: Skips the current iteration of the innermost loop and continues with the next iteration.

## Conclusion
Nested loops are a fundamental concept in programming, allowing you to solve complex problems efficiently by breaking them down into simpler tasks. Understanding how to work with nested loops is essential for developing algorithms, simulations, and handling multi-dimensional data structures.


