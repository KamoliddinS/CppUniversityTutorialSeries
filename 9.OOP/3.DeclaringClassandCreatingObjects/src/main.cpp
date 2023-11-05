#include <iostream>

// Step 1: Declare the Rectangle class
class Rectangle {
public:
    // Properties
    double length;
    double width;

    // Default constructor
    Rectangle() : length(1), width(1) {}  // Initialize with default values

    // Method to calculate area
    double calculateArea() {
        return length * width;
    }

    // Method to calculate perimeter
    double calculatePerimeter() {
        return 2 * (length + width);
    }
};

// Main function
int main() {
    // Step 2: Create an object of the Rectangle class
    Rectangle myRectangle;

    // Step 3: Assign values to properties
    std::cout << "Enter length of rectangle: ";
    std::cin >> myRectangle.length;

    std::cout << "Enter width of rectangle: ";
    std::cin >> myRectangle.width;

    // Step 4: Call methods on the object
    double area = myRectangle.calculateArea();
    double perimeter = myRectangle.calculatePerimeter();

    // Step 5: Output the results
    std::cout << "Area of the rectangle: " << area << std::endl;
    std::cout << "Perimeter of the rectangle: " << perimeter << std::endl;

    return 0;
}
