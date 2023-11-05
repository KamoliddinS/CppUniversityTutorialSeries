# Computer Programming with C++: Inheritance Overview

Welcome to the "Computer Programming with C++" course repository! This section provides an overview of inheritance, a fundamental concept in C++ and object-oriented programming (OOP).

## What is Inheritance?

Inheritance is a mechanism in C++ that allows one class (called a derived or child class) to inherit attributes and methods from another class (called a base or parent class). It's a way to form new classes using classes that have already been defined. The primary goal of inheritance is to provide code reusability and establish a relationship between different classes.

## Key Concepts

- **Base Class (Parent Class):** The class whose properties and functions can be inherited.
- **Derived Class (Child Class):** The class that inherits from another class.
- **Single Inheritance:** When a class inherits from only one base class.
- **Multiple Inheritance:** When a class inherits from more than one base class.

## Syntax

Here's a simple syntax for defining a derived class from a single base class:

```cpp
class BaseClass {
  // Base class members
};

class DerivedClass : public BaseClass {
  // Derived class members
};
```

## Types of Inheritance in C++

1. **Single Inheritance:** Deriving a new class from a single parent class.
2. **Multiple Inheritance:** Deriving a new class from more than one parent class.
3. **Hierarchical Inheritance:** Multiple classes are derived from a single base class.
4. **Multilevel Inheritance:** Deriving a class from another derived class.
5. **Hybrid Inheritance:** A combination of two or more types of inheritance.

## Access Specifiers

Inheritance in C++ is controlled by three access specifiers:

- `public`: Members of the base class are public in the derived class.
- `protected`: Members of the base class are protected in the derived class.
- `private`: Members of the base class are private in the derived class.

## Advantages of Inheritance

- **Code Reusability:** Reuse attributes and methods of the existing class when creating a new class.
- **Method Overriding:** Redefine the base class's methods in the derived class.
- **Polymorphism:** Allows us to use the same interface for different underlying forms (data types).

## Example

Below is a simple example of inheritance in C++:

```cpp
#include <iostream>

// Base class
class Animal {
public:
    void speak() {
        std::cout << "Some sound" << std::endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void speak() {
        std::cout << "Woof woof!" << std::endl;
    }
};

int main() {
    Dog myDog;
    myDog.speak();  // Output: Woof woof!
    return 0;
}
```

In this example, `Dog` is a derived class that inherits from the `Animal` base class. We have overridden the `speak` method in the `Dog` class to provide a more specific implementation.

## Conclusion

Inheritance is a powerful feature of C++ that promotes code reusability and logical relationships among classes. It's a cornerstone of OOP and essential for creating complex software systems with C++. Explore this repository for more examples and exercises related to inheritance.

