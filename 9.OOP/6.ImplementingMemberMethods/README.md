
# Implementing Member Methods in C++

In C++, a class consists not only of data but also of functions that operate on that data. These functions are known as member methods (or member functions). This README will guide you through the process of implementing member methods to encapsulate the behavior of your classes.

## 🧩 What are Member Methods?

Member methods are akin to the actions that an object can perform. Consider a class `Car`. Besides properties like `color` and `model`, a `Car` can also `start()`, `accelerate()`, and `stop()`. These actions are represented as member methods within the class.

## 🛠️ Implementing Member Methods

There are generally two ways to implement member methods in C++:

1. **Inline**: Defined inside the class definition.
2. **Outside the class**: Declared inside but defined outside the class definition.

### Inline Member Methods

Inline methods are defined within the class body. These are usually short and are included directly in the compiled code where they are called, which can make them faster.

```cpp
class Calculator {
public:
    int add(int a, int b) {
        return a + b; // Inline method
    }
};
```

### Member Methods Outside the Class

For more complex methods or to improve the readability of your class declaration, you might want to define your methods outside the class.

```cpp
class Calculator {
public:
    int add(int a, int b); // Method declaration
};

int Calculator::add(int a, int b) { // Method definition
    return a + b;
}
```

The `::` is the scope resolution operator, and it tells the compiler which class the method belongs to.

## 🎯 Why Use Member Methods?

Member methods serve several purposes:

- **Encapsulation**: They help keep the data and the methods that manipulate that data in a single package.
- **Abstraction**: They provide a simple interface for the class users; they don't need to know how a method works, just what it does.
- **Organisation**: They keep the logic that operates on the data close to the data itself.

## 📚 Example

Here's a simple example that defines a `Rectangle` class with member methods to calculate the area and perimeter.

```cpp
class Rectangle {
private:
    int width, height;

public:
    // Constructor
    Rectangle(int w, int h) : width(w), height(h) {}

    // Inline methods
    int area() {
        return width * height;
    }

    int perimeter() {
        return 2 * (width + height);
    }
};

// ...

Rectangle rect(10, 20);
std::cout << "Area: " << rect.area() << std::endl;
std::cout << "Perimeter: " << rect.perimeter() << std::endl;
```

## 📝 Exercises

To reinforce your learning, try the following:

1. Implement a class `Circle` with a method to calculate the area.
2. Add a method to the `Rectangle` class that sets the width and height, then updates the area and perimeter.
3. Create a class `Time` that has methods to add hours, minutes, and seconds to the time.

By practicing the implementation of member methods, you'll become adept at defining the behaviors of your classes, resulting in well-structured and maintainable code. Dive in and experiment with your own classes and methods to see these concepts in action.
