// Exercise 3: More shapes
// Complete the program: follow the four TODO comments.
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;
    virtual std::string name() const = 0;
    virtual double area() const = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}
    std::string name() const override { return "Rectangle"; }
    double area() const override { return width_ * height_; }

private:
    double width_ = 0.0;
    double height_ = 0.0;
};

// TODO 1: write a class Square (one side) that derives from Shape.

// TODO 2: write a class Triangle (base and height) that derives from Shape.
//         Its area is base * height / 2.

void print(const Shape& shape) {
    std::cout << shape.name() << ": " << shape.area() << '\n';
}

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(2.0, 3.0));
    // TODO 3: add a Square with side 4 and a Triangle with base 3 and height 5.

    // TODO 4: call print() for every shape in one loop.
    //         Add up the areas in the same loop and print the total at the end.
}
