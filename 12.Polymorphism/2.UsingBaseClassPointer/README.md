
# Using a Base Class Pointer in Polymorphism

Polymorphism is a cornerstone of object-oriented programming and it allows objects of different classes to be treated through the same interface. One of the key mechanisms to achieve runtime polymorphism in C++ is through the use of base class pointers. This README will delve into the concept and provide a clear understanding of its utility and application in C++.

## Introduction to Base Class Pointers

A base class pointer can point to objects of the base class as well as objects of any derived classes. This feature provides a way to call methods of different derived classes without knowing the exact type of the object at compile time.

## Why Use Base Class Pointers?

The main advantage of using base class pointers is that they enable polymorphic behavior. It allows a single pointer type to iterate over an array of different derived types and call overridden methods without knowing the object's derived type.

## How Does It Work?

Here's a simple breakdown of how base class pointers work in the context of polymorphism:

- Declare a base class with a virtual function.
- Create derived classes that override the virtual function.
- Use a base class pointer to refer to objects of the derived classes.
- Call the virtual function using the base class pointer.

## Code Example

Consider the following simple code snippet that demonstrates using a base class pointer:

```cpp
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    virtual void speak() {
        cout << "Some animal sound" << endl;
    }
    virtual ~Animal() {} // Virtual destructor for proper cleanup
};

// Derived class
class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof!" << endl;
    }
};

// Derived class
class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* myAnimal;

    // Pointing to Dog object
    Dog myDog;
    myAnimal = &myDog;
    myAnimal->speak(); // Outputs: Woof!

    // Pointing to Cat object
    Cat myCat;
    myAnimal = &myCat;
    myAnimal->speak(); // Outputs: Meow!

    return 0;
}
```

In the above example, the `Animal` base class pointer `myAnimal` is used to call the `speak` method on both `Dog` and `Cat` objects. The correct method is called corresponding to the actual object type, even though the pointer type is of the base class `Animal`.

## Conclusion

Using base class pointers is a powerful feature in C++ that leverages polymorphism to create flexible and reusable code. It is widely used in various applications like creating collections of different objects, implementing callback mechanisms, and for applying design patterns.

We encourage you to clone this repository, experiment with the examples, and explore the power of polymorphism in C++.
