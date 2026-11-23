#include <iostream>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const { return 0.0; }
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {}
    double area() override { return 3.14159 * radius_ * radius_; }   // const is missing

private:
    double radius_ = 0.0;
};

int main() {
    Circle circle(1.0);
    const Shape& shape = circle;
    std::cout << "Area: " << shape.area() << '\n';
}
