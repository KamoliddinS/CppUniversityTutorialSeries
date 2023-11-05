// Filename: main.cpp
// Compile with: g++ main.cpp -o polymorphism_example

#include <iostream>
#include <vector>

// Abstract base class
class Polygon {
public:
    // Virtual function to be overridden by derived classes
    virtual void draw() const = 0; // Pure virtual function makes this class abstract

    // Virtual destructor to ensure derived class destructors are called
    virtual ~Polygon() {
        std::cout << "Cleaning up Polygon." << std::endl;
    }
};

// Derived class - Triangle
class Triangle : public Polygon {
public:
    void draw() const override {
        std::cout << "Drawing Triangle" << std::endl;
    }

    ~Triangle() {
        std::cout << "Cleaning up Triangle." << std::endl;
    }
};

// Derived class - Rectangle
class Rectangle : public Polygon {
public:
    void draw() const override {
        std::cout << "Drawing Rectangle" << std::endl;
    }

    ~Rectangle() {
        std::cout << "Cleaning up Rectangle." << std::endl;
    }
};

int main() {
    // Vector of base class pointers
    std::vector<Polygon*> polygons;

    // Adding derived class instances to the vector
    polygons.push_back(new Triangle());
    polygons.push_back(new Rectangle());

    // Iterate through the vector and invoke the draw method
    // The specific method called is determined at runtime
    for (Polygon* poly : polygons) {
        poly->draw();
    }

    // Clean up
    for (Polygon* poly : polygons) {
        delete poly; // This will invoke the appropriate destructor
    }

    return 0;
}
