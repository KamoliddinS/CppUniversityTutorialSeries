// Filename: AbstractClassesAndPolymorphism.cpp
// Compile with: g++ AbstractClassesAndPolymorphism.cpp -o AbstractClassesAndPolymorphism

#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr

// Abstract base class with a pure virtual function
class GraphicObject {
public:
    virtual void draw() const = 0; // Pure virtual function making this an abstract class

    virtual ~GraphicObject() {
        std::cout << "GraphicObject destroyed." << std::endl;
    }
};

// Derived class Circle
class Circle : public GraphicObject {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }

    ~Circle() {
        std::cout << "Circle destroyed." << std::endl;
    }
};

// Derived class Square
class Square : public GraphicObject {
public:
    void draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }

    ~Square() {
        std::cout << "Square destroyed." << std::endl;
    }
};

// Function to draw a graphic object
void drawGraphicObject(const GraphicObject& obj) {
    obj.draw(); // Polymorphic call to the draw method
}

int main() {
    // Polymorphism can be achieved with pointers or references to the abstract base class
    std::unique_ptr<GraphicObject> circle = std::make_unique<Circle>();
    std::unique_ptr<GraphicObject> square = std::make_unique<Square>();

    // Using the function to draw different objects
    drawGraphicObject(*circle); // Outputs: Drawing a circle.
    drawGraphicObject(*square); // Outputs: Drawing a square.

    return 0;
}

