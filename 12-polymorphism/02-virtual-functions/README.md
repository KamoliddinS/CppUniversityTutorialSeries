# Virtual functions

> **Goal:** make a call through a base pointer or reference run the function of the object's real type.

## `virtual` and `override`

This is the program of the [last lesson](../01-why-virtual/README.md) with two new words:
`virtual` in `Shape`, and `override` in `Circle` and `Rectangle`.

**`areas.cpp`**
<!-- file: areas.cpp -->
```cpp
#include <iostream>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;                    // lesson 3 explains this line
    virtual double area() const { return 0.0; }
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

int main() {
    Circle circle(1.0);
    Rectangle rectangle(2.0, 3.0);

    std::vector<const Shape*> shapes = {&circle, &rectangle};
    for (const Shape* shape : shapes) {
        std::cout << "In the loop: " << shape->area() << '\n';
    }
}
```

<!-- output: areas -->
```text
In the loop: 3.14159
In the loop: 6
```

| Word | Where | Meaning |
|------|-------|---------|
| `virtual` | base class, before the function | derived classes may replace this function |
| `override` | derived class, after the parameters and `const` | this function replaces a virtual one |
| `final` | in place of `override`, or after a class name | no class may override this function again, or derive from this class |

A **virtual function** is called with **dynamic binding**: the function is chosen while the
program runs, from the real type of the object. A derived function with the same name,
parameters and `const` **overrides** (replaces) it.

## `override` checks your work

`override` does not change which function runs. It makes the compiler check that the function
really replaces a virtual one. In [`missing_const_nocompile.cpp`](missing_const_nocompile.cpp),
`Circle` has this line:

<!-- snippet: missing_const_nocompile.cpp -->
```cpp
    double area() override { return 3.14159 * radius_ * radius_; }   // const is missing
```

<!-- errors: missing_const_nocompile -->
```text
missing_const_nocompile.cpp:12:12: error: ‘double Circle::area()’ marked ‘override’, but does not override
   12 |     double area() override { return 3.14159 * radius_ * radius_; }   // const is missing
      |            ^~~~
missing_const_nocompile.cpp:6:20: warning: ‘virtual double Shape::area() const’ was hidden [-Woverloaded-virtual=]
    6 |     virtual double area() const { return 0.0; }
      |                    ^~~~
missing_const_nocompile.cpp:12:12: note:   by ‘double Circle::area()’
   12 |     double area() override { return 3.14159 * radius_ * radius_; }   // const is missing
      |            ^~~~
```

`area()` and `area() const` are two different functions. Without the word `override` the
program builds, g++ only warns ("was hidden"), and the call through a `Shape&` gives `0` again.

## Only through a pointer or a reference

[`by_value.cpp`](by_value.cpp) has the same `Shape` and `Circle`, and two functions:

<!-- snippet: by_value.cpp -->
```cpp
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
```

<!-- output: by_value -->
```text
By reference: 3.14159
By value: 0
```

Passing by value copies only the `Shape` part of `circle`
([slicing](../../11-inheritance/04-redefine-a-function/README.md)). The copy really is a
`Shape`, so `Shape::area()` runs.

## How it works

```text
   circle                       vtable of Circle
 ┌─────────────────┐          ┌────────────────────────┐
 │ hidden pointer ─┼────────► │ area → Circle::area    │
 │ radius_ = 1.0   │          └────────────────────────┘
 └─────────────────┘
   rectangle                    vtable of Rectangle
 ┌─────────────────┐          ┌────────────────────────┐
 │ hidden pointer ─┼────────► │ area → Rectangle::area │
 │ width_  = 2.0   │          └────────────────────────┘
 │ height_ = 3.0   │
 └─────────────────┘
```

Compilers usually do it like this: every object of a class with virtual functions holds a
hidden pointer to a table of its class's virtual functions, the **vtable**. The call
`shape->area()` follows that pointer and runs the function it finds in the table.

## Watch out

- Write `override` on every function that replaces a virtual one.
- Forget `virtual` in `Shape`, and `override` reports that too. Without `override`, you
  silently get static binding again.

## Try it

1. Predict the output (the classes are those of `areas.cpp`):

   ```cpp
   Rectangle rectangle(3.0, 4.0);
   Shape copy = rectangle;
   const Shape& ref = rectangle;
   std::cout << copy.area() << ' ' << ref.area() << '\n';
   ```

2. Print `sizeof(Circle)` in `areas.cpp`. Then remove both words `virtual` and both words
   `override`, and print it again.

<details>
<summary>Answers</summary>

1. `0 12`. `copy` is a new `Shape`, made from the `Shape` part of `rectangle`. `ref` is
   another name for the `Rectangle` itself.
2. With g++ on a 64-bit system: `16`, then `8`. The hidden pointer takes 8 bytes.
</details>

**Next:** [Virtual destructors](../03-virtual-destructors/README.md)
