class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

int main() {
    Shape shape;   // an object of an abstract class
}
