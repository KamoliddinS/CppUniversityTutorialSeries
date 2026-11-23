#include <iostream>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const { return 0.0; }
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {}
    double area() const override { return 3.14159 * radius_ * radius_; }

private:
    double radius_ = 0.0;
};

void byReference(const Shape& shape) {
    std::cout << "By reference: " << shape.area() << '\n';
}

void byValue(Shape shape) {   // a copy of the Shape part only
    std::cout << "By value: " << shape.area() << '\n';
}

int main() {
    Circle circle(1.0);
    byReference(circle);
    byValue(circle);
}
