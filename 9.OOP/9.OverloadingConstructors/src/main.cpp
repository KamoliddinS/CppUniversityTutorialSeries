#include <iostream>

// Define a class named 'Rectangle'
class Rectangle {
private:
    double width;
    double height;

public:
    // Default constructor
    // Initializes both width and height to 1.0 if no arguments are provided
    Rectangle() : width(1.0), height(1.0) {
        std::cout << "Default constructor called: width and height set to 1.0" << std::endl;
    }

    // Constructor with two parameters
    // Allows for the creation of a rectangle with specified width and height
    Rectangle(double w, double h) : width(w), height(h) {
        std::cout << "Parameterized constructor called: width = " << w << ", height = " << h << std::endl;
    }

    // Constructor with a single double parameter
    // Allows for the creation of a square where width and height are the same
    Rectangle(double side) : width(side), height(side) {
        std::cout << "Square constructor called: side = " << side << std::endl;
    }

    // Destructor
    ~Rectangle() {
        std::cout << "Destructor called for rectangle: width = " << width << ", height = " << height << std::endl;
    }

    // A member function to calculate the area of the rectangle
    double area() const {
        return width * height;
    }
};

int main() {
    // Create an instance using the default constructor
    Rectangle rect1;
    std::cout << "Area of rect1: " << rect1.area() << std::endl;

    // Create an instance using the parameterized constructor
    Rectangle rect2(3.0, 4.0);
    std::cout << "Area of rect2: " << rect2.area() << std::endl;

    // Create an instance using the constructor that takes a single double parameter (square)
    Rectangle square(5.0);
    std::cout << "Area of square: " << square.area() << std::endl;

    return 0;
}
