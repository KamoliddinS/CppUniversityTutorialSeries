#include <iostream>

// Define a struct 'Point'
struct Point {
    int x, y; // Members are public by default

    // Constructor to initialize the Point
    Point(int px, int py) : x(px), y(py) {}

    // Function to print the point
    void print() const {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

// Define a class 'Circle'
class Circle {
    // Members are private by default
    Point center;
    double radius;

public:
    // Constructor to initialize the Circle
    Circle(int x, int y, double r) : center(x, y), radius(r) {}

    // Function to print the circle
    void print() const {
        std::cout << "Circle at ";
        center.print();
        std::cout << " with radius " << radius << std::endl;
    }
};

int main() {
    // Creating a Point object - struct
    Point point(5, 10);
    point.print(); // Accessible directly because 'print' and members are public

    // Creating a Circle object - class
    Circle circle(15, 25, 3.5);
    // circle.center.print(); // This would be an error; 'center' is private
    circle.print(); // Accessible through a public member function

    return 0;
}
