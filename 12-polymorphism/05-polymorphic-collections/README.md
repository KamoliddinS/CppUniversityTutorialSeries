# Polymorphic collections

> **Goal:** keep different kinds of objects in one `std::vector` and handle them all in one loop.

## A vector of owning pointers

A `std::vector<Shape>` cannot hold a `Circle`. Each element has room for a `Shape` only, so
a circle would be sliced; with an abstract `Shape`, `push_back` does not even compile.
Store pointers instead. A `std::unique_ptr<Shape>` owns its object and deletes it for you
([unique_ptr](../../10-resource-management/05-unique-ptr/README.md)).

**`shapes.cpp`**
<!-- file: shapes.cpp -->
```cpp
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

void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << '\n';
}

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(2.0));
    shapes.push_back(std::make_unique<Rectangle>(3.0, 4.0));

    for (const std::unique_ptr<Shape>& shape : shapes) {
        printArea(*shape);
    }
}
```

<!-- output: shapes -->
```text
Area: 12.5664
Area: 12
```

- `std::make_unique<Circle>(2.0)` creates a `Circle` on the heap. The vector stores it as a
  `std::unique_ptr<Shape>`.
- The loop takes each element by reference, because a `unique_ptr` cannot be copied.
- `*shape` is the object itself. `printArea` takes a `const Shape&`, so it works for every
  shape, also for kinds you write later.
- When `shapes` is destroyed, every object is deleted through a `Shape*`. The virtual
  destructor makes that correct.

## Ask for the real type

Rarely you need something that only one kind has, such as the radius of a circle.
[`find_circles.cpp`](find_circles.cpp) has the same classes, plus a `radius()` function in
`Circle`:

<!-- snippet: find_circles.cpp -->
```cpp
    for (const std::unique_ptr<Shape>& shape : shapes) {
        const Circle* circle = dynamic_cast<const Circle*>(shape.get());
        if (circle != nullptr) {
            std::cout << "A circle with radius " << circle->radius() << '\n';
        } else {
            std::cout << "Not a circle\n";
        }
    }
```

<!-- output: find_circles -->
```text
A circle with radius 2
Not a circle
```

`shape.get()` is the plain `Shape*` inside the `unique_ptr`. **`dynamic_cast`** checks the
object's real type while the program runs. It gives a `const Circle*`, or `nullptr` when the
object is not a `Circle`.

## Watch out

- Test the result for `nullptr` before you use it.
- A `dynamic_cast` for every kind of shape means that `Shape` lacks a virtual function. Add
  one, and let each class answer for itself.

## Try it

1. Predict the output (the classes are those of `find_circles.cpp`):

   ```cpp
   std::vector<std::unique_ptr<Shape>> shapes;
   shapes.push_back(std::make_unique<Rectangle>(2.0, 5.0));
   shapes.push_back(std::make_unique<Circle>(1.0));
   const Circle* first = dynamic_cast<const Circle*>(shapes[0].get());
   const Circle* second = dynamic_cast<const Circle*>(shapes[1].get());
   std::cout << (first == nullptr) << ' ' << (second == nullptr) << ' ' << shapes[0]->area() << '\n';
   ```

2. `shapes.cpp` should print `Circle: 12.5664` and `Rectangle: 12`. Do it without
   `dynamic_cast`.

<details>
<summary>Answers</summary>

1. `1 0 10`. The first object is a `Rectangle`, so the cast gives `nullptr`. The second is a
   `Circle`.
2. Add `virtual std::string name() const = 0;` to `Shape` (and `#include <string>`), override
   it in both classes, and print `shape.name()` in `printArea`. The loop does not change.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)
