
# Polymorphism in C++

Welcome to our Computer Programming with C++ course repository. In this section, we will discuss a fundamental concept of C++ and object-oriented programming: polymorphism.

## What is Polymorphism?

The term "polymorphism" is derived from Greek, meaning "many shapes." In programming, polymorphism gives us the ability to treat objects of different classes in a uniform way. Specifically, it allows objects to be treated as instances of their parent class rather than their actual class.

## Types of Polymorphism in C++

There are two primary types of polymorphism in C++:

1. **Compile-time Polymorphism**: This type is achieved by function overloading or operator overloading.

2. **Runtime Polymorphism**: This is achieved through inheritance and virtual functions, allowing a function to behave differently depending on the object that calls it.

## Example of Polymorphism

Here is a simple example to demonstrate runtime polymorphism:

```cpp
#include <iostream>

class Base {
public:
    virtual void display() {
        std::cout << "Display of Base" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        std::cout << "Display of Derived" << std::endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;

    basePtr = &derivedObj;

    // The call to display will be determined at runtime
    basePtr->display();  // Output: Display of Derived

    return 0;
}
```

In this example, `basePtr` is a pointer of type `Base` but points to an object of type `Derived`. When we call `basePtr->display()`, it calls the `display` method of the `Derived` class, not the `Base` class, due to polymorphism.

## Why Use Polymorphism?

Polymorphism is essential for the following reasons:

- **Code Reusability**: It allows the reuse of code and enables the programmer to write more generic and reusable functions.
- **Modularity**: It helps in building more manageable code by separating different functionalities into different classes.
- **Extensibility**: It makes the codebase more easily extensible to incorporate new features or components.

Feel free to explore the code examples in this repository to see polymorphism in action. If you have any questions or need further clarification, please open an issue, and we'll be happy to help!

Happy Coding!

