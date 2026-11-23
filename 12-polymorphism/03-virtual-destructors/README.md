# Virtual destructors

> **Goal:** give a base class a virtual destructor, so that deleting through a base pointer destroys the whole object.

## Half of the object is destroyed

Each destructor prints a line. Which lines appear when the circle is deleted?

**`half_destroyed_bug.cpp`**
<!-- file: half_destroyed_bug.cpp -->
```cpp
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
```

g++ builds the program, but warns:

<!-- errors: half_destroyed_bug -->
```text
half_destroyed_bug.cpp: In function ‘int main()’:
half_destroyed_bug.cpp:22:5: warning: deleting object of polymorphic class type ‘Shape’ which has non-virtual destructor might cause undefined behavior [-Wdelete-non-virtual-dtor]
   22 |     delete shape;   // through a Shape*: which destructor runs?
      |     ^~~~~~~~~~~~
```

A run usually prints:

```text
Area: 3.14159
Shape destroyed
```

`Circle destroyed` is missing. `~Shape` is not virtual, so it was chosen from the pointer
type `Shape*`, and `~Circle` never ran. A `Circle` that owned memory or an open file would
never release it. In C++ this `delete` is undefined behaviour: anything may happen. The
output above is only what you usually see.

## The fix: a virtual destructor

**`fully_destroyed.cpp`**
<!-- file: fully_destroyed.cpp -->
```cpp
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
```

<!-- output: fully_destroyed -->
```text
Area: 3.14159
Circle destroyed
Shape destroyed
```

- A **virtual destructor** is chosen like any virtual function: by the object's real type.
  `~Circle` runs first, then `~Shape`, the usual order
  ([Constructors in a hierarchy](../../11-inheritance/03-constructors-in-a-hierarchy/README.md)).
- `main` now uses a `std::unique_ptr<Shape>`. It deletes through a `Shape*` too, so it
  needs the virtual destructor just as much.
- When the base destructor has nothing to do, write `virtual ~Shape() = default;`.

**The rule:** a class with at least one virtual function gets a virtual destructor.

## Watch out

- Write `virtual` in the base class only. The destructors of derived classes are then
  virtual too.
- A local variable such as `Circle circle(1.0);` is always destroyed completely. The danger
  is a delete through a base pointer.

## Try it

1. Predict the output when `main` in `fully_destroyed.cpp` has this body:

   ```cpp
   std::unique_ptr<Shape> shape = std::make_unique<Circle>(1.0);
   std::cout << "one\n";
   shape = std::make_unique<Circle>(2.0);
   std::cout << "two\n";
   ```

2. Remove `virtual` from `~Shape` in `fully_destroyed.cpp`. Does g++ warn? What does a run print?

<details>
<summary>Answers</summary>

1. Six lines: `one`, `Circle destroyed`, `Shape destroyed`, `two`, `Circle destroyed`,
   `Shape destroyed`. A `unique_ptr` that gets a new object deletes the old one. The second
   circle is deleted at the end of `main`.
2. No warning, but the bug is the same: a run usually prints `Area: 3.14159` and
   `Shape destroyed` only. A build with `-fsanitize=address` reports it as
   `new-delete-type-mismatch`.
</details>

**Next:** [Abstract classes](../04-abstract-classes/README.md)
