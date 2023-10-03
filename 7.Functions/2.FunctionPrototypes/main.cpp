#include <iostream>

// Function prototype
double calculateRectangleArea(double length, double width);

int main() {
    // Call the calculateRectangleArea function
    double length = 5.0;
    double width = 3.0;
    
    // Function call using the prototype
    double area = calculateRectangleArea(length, width);
    
    // Display the result
    std::cout << "Rectangle Area: " << area << std::endl;
    
    return 0;
}

// Function definition
double calculateRectangleArea(double length, double width) {
    // Function implementation
    double area = length * width;
    return area;
}
