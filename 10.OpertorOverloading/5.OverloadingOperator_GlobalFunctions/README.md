

# Overloading Operators as Global Functions

This part of the repository provides an introduction to overloading operators as global functions in C++. This method allows for operator overloading for classes where member function operator overloading is not possible or when you want to maintain symmetry, especially with binary operators.

## Overview

Operator overloading allows custom types to behave like primitive types by defining how operators work with them. Global operator overloading is defined outside the class and can work with private members if the class has provided the necessary access through friend functions.

## Learning Outcomes

- Understand when and why to overload operators as global functions.
- Get to know the syntax for declaring and defining global operator overloads.
- Learn to implement operator overloading for symmetry in binary operations.

## Syntax for Global Operator Overloading

The general syntax for overloading an operator globally is as follows:

```cpp
ReturnType operatorX(const Type1& lhs, const Type2& rhs);
```

- `ReturnType` is the type returned by the operator, which could be a class, primitive type, or a reference.
- `operatorX` is the operator keyword followed by the operator symbol (e.g., `operator+`, `operator==`).
- `Type1` and `Type2` are the types of the operands.

## Rules and Considerations

- The operators `=`, `()`, `[]`, and `->` must always be member functions.
- To access private or protected class members, the global function must be declared as a `friend` of the class.
- For binary operators, usually the left-hand side operand is the first argument and the right-hand side operand is the second.

## Example: Overloading the Plus Operator for Symmetry

Let's overload the addition operator for a `Point` class as a global function.

```cpp
class Point {
public:
    Point(int x, int y) : x_(x), y_(y) {}

    // Friend declaration for global operator function
    friend Point operator+(const Point& lhs, const Point& rhs);

    // ... additional members ...

private:
    int x_, y_;
};

// Global operator overload
Point operator+(const Point& lhs, const Point& rhs) {
    return Point(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_);
}
```

This example shows a global operator function that adds two `Point` objects. The `friend` declaration within the class allows the function to access private members.

