
# Copy Constructors in C++

In this section of our Computer Programming with C++ course, we will discuss copy constructors, which are a fundamental concept in the creation of object-oriented programs in C++.

## What is a Copy Constructor?

A copy constructor is a special constructor in C++ used to create a new object as a copy of an existing object. Whenever an object is created and initialized by another object of the same class, the copy constructor is called.

## When is a Copy Constructor Called?

A copy constructor is invoked in the following situations:
- When an object is initialized with another object of the same class at the time of creation.
- When an object is passed by value as a parameter.
- When an object is returned by value from a function.
- When an object is thrown or caught in exception handling.

## Syntax of a Copy Constructor

The copy constructor is usually declared as follows:

```cpp
class ClassName {
public:
    ClassName(const ClassName &old_obj);
};
```

Here, `old_obj` is a reference to the object that is being copied.

## Default Copy Constructor

C++ provides a default copy constructor if one is not defined explicitly. The default copy constructor performs a shallow copy, which means it copies all the member values from one object to another.

## Shallow vs Deep Copy

- **Shallow Copy**: This is the approach taken by the default copy constructor. If the object has pointer members, the pointers are copied, not the objects they point to.
- **Deep Copy**: If an object contains pointers to dynamically allocated memory, a deep copy creates copies of the pointed-to data.

## Example of a Custom Copy Constructor

Here's an example that demonstrates defining a custom copy constructor for a simple `StringWrapper` class:

```cpp
#include <iostream>
#include <cstring>

class StringWrapper {
    char *str;

public:
    // Constructor
    StringWrapper(const char *s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy Constructor for deep copy
    StringWrapper(const StringWrapper &source) {
        str = new char[strlen(source.str) + 1];
        strcpy(str, source.str);
        std::cout << "Copy constructor called" << std::endl;
    }

    // Destructor
    ~StringWrapper() {
        delete[] str;
    }

    // Function to display the string
    void print() const {
        std::cout << str << std::endl;
    }
};

int main() {
    StringWrapper original("Hello World");
    StringWrapper copy = original;  // This invokes the copy constructor

    std::cout << "Original: ";
    original.print();

    std::cout << "Copy: ";
    copy.print();

    return 0;
}
```

## Conclusion

A copy constructor is a key part of C++ that ensures objects can be copied in a way that respects the semantics of the object's class, especially when dealing with dynamic memory allocation.

When creating classes that manage resources like dynamic memory or file handles, it is important to define a copy constructor to handle the copying of objects properly.

