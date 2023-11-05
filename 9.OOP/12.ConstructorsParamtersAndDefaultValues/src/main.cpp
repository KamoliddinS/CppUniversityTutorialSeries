#include <iostream>
#include <string>

// Define a class named 'Rectangle'
class Rectangle {
private:
    int width;
    int height;

public:
    // Constructor with default values for width and height
    Rectangle(int w = 1, int h = 1) : width(w), height(h) {
        std::cout << "Rectangle created with width " << width << " and height " << height << std::endl;
    }

    // Member function to calculate the area of the rectangle
    int area() const {
        return width * height;
    }

    // Member function to print the dimensions of the rectangle
    void printDimensions() const {
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }
};

int main() {
    // Creating objects with different sets of parameters
    Rectangle rect1;                  // Will use default values for both parameters
    Rectangle rect2(5);               // Will use default height
    Rectangle rect3(4, 3);            // No defaults used

    std::cout << "Area of rect1: " << rect1.area() << std::endl;
    rect1.printDimensions();

    std::cout << "Area of rect2: " << rect2.area() << std::endl;
    rect2.printDimensions();

    std::cout << "Area of rect3: " << rect3.area() << std::endl;
    rect3.printDimensions();

    return 0;
}
