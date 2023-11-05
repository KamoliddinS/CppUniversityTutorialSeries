
# Custom Deleters for Smart Pointers in C++

## Introduction

In C++, smart pointers are used to ensure resource management is handled automatically, preventing resource leaks and ensuring that resources are released properly when no longer needed. The standard deleters for `std::unique_ptr` and `std::shared_ptr` call `delete` on the pointer they hold, but there are scenarios where custom behavior is required upon the destruction of the smart pointer. This is where custom deleters come into play.

## Understanding Custom Deleters

A custom deleter is a function or functor that you provide to a smart pointer to invoke when the smart pointer is supposed to release its resource. This can be particularly useful when working with APIs that require specific cleanup functions or for embedding custom logic during the deallocation process.

### Reasons to Use Custom Deleters:

- To interface with C APIs that have specific resource deallocation functions (e.g., `fclose` for file pointers).
- To provide additional logging or processing during resource deallocation.
- To manage non-memory resources that require custom cleanup.

## Syntax and Usage

Here is a basic example of using a custom deleter with `std::unique_ptr`:

```cpp
#include <iostream>
#include <memory>

void customDeleter(int* ptr) {
    std::cout << "Custom deleter called.\n";
    delete ptr;  // Perform the actual deletion
}

int main() {
    std::unique_ptr<int, decltype(&customDeleter)> ptr(new int, customDeleter);
    *ptr = 10;
    return 0; // customDeleter will be called automatically here
}
```

In this example, `decltype(&customDeleter)` is used to deduce the type of the deleter, and `customDeleter` is provided as the deleter to the `std::unique_ptr`. When the `std::unique_ptr` goes out of scope, `customDeleter` is called instead of the default `delete` operator.

## Implementing Custom Deleters

Custom deleters can be implemented in several ways:

- As a function.
- As a functor (an object that overloads the `operator()`).
- Using lambdas (for inline, anonymous custom deleters).

### Function Pointer Deleter

```cpp
void fileCloser(FILE* filePtr) {
    if (filePtr) {
        fclose(filePtr);
        std::cout << "File closed successfully.\n";
    }
}
```

### Functor Deleter

```cpp
struct FileCloser {
    void operator()(FILE* filePtr) const {
        if (filePtr) {
            fclose(filePtr);
            std::cout << "File closed by Functor.\n";
        }
    }
};
```

### Lambda Deleter

```cpp
auto lambdaDeleter = [](FILE* filePtr) {
    if (filePtr) {
        fclose(filePtr);
        std::cout << "File closed by Lambda.\n";
    }
};
```

## Usage with `std::shared_ptr`

Custom deleters can also be used with `std::shared_ptr`. The syntax is similar, but the type of the deleter does not need to be part of the type declaration of the `std::shared_ptr`.

```cpp
std::shared_ptr<FILE> filePtr(fopen("example.txt", "r"), fileCloser);
```

## Conclusion

Custom deleters offer flexibility and control over how resources are cleaned up in smart pointers. They enable smart pointers to be used in a wider range of scenarios beyond default memory deallocation.

## Best Practices

- Use custom deleters to ensure resources are managed safely and efficiently.
- Keep custom deleters stateless when possible, as stateful deleters may increase the size and complexity of smart pointers.
- Avoid capturing pointers or references in lambda deleters that may outlive the captured context.

## Additional Resources

- [C++ Documentation on smart pointers and custom deleters](https://en.cppreference.com/w/cpp/memory)
- [Effective Modern C++ by Scott Meyers](#)

