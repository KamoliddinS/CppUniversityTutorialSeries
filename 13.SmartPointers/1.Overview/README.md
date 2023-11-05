
# Computer Programming with C++: Smart Pointers Overview

Welcome to the Smart Pointers module of the Computer Programming with C++ Course! This repository is dedicated to providing an overview of smart pointers in C++, a powerful feature that helps in managing dynamic memory.

## What are Smart Pointers?

Smart pointers are a key feature of C++ that enable automatic memory management. When using dynamic memory allocation, it's crucial to deallocate memory that is no longer needed to avoid memory leaks. Smart pointers help by automatically managing the lifetime of objects that they point to.

## Types of Smart Pointers in C++

C++11 introduced three types of smart pointers, which are defined in the `<memory>` header:

### `std::unique_ptr`

`std::unique_ptr` is a smart pointer that owns and manages another object through a pointer and disposes of that object when the `unique_ptr` goes out of scope.

Example:
```cpp
#include <memory>

int main() {
    std::unique_ptr<int> ptr(new int(10));
    // Use *ptr...
    // No need to delete, automatically cleaned up when out of scope.
}
```

### `std::shared_ptr`

`std::shared_ptr` is a smart pointer that retains shared ownership of an object through a pointer. Several `shared_ptr` objects may own the same object, and the object is destroyed when the last remaining `shared_ptr` owning it is destroyed or reset.

Example:
```cpp
#include <memory>

int main() {
    std::shared_ptr<int> ptr1(new int(20));
    std::shared_ptr<int> ptr2 = ptr1; // Both point to the same memory.
    // Use *ptr1 or *ptr2...
    // Memory will be freed when last shared_ptr is out of scope.
}
```

### `std::weak_ptr`

`std::weak_ptr` is a smart pointer that holds a non-owning ("weak") reference to an object that is managed by `std::shared_ptr`. It must be converted to `std::shared_ptr` in order to access the referenced object.

Example:
```cpp
#include <memory>

int main() {
    std::shared_ptr<int> sharedPtr(new int(30));
    std::weak_ptr<int> weakPtr(sharedPtr);
    // Use weakPtr.lock() to get a shared_ptr when needed.
    // Memory is not affected by weak_ptr's scope.
}
```

## Why Use Smart Pointers?

- **Automatic Memory Management**: Smart pointers help prevent memory leaks by ensuring that memory is properly deallocated when it is no longer in use.
- **Exception Safety**: Smart pointers can help protect against memory leaks in the presence of exceptions by ensuring that resources are released appropriately when an exception occurs.
- **Ownership Semantics**: They encode the ownership rules directly into the type system, making the programmer's intent clear and reducing the risk of errors.

## Best Practices

- Prefer to use `std::make_unique` and `std::make_shared` to create smart pointers whenever possible.
- Avoid using raw pointers in combination with smart pointers to prevent confusion over ownership.
- Be cautious with `std::shared_ptr` as it can lead to circular references and memory leaks if not used carefully.

