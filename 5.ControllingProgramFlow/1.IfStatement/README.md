
# Lesson: Controlling Program Flow with IF Statements

## Objective
In this lesson, you will learn how to use the `if` statement in C++ to control the flow of your programs based on certain conditions. Conditional statements are essential for making decisions and executing code selectively.

## Prerequisites
Before starting this lesson, make sure you have a basic understanding of C++ syntax and variables.

## IF Statement
The `if` statement is used to perform conditional execution of code. It allows you to specify a condition, and if that condition is true, the code inside the `if` block will be executed.

### Syntax
```cpp
if (condition) {
    // Code to execute when the condition is true
}
```

- `condition`: A Boolean expression that evaluates to either true or false.
- `{}`: Curly braces are used to enclose the code block to be executed when the condition is true.

### Example
```cpp
#include <iostream>

int main() {
    int x = 10;

    if (x > 5) {
        std::cout << "x is greater than 5." << std::endl;
    }

    std::cout << "Program continues here." << std::endl;

    return 0;
}
```

In this example, if the condition `x > 5` is true, the message "x is greater than 5" will be printed. Otherwise, it will be skipped, and the program will continue with the next line.

## ELSE Statement
In addition to `if`, you can use the `else` statement to provide an alternative code block to execute when the condition is false.

### Syntax
```cpp
if (condition) {
    // Code to execute when the condition is true
} else {
    // Code to execute when the condition is false
}
```

### Example
```cpp
#include <iostream>

int main() {
    int x = 3;

    if (x > 5) {
        std::cout << "x is greater than 5." << std::endl;
    } else {
        std::cout << "x is not greater than 5." << std::endl;
    }

    std::cout << "Program continues here." << std::endl;

    return 0;
}
```

In this example, since `x` is not greater than 5, the message "x is not greater than 5" will be printed.

## Conclusion
The `if` statement is a fundamental construct in C++ for controlling program flow based on conditions. Combined with the `else` statement, you can make your programs more dynamic and responsive to different situations.

In the next lesson, we will explore more advanced conditional constructs and how to use them effectively in your C++ programs.

## Homework
1. Write a C++ program that takes a user's age as input and outputs whether they are eligible to vote (18 years or older) or not.
2. Experiment with nested `if` statements to create more complex conditions and branching logic.

