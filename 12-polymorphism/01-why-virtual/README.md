# Why virtual

> **Goal:** explain why a call through a base pointer runs the base class's function, and say what should happen instead.

## One loop for every shape

Chapter 11 ended with a problem: a call through a `Person&` ran `Person::describe`, even for
a student ([Redefine a function](../../11-inheritance/04-redefine-a-function/README.md)).
Here is the same problem with shapes.

A drawing program has circles and rectangles. One loop should ask every shape for its area.
A `Circle` is a `Shape`, so a `Shape*` can point to a circle, and one vector can list all shapes.

**`wrong_areas.cpp`**
<!-- file: wrong_areas.cpp -->
```cpp
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
```

<!-- output: wrong_areas -->
```text
Direct call: 3.14159
In the loop: 0
In the loop: 0
```

- The direct call is right: the compiler knows that `circle` is a `Circle`.
- In the loop the compiler knows only the type of the pointer, `const Shape*`. It chooses
  `Shape::area()` for both objects while it builds the program. This is static binding,
  as in chapter 11.

## What we want

| `shape` points to | `shape->area()` runs | It should run |
|-------------------|----------------------|---------------|
| a `Circle` | `Shape::area()` | `Circle::area()` |
| a `Rectangle` | `Shape::area()` | `Rectangle::area()` |

The object's **real type**, the type it was created with, should decide. One call that runs
different code for different kinds of object is called **polymorphism**. The next lesson
makes it work.

## Watch out

- No data is lost. `circle` is still a complete `Circle` with its radius. Only the choice of
  function is wrong.
- A reference behaves like the pointer: after `const Shape& ref = circle;` the call
  `ref.area()` also runs `Shape::area()`.

## Try it

1. Predict the output (the classes are those of `wrong_areas.cpp`):

   ```cpp
   Rectangle rectangle(2.0, 5.0);
   const Shape& ref = rectangle;
   const Rectangle* ptr = &rectangle;
   std::cout << ref.area() << ' ' << ptr->area() << '\n';
   ```

2. Add a class `Square` with one side and its own `area()` to `wrong_areas.cpp`. Put a square
   into the vector. What does the loop print for it?

<details>
<summary>Answers</summary>

1. `0 10`. Both names stand for the same object. `ref` is a reference to `Shape`, so
   `Shape::area()` runs. `ptr` is a pointer to `Rectangle`, so `Rectangle::area()` runs.
2. `In the loop: 0`. The vector holds pointers to `Shape`, so the loop still calls
   `Shape::area()`.
</details>

**Next:** [Virtual functions](../02-virtual-functions/README.md)
