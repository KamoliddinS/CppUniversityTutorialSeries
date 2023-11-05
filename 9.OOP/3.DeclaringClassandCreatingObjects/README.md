
# Declaring a Class and Creating Objects in C++

Welcome to the segment of our C++ course where we learn how to define classes and create objects. This is where your journey in object-oriented programming starts to take shape—quite literally!

## 🛠️ Declaring a Class

A class in C++ is declared with the `class` keyword, followed by the class name and a set of curly braces `{}` containing the members and functions of the class. Think of a class as a template for making objects that share common properties and behaviors.

Here's how you can declare a simple class called `Rectangle`:

```cpp
class Rectangle {
  public:
    double length;
    double width;

    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }
};
```

In this `Rectangle` class, `length` and `width` are the properties, while `calculateArea()` and `calculatePerimeter()` are the behaviors or functions.

## 🏗️ Creating Objects

Once we have a class, we can create objects from it. Creating an object is also known as instantiation, and it allows us to use the actual data and functions of the class.

Here's how you create an object of the `Rectangle` class:

```cpp
Rectangle myRectangle;

myRectangle.length = 5.0;
myRectangle.width = 3.0;

double area = myRectangle.calculateArea();
double perimeter = myRectangle.calculatePerimeter();
```

With the `myRectangle` object, we've given specific values to the `length` and `width` properties and then used them to calculate the area and perimeter of the rectangle.

## ✨ In Action

In the `/src` directory, you'll find example C++ files where classes are defined, and objects are instantiated. Explore these examples to see how you can create and interact with objects of your own classes.

To compile and run an example, if you're using `g++` you can do the following in your terminal:

```bash
g++ -o example example.cpp
./example
```

Replace `example.cpp` with the actual file name of the example you wish to compile and run.

## 🎯 Exercises

To put your knowledge into practice, check out the `/exercises` directory. Here, you will find various tasks to help you master the art of class declaration and object creation in C++.

Dive in and start shaping your understanding of these fundamental concepts. Happy coding!
