#include <iostream>

class Shape {       // interface: anything that has an area
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Printable {   // interface: anything that can print itself
public:
    virtual ~Printable() = default;
    virtual void print() const = 0;
};

class Circle : public Shape, public Printable {
public:
    explicit Circle(double radius) : radius_(radius) {}
    double area() const override { return 3.14159 * radius_ * radius_; }
    void print() const override { std::cout << "Circle with radius " << radius_ << '\n'; }

private:
    double radius_ = 0.0;
};

void show(const Printable& item) {
    item.print();
}

void measure(const Shape& shape) {
    std::cout << "Area: " << shape.area() << '\n';
}

int main() {
    Circle circle(1.0);
    show(circle);      // a Circle is a Printable
    measure(circle);   // and it is a Shape
}
