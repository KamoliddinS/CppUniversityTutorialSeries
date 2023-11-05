
# Constructor Parameters and Default Values in C++

This section of our Computer Programming with C++ course covers the use of parameters in constructors and how default values can be specified for them.

## Introduction

In C++, a constructor is a special type of member function that initializes objects of its class. It is possible to pass parameters to constructors to initialize an object with specific values at the time of its creation. Furthermore, we can provide default values for constructor parameters to allow flexibility in object creation.

## Syntax for Constructor Parameters

Here's how you can define a constructor that takes parameters:

```cpp
class MyClass {
public:
    MyClass(Type1 param1, Type2 param2) {
        // Initialization code using param1 and param2
    }
};
```

## Default Values for Constructor Parameters

You can also provide default values for constructor parameters, allowing you to instantiate objects with or without providing explicit arguments:

```cpp
class MyClass {
public:
    MyClass(Type1 param1 = defaultValue1, Type2 param2 = defaultValue2) {
        // Initialization code using param1 and param2
    }
};
```

When you instantiate an object of `MyClass`, you can choose to provide values for `param1` and `param2` or to rely on the default values.

## Example

Let's consider a simple class `Book` that demonstrates the use of constructor parameters with default values:

```cpp
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    // Constructor with default values
    Book(const std::string &title = "Untitled", const std::string &author = "Unknown", int year = 0)
        : title(title), author(author), year(year) {}

    // Function to display book information
    void display() const {
        std::cout << "Book: " << title << ", Author: " << author << ", Year: " << year << std::endl;
    }
};
```

In the `Book` class above, the constructor takes three parameters, all of which have default values. This means you can create a `Book` object in several ways:

```cpp
int main() {
    Book book1;                      // Uses all default values
    Book book2("1984");              // Default author and year
    Book book3("Animal Farm", "George Orwell", 1945);  // No defaults used

    book1.display();
    book2.display();
    book3.display();

    return 0;
}
```

## Conclusion

Using parameters and default values in constructors provides flexibility and helps in creating objects with specific initial states or default configuration. It is a way to reuse the same constructor logic for creating objects with different initial properties.

Remember that when using default values, any parameters following a parameter with a default value must also have default values.

