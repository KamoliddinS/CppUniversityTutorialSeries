
# The `do-while` Loop in C++

## Objective
In this lesson, we will explore the `do-while` loop in C++. The `do-while` loop is a type of loop that executes a block of code repeatedly as long as a specified condition is true. Unlike the `for` and `while` loops, the `do-while` loop ensures that the code block is executed at least once before checking the condition.

## `do-while` Loop Syntax
The syntax of the `do-while` loop is as follows:

```cpp
do {
    // Code to be executed
} while (condition);
```

- `condition`: The Boolean expression that determines whether the loop should continue. The loop will execute as long as this condition is true.

## Example
```cpp
#include <iostream>

int main() {
    int count = 1;

    // Using a do-while loop to print numbers from 1 to 5
    do {
        std::cout << "Number: " << count << std::endl;
        count++;
    } while (count <= 5);

    return 0;
}
```

In this example, the `do-while` loop prints numbers from 1 to 5. Even though the condition is checked at the end of the loop, the code block is executed at least once.

## Common Use Cases
The `do-while` loop is suitable for various programming scenarios:

- **Input Validation**: It can be used for input validation, ensuring that user input meets specific criteria.
- **Menu-Driven Programs**: `do-while` loops are often used in menu-driven programs to repeatedly display options to the user.
- **Game Loops**: In game development, `do-while` loops can handle game logic loops that run until a game over condition is met.

## Loop Control Statements in `do-while` Loops
Inside a `do-while` loop, you can use loop control statements like `break` and `continue` to alter the loop's behavior, similar to other types of loops.

- **`break`**: Exits the loop prematurely when a certain condition is met.
- **`continue`**: Skips the current iteration of the loop and continues with the next iteration.

## Conclusion
The `do-while` loop in C++ is a valuable construct for scenarios where you need to ensure that a code block is executed at least once, even before checking the loop condition. It is useful in input validation, menu-driven programs, and game development loops.

