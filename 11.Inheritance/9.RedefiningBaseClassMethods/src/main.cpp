#include <iostream>

// Base class with a virtual function
class Base {
public:
    virtual void display() const {
        std::cout << "Display Base" << std::endl;
    }

    virtual ~Base() {} // Virtual destructor for proper cleanup
};

// Derived class that overrides the display function
class Derived : public Base {
public:
    // Override the 'display' method of the base class
    void display() const override { // Notice the use of 'override' keyword
        std::cout << "Display Derived" << std::endl;
    }
};

void callDisplay(const Base& obj) {
    // This function will call the appropriate display function based on the object type
    obj.display();
}

int main() {
    Base b;
    Derived d;

    // Calling display method using objects
    b.display(); // Outputs: Display Base
    d.display(); // Outputs: Display Derived

    // Calling display through a reference to Base
    callDisplay(b); // Outputs: Display Base
    callDisplay(d); // Outputs: Display Derived

    // Using pointers to demonstrate polymorphism
    Base* ptr = &b;
    ptr->display(); // Outputs: Display Base

    ptr = &d;
    ptr->display(); // Outputs: Display Derived

    return 0;
}
