#include <iostream>
#include <cmath> // For M_PI constant used in area of Circle

// Rectangle class definition
class Rectangle {
private:
    int width, height;

public:
    // Constructor to initialize the Rectangle with width and height
    Rectangle(int w, int h) : width(w), height(h) {}

    // Member method to calculate the area of the Rectangle
    int area() {
        return width * height;
    }

    // Member method to calculate the perimeter of the Rectangle
    int perimeter() {
        return 2 * (width + height);
    }

    // Member method to set the dimensions of the Rectangle
    void setDimensions(int w, int h) {
        width = w;
        height = h;
    }
};

// Circle class definition
class Circle {
private:
    double radius;

public:
    // Constructor to initialize the Circle with radius
    Circle(double r) : radius(r) {}

    // Member method to calculate the area of the Circle
    double area() {
        return M_PI * radius * radius; // M_PI is from cmath library
    }
};

// Main function
int main() {
    // Create a Rectangle object
    Rectangle rect(10, 20);
    std::cout << "Rectangle Area: " << rect.area() << std::endl;
    std::cout << "Rectangle Perimeter: " << rect.perimeter() << std::endl;

    // Update Rectangle dimensions
    rect.setDimensions(15, 25);
    std::cout << "Updated Rectangle Area: " << rect.area() << std::endl;
    std::cout << "Updated Rectangle Perimeter: " << rect.perimeter() << std::endl;

    // Create a Circle object
    Circle circle(5);
    std::cout << "Circle Area: " << circle.area() << std::endl;

    return 0;
}
