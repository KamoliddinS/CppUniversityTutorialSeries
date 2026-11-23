#include <iostream>

class Shape {
public:
    ~Shape() { std::cout << "Shape destroyed\n"; }   // not virtual
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
    Shape* shape = new Circle(1.0);
    std::cout << "Area: " << shape->area() << '\n';
    delete shape;   // through a Shape*: which destructor runs?
}
