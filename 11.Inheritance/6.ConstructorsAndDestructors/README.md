# Constructors and Destructors in Inheritance

Inheritance is one of the core concepts of object-oriented programming (OOP), allowing new classes to derive properties and behaviors from existing ones. A crucial aspect of inheritance involves understanding how constructors and destructors work across parent and child classes. Here's a detailed overview of these concepts in the context of inheritance in C++.

## Constructors in Inheritance

When a new object of a derived class is created, C++ constructs the object starting with the base class and moving down the inheritance chain to the most-derived class.

### Order of Execution

- **Base Class Constructor**: Called first. If the base class constructor is not specified, the default constructor is called.
- **Derived Class Constructor**: Called after the base class constructor completes.

### Specifying Base Class Constructors

You can specify which base class constructor should be called using an initialization list.

```cpp
class Base {
public:
    Base(int value) {
        // Initialize base class
    }
};

class Derived : public Base {
public:
    Derived(int value) : Base(value) {
        // Initialize derived class, after calling specified Base constructor
    }
};
```

### Default Constructors

If a base class does not have a default constructor, and a derived class constructor does not explicitly call a base class constructor, the code will not compile.

## Destructors in Inheritance

Destructors are called in the reverse order of the constructors, starting with the most-derived class and ending with the base class.

### Order of Execution

- **Derived Class Destructor**: Called first when an object goes out of scope or is deleted.
- **Base Class Destructor**: Called after the derived class destructor completes.

### Importance of Virtual Destructors

If a base class destructor is not declared `virtual`, deleting an object of a derived class via a pointer to the base class can lead to undefined behavior because the base class destructor will be called instead of the derived class destructor.

```cpp
class Base {
public:
    virtual ~Base() {
        // Cleanup base class
    }
};

class Derived : public Base {
public:
    ~Derived() {
        // Cleanup derived class
    }
};
```

## Code Example

Here's a simple example to demonstrate the order of constructor and destructor calls:

```cpp
class Base {
public:
    Base() { std::cout << "Base Constructor\n"; }
    virtual ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived Constructor\n"; }
    ~Derived() { std::cout << "Derived Destructor\n"; }
};

int main() {
    Derived obj;
    // Output will be:
    // Base Constructor
    // Derived Constructor
    // Derived Destructor
    // Base Destructor
}
```

## Conclusion

Understanding how constructors and destructors work in an inheritance hierarchy is critical for the proper creation and cleanup of objects in C++. Always ensure base class destructors are virtual when you have a class hierarchy intended for polymorphism. This ensures that derived class destructors will be called appropriately, avoiding resource leaks and undefined behavior.