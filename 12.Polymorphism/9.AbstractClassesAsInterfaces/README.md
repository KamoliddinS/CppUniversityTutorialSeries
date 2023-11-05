
# Pure Virtual Functions and Abstract Classes in Polymorphism

In object-oriented programming, polymorphism allows objects of different classes to be treated as objects of a common base class. One of the mechanisms to enforce polymorphism in C++ is through the use of pure virtual functions and abstract classes. This document provides an introduction to these concepts and their role in enabling polymorphism.

## What is a Pure Virtual Function?

A pure virtual function is a function declared in a base class that has no definition within that base class. The syntax for a pure virtual function is:

```cpp
virtual ReturnType FunctionName(Parameters...) = 0;
```

The `= 0` syntax specifies that the function has no body and must be overridden by any concrete subclass. A class that contains at least one pure virtual function is considered an abstract class.

## What is an Abstract Class?

An abstract class serves as a blueprint for other classes. It cannot be instantiated directly, which means you cannot create objects of an abstract class. Instead, it must be derived from, and its pure virtual functions must be defined in the derived classes.

## The Role of Abstract Classes in Polymorphism

Abstract classes are used to define interfaces, i.e., sets of functions that derived classes must implement. This allows for consistent interfaces while permitting varied implementations. When a function accepts a reference or pointer to an abstract class, it can interact with any concrete subclass through the interface defined by the abstract class.

## Benefits of Using Abstract Classes

- **Consistency**: Abstract classes provide a clear contract for subclasses. This contract ensures that all subclasses implement the same interface.
- **Flexibility**: While enforcing an interface, abstract classes allow for varying implementations, which can be swapped out seamlessly at runtime.
- **Safety**: Since you cannot instantiate an abstract class, it prevents the misuse of the base class on its own.

## Example: Shapes Drawing Application

Consider an application that draws different shapes:

```cpp
#include <iostream>
#include <vector>

// Abstract base class Shape with a pure virtual function draw
class Shape {
public:
    virtual void draw() const = 0; // Pure virtual function

    virtual ~Shape() {} // A virtual destructor ensures proper cleanup of derived objects
};

// Derived class Circle
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

// Derived class Square
class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }
};

// A function to draw all shapes
void drawAllShapes(const std::vector<Shape*>& shapes) {
    for (const Shape* shape : shapes) {
        shape->draw();  // Dynamic dispatch to the actual object's draw method
    }
}

int main() {
    Circle circle;
    Square square;

    std::vector<Shape*> shapes = {&circle, &square};
    drawAllShapes(shapes);  // Draws all the shapes

    return 0;
}
```

In the example above, `Shape` is an abstract class with a pure virtual function `draw()`. Both `Circle` and `Square` are concrete classes that derive from `Shape` and implement the `draw()` function. The `drawAllShapes` function demonstrates polymorphism by accepting a vector of `Shape` pointers and invoking `draw()` on each shape, regardless of its concrete type.

## Conclusion

Pure virtual functions and abstract classes are essential for enforcing a polymorphic interface in C++. They ensure that each derived class adheres to a certain contract while allowing for diverse implementations. This encourages cleaner and more modular code design and is a staple in robust C++ programming.

For more detailed explanations, use cases, and examples, please refer to the source code files and exercises provided in this repository.
