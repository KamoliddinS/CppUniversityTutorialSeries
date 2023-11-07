
# Handling Multiple Exceptions

Exception handling is a fundamental part of C++ that allows for the management of unexpected events during program execution. Multiple exceptions may occur, and handling each specific case elegantly is crucial for robust software development.

## Overview

A function may throw different types of exceptions based on the error conditions. When such a function is called, the calling code should be prepared to handle each possible exception in an appropriate manner.

## The try-catch Block

Multiple exceptions are handled using multiple `catch` blocks associated with a single `try` block. Each `catch` block is designed to handle a specific type of exception.

## Catching Standard Exceptions

The C++ Standard Library provides a hierarchy of exception classes that can be caught and handled. The catch blocks should be ordered from the most derived exceptions to the least derived ones.

### Example:

```cpp
try {
    // Code that may throw multiple exceptions
} catch (const std::overflow_error& e) {
    // Handle overflow exceptions
} catch (const std::runtime_error& e) {
    // Handle all runtime_errors not caught by more derived blocks
} catch (const std::exception& e) {
    // Catch all other standard exceptions
}
```

### Explanation

- The `try` block contains the code that may throw exceptions.
- The first `catch` block catches `std::overflow_error`, a specific standard exception.
- The subsequent `catch` block catches `std::runtime_error` which is a more general type than `std::overflow_error`.
- The last `catch` block is a generic handler for any exception derived from `std::exception`.

## Catching Custom Exceptions

If you have defined custom exceptions, you can catch them in the same way you catch standard exceptions.

### Example:

```cpp
try {
    // Code that may throw custom exceptions
} catch (const MyNotFoundException& e) {
    // Handle not found exceptions
} catch (const MyDatabaseException& e) {
    // Handle database related exceptions
} catch (...) {
    // Catch all other exceptions
}
```

### Explanation

- Custom exceptions like `MyNotFoundException` and `MyDatabaseException` are caught in their respective catch blocks.
- The catch-all handler `catch (...)` is a failsafe for any exception that does not match the previous handlers.

## Catch Blocks Ordering

It's important to order catch blocks correctly; if a catch block for a more general exception precedes one for a more specific exception, the more general block will catch exceptions of both types, and the more specific block will never be executed.

### Incorrect Example:

```cpp
try {
    // ...
} catch (const std::exception& e) {
    // This will catch all exceptions derived from std::exception
} catch (const std::runtime_error& e) {
    // This block will never be reached
}
```

## Best Practices

- Always catch exceptions by reference, preferably by const reference, to avoid slicing and unnecessary copies.
- Order your catch blocks from the most specific to the least specific to ensure that each exception is caught by its corresponding handler.
- Include a catch-all handler only if you have a good reason to catch unknown exceptions, and log them for debugging purposes.

## Conclusion

Handling multiple exceptions is about expecting the unexpected in a structured way. By utilizing a series of well-planned `catch` blocks, you can ensure that your C++ applications handle errors gracefully and maintain reliability even when facing multiple failure modes.

