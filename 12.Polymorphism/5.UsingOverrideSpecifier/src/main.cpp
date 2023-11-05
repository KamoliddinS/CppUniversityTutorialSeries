// Filename: OverrideSpecifierDemo.cpp
// Compile with: g++ OverrideSpecifierDemo.cpp -o OverrideSpecifierDemo

#include <iostream>
#include <vector>
#include <memory>

// Base class with a virtual function
class Shape {
public:
    // Virtual draw function to be overridden by derived classes
    virtual void draw() const {
        std::cout << "Drawing a generic shape." << std::endl;
    }

    // Virtual destructor for safe polymorphic use
    virtual ~Shape() {
        std::cout << "Shape destroyed." << std::endl;
    }
};

// Derived class Circle
class Circle : public Shape {
public:
    // Override specifier ensures this method correctly overrides the base class method
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }

    ~Circle() {
        std::cout << "Circle destroyed." << std::endl;
    }
};

// Derived class Square
class Square : public Shape {
public:
    // This will compile without issue, it's an override of the base class draw method
    void draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }

    ~Square() {
        std::cout << "Square destroyed." << std::endl;
    }
};

// Derived class Triangle
class Triangle : public Shape {
public:
    // This will also compile correctly, it's an override of the base class draw method
    void draw() const override {
        std::cout << "Drawing a triangle." << std::endl;
    }

    ~Triangle() {
        std::cout << "Triangle destroyed." << std::endl;
    }
};

int main() {
    // Create a vector of unique pointers to Shapes
    std::vector<std::unique_ptr<Shape>> shapes;

    // Add different shapes to the vector
    shapes.push_back(std::make_unique<Circle>());
    shapes.push_back(std::make_unique<Square>());
    shapes.push_back(std::make_unique<Triangle>());

    // Iterate over the vector and draw the shapes
    // The correct draw() method is called due to polymorphism and the override specifier
    for (const auto& shape : shapes) {
        shape->draw();
    }

    // The vector and its shapes are automatically cleaned up when going out of scope
    return 0;
}
