
# Friends of Classes in C++

In C++, the `friend` keyword is used to give a non-member function or another class access to private and protected members of a class. This concept is important for scenarios where you need an external function or class to access an object's private internals without compromising encapsulation entirely.

## Friend Functions

A friend function is a function that is not a member of a class but has the right to access the class's private and protected members. Friend functions are useful for operator overloading when you need to access the private members of a class.

### Syntax

```cpp
class MyClass {
    friend void friendFunction(MyClass &obj);
    // ...
};
```

### Example

```cpp
class Box {
private:
    double width;

public:
    Box(double wid) : width(wid) {}

    // Friend function declaration
    friend void printWidth(Box& b);
};

// Friend function definition
void printWidth(Box& b) {
    std::cout << "Width of box: " << b.width << std::endl;
}
```

In the example above, `printWidth` is a friend function and can access the private member `width` of the `Box` class.

## Friend Classes

A friend class is a class whose members are allowed to access the private and protected members of another class.

### Syntax

```cpp
class MyClass {
    friend class FriendClass;
    // ...
};
```

### Example

```cpp
class Box {
private:
    double length;

public:
    Box(double len) : length(len) {}

    // Friend class declaration
    friend class BoxPrinter;
};

class BoxPrinter {
public:
    static void printLength(Box& b) {
        std::cout << "Length of box: " << b.length << std::endl;
    }
};
```

Here, `BoxPrinter` is a friend class of `Box` and can access its private member `length`.

## Why Use Friends?

- **Operator Overloading**: Overloading certain operators (like `<<`, `>>`, or arithmetic operators) for custom classes.
- **System-Level Access**: When your class is used by system-level code, which needs access to its internals without getters/setters.
- **Efficiency**: Sometimes using friend functions can be more efficient than getters/setters as it avoids the overhead of function calls.

## Conclusion

Friends break the strict encapsulation of a class by allowing external functions and classes to access its private parts. This feature should be used sparingly, as it can make the interface of a class harder to understand and maintain.
