#include <iostream>
#include <memory>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {}
    double area() const override { return 3.14159 * radius_ * radius_; }
    double radius() const { return radius_; }   // only circles have a radius

private:
    double radius_ = 0.0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}
    double area() const override { return width_ * height_; }

private:
    double width_ = 0.0;
    double height_ = 0.0;
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(2.0));
    shapes.push_back(std::make_unique<Rectangle>(3.0, 4.0));

    for (const std::unique_ptr<Shape>& shape : shapes) {
        const Circle* circle = dynamic_cast<const Circle*>(shape.get());
        if (circle != nullptr) {
            std::cout << "A circle with radius " << circle->radius() << '\n';
        } else {
            std::cout << "Not a circle\n";
        }
    }
}
