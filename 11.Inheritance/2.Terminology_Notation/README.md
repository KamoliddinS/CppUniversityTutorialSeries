# Inheritance in C++: Terminology and Notation

Welcome to the section of our C++ course repository dedicated to explaining the terminology and notation used in inheritance. Inheritance is a core concept of object-oriented programming (OOP) and C++, which allows new classes to be built upon existing ones. This README aims to simplify the jargon and symbols related to inheritance.

## Basic Terminology

- **Base Class:** Also known as the parent or superclass. This is the class from which properties and methods are inherited.
- **Derived Class:** Also known as the child or subclass. This class inherits from the base class.
- **Inheriting:** The process by which one class takes on the properties and behaviors of another class.
- **Member:** A variable or a function that belongs to a class.
- **Overriding:** Providing a new implementation for a base class's method in the derived class.

## Inheritance Notation

In C++, we use a special syntax to denote that one class is derived from another. Here's the basic notation:

```cpp
class DerivedClass : accessSpecifier BaseClass {
  // members of the derived class
};
```

- The colon `:` symbol indicates that inheritance is taking place.
- The `accessSpecifier` defines how the members of the base class are accessed in the derived class. It can be `public`, `protected`, or `private`.

## Access Specifiers and Inheritance

The access specifier used during inheritance impacts the accessibility of the inherited members in the derived class.

- **Public Inheritance (`public`):** Members that are public in the base class remain public in the derived class. Protected members remain protected, and private members are inaccessible.
- **Protected Inheritance (`protected`):** Public and protected members of the base class become protected in the derived class. Private members remain inaccessible.
- **Private Inheritance (`private`):** Public and protected members of the base class become private in the derived class. Private members remain inaccessible.

## Common Terms in Inheritance

- **Constructor:** A special member function that is called when a new instance of a class is created. Constructors of base classes are not inherited but can be called by the derived class's constructor.
- **Destructor:** A member function called when an instance of a class is destroyed. Like constructors, destructors are not inherited.
- **Virtual Functions:** Functions that are designed to be overridden in a derived class. When used with pointers or references, they allow for dynamic (run-time) polymorphism.
- **Abstract Class:** A class that cannot be instantiated and often contains pure virtual functions. It is designed to be a base class for other derived classes.
- **Concrete Class:** A class that can be instantiated, meaning it has implementations for all of its functions and no pure virtual functions.

## Example of Inheritance Notation

```cpp
class Animal {
public:
    virtual void speak() {
        std::cout << "Some sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Woof woof!" << std::endl;
    }
};
```

In this example:
- `Animal` is the base class.
- `Dog` is the derived class that inherits from `Animal` using public inheritance.
- The `speak` function in `Animal` is a virtual function, indicating it's meant to be overridden.
- The `speak` function in `Dog` uses the `override` keyword to clearly indicate that it is overriding a virtual function from the base class.

## Conclusion

Understanding inheritance terminology and notation is crucial for working with C++ and OOP. It lays the foundation for building complex and efficient software systems. Through inheritance, we can extend the functionality of existing classes in a structured and logical manner.

