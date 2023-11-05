// Example of Polymorphism in C++

#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    // Constructor
    Shape() {
        cout << "Shape created" << endl;
    }

    // Virtual function for runtime polymorphism
    virtual void draw() {
        cout << "Drawing a Shape" << endl;
    }

    // Virtual destructor
    virtual ~Shape() {
        cout << "Shape destroyed" << endl;
    }
};

// Derived class
class Circle : public Shape {
public:
    // Overriding the draw function
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

// Another derived class
class Square : public Shape {
public:
    // Overriding the draw function
    void draw() override {
        cout << "Drawing a Square" << endl;
    }
};

// Function to demonstrate compile-time polymorphism (Function Overloading)
void printArea(int length, int width) {
    cout << "Area of Rectangle: " << length * width << endl;
}

void printArea(int side) {
    cout << "Area of Square: " << side * side << endl;
}

int main() {
    // Runtime Polymorphism
    Shape* shape; // Base class pointer
    Circle circle;
    Square square;

    // Pointing to Circle
    shape = &circle;
    shape->draw(); // Calls Circle's draw

    // Pointing to Square
    shape = &square;
    shape->draw(); // Calls Square's draw

    // Compile-time Polymorphism
    printArea(5); // Calls printArea for Square
    printArea(4, 6); // Calls printArea for Rectangle

    return 0;
}
