#include <iostream>
#include <string>

// Base class with a parameterized constructor
class Base {
    int value;
public:
    // Base class constructor that takes an integer
    Base(int val) : value(val) {
        std::cout << "Base constructor called with value: " << value << std::endl;
    }

    // Simple member function to display the value
    void displayValue() const {
        std::cout << "Base value: " << value << std::endl;
    }
};

// Derived class that inherits from Base
class Derived : public Base {
    std::string name;
public:
    // Derived class constructor that takes an integer and a string
    Derived(int val, std::string nm) : Base(val), name(std::move(nm)) {
        std::cout << "Derived constructor called with name: " << name << std::endl;
    }

    // Member function to display the derived class's details
    void display() const {
        // Display the base class value
        displayValue();
        // Display the derived class name
        std::cout << "Derived name: " << name << std::endl;
    }
};

int main() {
    // Create an object of Derived class with integer and string
    Derived derivedObj(42, "Example");
    
    // Display the details of the object
    derivedObj.display();

    // Output:
    // Base constructor called with value: 42
    // Derived constructor called with name: Example
    // Base value: 42
    // Derived name: Example

    return 0;
}
