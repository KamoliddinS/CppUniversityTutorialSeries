
# Lesson: Using If-Else Statements in C++

## Objective
In this lesson, you will learn how to use `if-else` statements in C++ to make decisions and execute different blocks of code based on specified conditions. `if-else` statements are essential for creating more complex branching logic in your programs.

## Prerequisites
Before starting this lesson, make sure you have a basic understanding of C++ syntax, variables, and `if` statements.

## If-Else Statement
The `if-else` statement is an extension of the `if` statement and is used when you want to provide an alternative code block to execute when the initial condition is false.

### Syntax
```cpp
if (condition) {
    // Code to execute when the condition is true
} else {
    // Code to execute when the condition is false
}
```

- `condition`: A Boolean expression that evaluates to either true or false.
- `{}`: Curly braces are used to enclose the code blocks to be executed when the condition is true and false, respectively.

### Example
```cpp
#include <iostream>

int main() {
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num % 2 == 0) {
        std::cout << num << " is even." << std::endl;
    } else {
        std::cout << num << " is odd." << std::endl;
    }

    return 0;
}
```

In this example, if the entered number is even, the message "x is even" will be printed; otherwise, "x is odd" will be printed.

## Nested If-Else Statements
You can also nest `if-else` statements within each other to create more complex conditional logic.

### Syntax
```cpp
if (condition1) {
    // Code to execute when condition1 is true
} else if (condition2) {
    // Code to execute when condition2 is true
} else {
    // Code to execute when neither condition1 nor condition2 is true
}
```

### Example
```cpp
#include <iostream>

int main() {
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num > 0) {
        std::cout << num << " is positive." << std::endl;
    } else if (num < 0) {
        std::cout << num << " is negative." << std::endl;
    } else {
        std::cout << num << " is zero." << std::endl;
    }

    return 0;
}
```

In this example, we check if the number is positive, negative, or zero, and print the corresponding message.

## Conclusion
`if-else` statements are powerful tools for creating decision-making logic in C++. They allow you to execute different blocks of code based on various conditions, making your programs more flexible and responsive to different situations.

In the next lesson, we will explore more advanced conditional constructs and how to use them effectively in your C++ programs.

## Homework
1. Write a C++ program that takes a user's score as input and outputs their letter grade based on the grading scale (e.g., A, B, C, D, F).
2. Experiment with nested `if-else` statements to create more complex branching logic.
