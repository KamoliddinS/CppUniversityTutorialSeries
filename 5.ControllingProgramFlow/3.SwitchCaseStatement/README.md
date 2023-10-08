
# Lesson: Using Switch Case Statements in C++

## Objective
In this lesson, you will learn how to use the `switch` case statement in C++ to create more efficient and structured alternatives to long chains of `if-else` statements. `switch` statements are particularly useful when you need to compare a variable to multiple constant values.

## Prerequisites
Before starting this lesson, make sure you have a basic understanding of C++ syntax and variables.

## Switch Case Statement
The `switch` case statement allows you to compare a variable's value against multiple constant values and execute code blocks accordingly. It provides a more efficient way to handle multiple choices compared to using a series of `if-else` statements.

### Syntax
```cpp
switch (expression) {
    case constant1:
        // Code to execute when expression equals constant1
        break;
    case constant2:
        // Code to execute when expression equals constant2
        break;
    // Add more cases as needed
    default:
        // Code to execute when expression doesn't match any constant
}
```

- `expression`: The variable or expression to be compared.
- `constant1`, `constant2`, etc.: The constant values to compare `expression` against.
- `break`: Terminates the `switch` statement, preventing fall-through to the next case.
- `default`: Optional. Executed when `expression` doesn't match any of the specified constants.

### Example
```cpp
#include <iostream>

int main() {
    int dayNumber;

    // Prompt the user for a number from 1 to 7
    std::cout << "Enter a number from 1 to 7: ";
    std::cin >> dayNumber;

    // Determine the day of the week based on the number
    switch (dayNumber) {
        case 1:
            std::cout << "Sunday" << std::endl;
            break;
        case 2:
            std::cout << "Monday" << std::endl;
            break;
        case 3:
            std::cout << "Tuesday" << std::endl;
            break;
        case 4:
            std::cout << "Wednesday" << std::endl;
            break;
        case 5:
            std::cout << "Thursday" << std::endl;
            break;
        case 6:
            std::cout << "Friday" << std::endl;
            break;
        case 7:
            std::cout << "Saturday" << std::endl;
            break;
        default:
            std::cout << "Invalid input. Please enter a number from 1 to 7." << std::endl;
    }

    return 0;
}
```

In this example, we use the `switch` statement to determine the message based on the input grade character.

## Benefits of Switch Case
- **Readability**: `switch` statements make the code more readable, especially when comparing a variable against multiple constants.

- **Efficiency**: `switch` statements are generally more efficient than long chains of `if-else` statements, as they can be optimized by the compiler.

- **Structured**: `switch` statements provide a structured way to handle multiple cases and a default case when none of the constants match.

## Conclusion
The `switch` case statement is a valuable tool for handling multiple choices in C++ programming. It offers improved code readability and efficiency when compared to long `if-else` chains.

In the next lesson, we will explore more advanced programming constructs to enhance your C++ skills.

## Homework
1. Write a C++ program that takes a number from 1 to 7 and outputs the corresponding day of the week (e.g., 1 for "Sunday," 2 for "Monday," etc.) using a `switch` statement.
2. Experiment with nested `switch` statements to handle more complex scenarios.
