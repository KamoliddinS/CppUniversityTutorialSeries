#include <iostream>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;   // pure virtual: every real shape must provide it
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {}
    double area() const override { return 3.14159 * radius_ * radius_; }

private:
    double radius_ = 0.0;
};

void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << '\n';
}

int main() {
    Circle circle(1.0);
    printArea(circle);
}
