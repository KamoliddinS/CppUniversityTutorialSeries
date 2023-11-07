

# Throwing Exceptions from a Function

In this section of our Computer Programming with C++ course, we explore how to throw exceptions from within a function. This is a critical aspect of exception handling, which allows us to signal that an error or unexpected situation has occurred during a function's execution.

## Introduction to Throwing Exceptions

Throwing an exception is the process of signaling an error or other unusual circumstance that has occurred. In C++, this is done using the `throw` keyword, followed by an exception object.

## Why Throw Exceptions?

Exceptions provide a way to react to exceptional circumstances (like runtime errors) in a controlled way. When a function encounters a situation it can't handle:

- It can return an error code (traditional error handling).
- It can handle the situation internally (if possible).
- Or, it can throw an exception, signaling the calling code to handle the situation.

Throwing exceptions allows us to separate error handling from our business logic, making the code cleaner and more maintainable.

## Key Concepts

- **Throwing Exceptions**: The syntax for throwing exceptions, including how to throw standard exceptions and custom exceptions.
- **Exception Propagation**: How exceptions are propagated up the call stack until they are caught by a suitable catch handler.
- **No-Throw Guarantee**: Functions can also provide a guarantee that they won't throw any exceptions, which is important for certain types of applications.

## Throwing Standard Exceptions

C++ standard library provides a set of standard exception classes that can be used to represent common problems. They are all derived from `std::exception`.

### Example: Throwing a Standard Exception

```cpp
#include <iostream>
#include <stdexcept>

void processInput(int input) {
    if (input < 0) {
        // Throw a standard exception if input is negative
        throw std::domain_error("Input must be non-negative");
    }
    // Process the positive input
    std::cout << "Processing input: " << input << std::endl;
}

int main() {
    try {
        processInput(-1);
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    return 0;
}
```

### Explanation

- We have a function `processInput` that throws a `std::domain_error`, which is a standard exception class, when it receives a negative input.
- In the `main` function, we call `processInput` inside a `try` block and provide a `catch` block that catches exceptions of type `std::exception` (the base class for all standard exceptions).

## Throwing Custom Exceptions

Sometimes, the standard exceptions do not fit the error that has occurred. In such cases, we can define our own exception classes.

### Example: Throwing a Custom Exception

```cpp
#include <iostream>
#include <exception>

// Define a custom exception class
class MyException : public std::exception {
public:
    const char* what() const throw() {
        return "Custom Exception: Something went wrong!";
    }
};

void riskyFunction() {
    // Logic that might throw an exception
    throw MyException();
}

int main() {
    try {
        riskyFunction();
    } catch (const MyException& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
```

### Explanation

- A custom exception class `MyException` is defined, which overrides the `what()` method from `std::exception`.
- `riskyFunction` throws an exception of type `MyException`.
- The `main` function contains a try-catch block that specifically catches `MyException`.

## Best Practices

- Only throw exceptions for conditions that are truly exceptional and not expected to occur as part of the normal operation of the program.
- Prefer to throw objects of classes derived from `std::exception`. This ensures compatibility with other C++ code and libraries.
- Catch exceptions by const reference to avoid slicing and unnecessary copying.

## Conclusion

Throwing exceptions from functions is a powerful feature in C++ that allows for robust error handling. It's essential to understand this mechanism to write reliable applications that can handle unexpected events gracefully.

