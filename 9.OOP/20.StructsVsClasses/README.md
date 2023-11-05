
# Structs vs Classes in C++

In C++, both structs (`struct`) and classes (`class`) are used to define custom data types that can contain member variables and functions. However, there are some differences that affect their usage.

## Key Differences

### Default Access Specifier
- **Struct**: By default, members of a struct are `public`.
- **Class**: By default, members of a class are `private`.

### Inheritance
- **Struct**: When deriving a struct from a class/struct, the default access specifier for base class/struct is `public`.
- **Class**: When deriving a class, the default access specifier for base class is `private`.

### Intended Use
- **Struct**: Structs are typically used for passive objects with public access, like data carriers.
- **Class**: Classes are used for active objects with private attributes, encapsulation, and abstraction.

## Similarities
Despite these differences, structs and classes are fundamentally the same in how they behave. Both can:
- Have member functions and variables.
- Support access specifiers (`public`, `protected`, `private`).
- Be used for inheritance.
- Have constructors and destructors.
- Be instantiated as objects.

## Example Code

```cpp
// Struct example
struct Point {
    int x, y; // Public by default

    Point(int px, int py) : x(px), y(py) {} // Constructor

    void print() const { // Function is public by default
        std::cout << "Point(" << x << ", " << y << ")\n";
    }
};

// Class example
class Circle {
private:
    Point center; // Private by default
    double radius; // Private by default

public:
    Circle(int x, int y, double r) : center(x, y), radius(r) {} // Constructor

    void print() const { // Public because we explicitly declared it so
        std::cout << "Circle at ";
        center.print(); // Accessible because print() is public in Point
        std::cout << " with radius " << radius << "\n";
    }
};
```

In the example above, `Point` is a `struct` with public data members and a function, while `Circle` is a `class` with private data members that can only be accessed through public member functions.

## Conclusion

The choice between using a struct or a class in C++ is often based on convention and the intent of the code rather than functional necessity, as both are nearly identical in terms of capabilities. Use `structs` when you want to bundle data without requiring strict encapsulation and `classes` when you want to enforce encapsulation and control over data and behavior.
