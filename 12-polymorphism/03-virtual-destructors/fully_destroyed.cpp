#include <iostream>
#include <memory>

class Shape {
public:
    virtual ~Shape() { std::cout << "Shape destroyed\n"; }   // virtual: the fix
    virtual double area() const { return 0.0; }
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {}
    ~Circle() { std::cout << "Circle destroyed\n"; }
    double area() const override { return 3.14159 * radius_ * radius_; }

private:
    double radius_ = 0.0;
};

int main() {
    std::unique_ptr<Shape> shape = std::make_unique<Circle>(1.0);
    std::cout << "Area: " << shape->area() << '\n';
}   // the unique_ptr deletes the Circle here, through a Shape*
