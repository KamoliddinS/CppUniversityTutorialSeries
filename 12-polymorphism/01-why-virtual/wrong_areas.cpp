#include <iostream>
#include <vector>

class Shape {
public:
    double area() const { return 0.0; }
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {}
    double area() const { return 3.14159 * radius_ * radius_; }

private:
    double radius_ = 0.0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}
    double area() const { return width_ * height_; }

private:
    double width_ = 0.0;
    double height_ = 0.0;
};

int main() {
    Circle circle(1.0);
    Rectangle rectangle(2.0, 3.0);
    std::cout << "Direct call: " << circle.area() << '\n';

    std::vector<const Shape*> shapes = {&circle, &rectangle};
    for (const Shape* shape : shapes) {
        std::cout << "In the loop: " << shape->area() << '\n';   // which area()?
    }
}
