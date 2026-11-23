# Abstract classes

> **Goal:** write a base class that says what every derived class must provide, and use it as an interface.

## A shape with no area

Until now `Shape::area()` returned `0.0`. That answer is made up: a shape "in general" has no
area. And a derived class that forgets to override `area()` silently reports `0`.

`= 0` says it honestly: `Shape` has no answer, and every real shape must give one.

**`abstract_shape.cpp`**
<!-- file: abstract_shape.cpp -->
```cpp
#include <iostream>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;   // pure virtual: every real shape must provide it
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {}
    double area() const override { return 3.14159 * radius_ * radius_; }

private:
    double radius_ = 0.0;
};

void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << '\n';
}

int main() {
    Circle circle(1.0);
    printArea(circle);
}
```

<!-- output: abstract_shape -->
```text
Area: 3.14159
```

- A function marked `= 0` is a **pure virtual function**: derived classes must override it.
- A class with at least one pure virtual function is an **abstract class**. You cannot create
  an object of it:

**`create_shape_nocompile.cpp`**
<!-- file: create_shape_nocompile.cpp -->
```cpp
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

int main() {
    Shape shape;   // an object of an abstract class
}
```

<!-- errors: create_shape_nocompile -->
```text
create_shape_nocompile.cpp: In function ‘int main()’:
create_shape_nocompile.cpp:8:11: error: cannot declare variable ‘shape’ to be of abstract type ‘Shape’
    8 |     Shape shape;   // an object of an abstract class
      |           ^~~~~
create_shape_nocompile.cpp:1:7: note:   because the following virtual functions are pure within ‘Shape’:
    1 | class Shape {
      |       ^~~~~
create_shape_nocompile.cpp:4:20: note:     ‘virtual double Shape::area() const’
    4 |     virtual double area() const = 0;
      |                    ^~~~
```

- A `Shape&` or a `Shape*` is still fine: see `printArea`.
- `Circle` overrides every pure virtual function, so you can create a `Circle`.

## Interfaces

An **interface** is a class with only pure virtual functions and a virtual destructor: a list
of what an object can do. C++ has no keyword for it; `Shape` above is one. A class may
implement several interfaces. They hold no data, so this is the safe kind of
[multiple inheritance](../../11-inheritance/05-multiple-inheritance/README.md).

**`interfaces.cpp`**
<!-- file: interfaces.cpp -->
```cpp
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
```

<!-- output: interfaces -->
```text
Circle with radius 1
Area: 3.14159
```

`show` asks only for "can print itself", and `measure` only for "has an area". A function
that asks for a small interface works with more types.

## Watch out

- `= 0` does not mean "no body". It means "derived classes must override this". A pure
  virtual function may still have a body, written outside the class:
  `double Shape::area() const { return 0.0; }`. An override can call it as `Shape::area()`.
- A derived class that leaves one pure virtual function without an override is abstract too.

## Try it

1. Does `Square square(2.0);` compile with this class? Why?

   ```cpp
   class Square : public Shape {
   public:
       explicit Square(double side) : side_(side) {}
       double area() { return side_ * side_; }

   private:
       double side_;
   };
   ```

2. Add a class `Rectangle` to `interfaces.cpp` that implements only `Shape`. Which call
   compiles: `show(rectangle)` or `measure(rectangle)`?

<details>
<summary>Answers</summary>

1. No. `area()` without `const` does not override `area() const`, so `Square` is still
   abstract: `cannot declare variable 'square' to be of abstract type 'Square'`.
   With `override` on that line, the compiler points at the real mistake.
2. Only `measure(rectangle)`. A `Rectangle` is a `Shape`, but it is not a `Printable`.
</details>

**Next:** [Polymorphic collections](../05-polymorphic-collections/README.md)
