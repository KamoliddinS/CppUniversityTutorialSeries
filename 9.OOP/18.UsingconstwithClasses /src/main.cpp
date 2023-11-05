#include <iostream>

class Rectangle {
private:
    const double length; // const member variable
    const double width;  // const member variable

public:
    // Constructor with initializer list to set the const members
    Rectangle(double len, double wid) : length(len), width(wid) {}

    // A const member function that calculates the area of the rectangle.
    // This function does not modify any member variables.
    double area() const {
        return length * width;
    }

    // A const member function that calculates the perimeter
    // This function does not modify any member variables.
    double perimeter() const {
        return 2 * (length + width);
    }

    // Accessor for length that does not modify the object
    double getLength() const {
        return length;
    }

    // Accessor for width that does not modify the object
    double getWidth() const {
        return width;
    }

    // This function attempts to modify a const member variable, which is illegal
    // and will cause a compile-time error if uncommented.
    // void setLength(double len) {
    //     length = len; // Error: cannot assign to a variable that is const
    // }
};

int main() {
    Rectangle rect(10.0, 5.0); // Create a Rectangle object

    // Output the area of the rectangle
    std::cout << "Area of the rectangle: " << rect.area() << std::endl;

    // Output the perimeter of the rectangle
    std::cout << "Perimeter of the rectangle: " << rect.perimeter() << std::endl;

    // Attempting to change the rectangle's dimensions is not allowed by the class design
    // rect.setLength(20.0); // Uncommenting this will result in a compile error

    return 0;
}
