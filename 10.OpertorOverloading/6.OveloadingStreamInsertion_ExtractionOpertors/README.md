
# Overloading the Stream Insertion and Extraction Operators

This section of the repository provides guidelines and examples for overloading the stream insertion (`<<`) and extraction (`>>`) operators in C++. These operators are commonly overloaded to perform input and output operations on user-defined types in a way that is consistent with the standard input/output operations provided by C++ for built-in types.

## Overview

Overloading these operators allows for seamless integration of custom types with the C++ Standard Library's I/O facilities, such as `std::cout` for console output and `std::cin` for console input.

## Learning Objectives

- Learn to implement operator overloading for custom I/O operations.
- Understand best practices for overloading `<<` and `>>`.
- Practice writing non-member functions to maintain encapsulation and utilize the friend keyword when necessary.

## Syntax for Overloading I/O Operators

For a class `ClassName`, the overloading syntax for the stream insertion and extraction operators would look like this:

```cpp
// Overload the stream insertion operator for ClassName
std::ostream& operator<<(std::ostream& out, const ClassName& obj);

// Overload the stream extraction operator for ClassName
std::istream& operator>>(std::istream& in, ClassName& obj);
```

## Best Practices

- Always return the stream (`std::ostream` or `std::istream`) by reference to allow chaining of operator calls.
- For `operator<<`, use `const` for the object being streamed to prevent modification.
- The `operator>>` should handle input errors and possibly set the stream's failbit.

## Example

Below is an example of overloading these operators for a simple `Person` class:

```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor
    Person(std::string name = "", int age = 0) : name(name), age(age) {}

    // Friend declaration for the I/O operators
    friend std::ostream& operator<<(std::ostream& out, const Person& person);
    friend std::istream& operator>>(std::istream& in, Person& person);
};

// Stream insertion operator
std::ostream& operator<<(std::ostream& out, const Person& person) {
    out << "Person(Name: " << person.name << ", Age: " << person.age << ")";
    return out;
}

// Stream extraction operator
std::istream& operator>>(std::istream& in, Person& person) {
    in >> person.name >> person.age;
    return in;
}
```

