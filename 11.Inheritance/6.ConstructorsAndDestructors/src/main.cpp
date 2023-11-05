#include <iostream>

// Base class
class Base {
public:
    // Base class constructor
    Base() {
        std::cout << "Base class constructor called." << std::endl;
    }
    
    // Base class destructor
    virtual ~Base() {
        std::cout << "Base class destructor called." << std::endl;
    }
};

// Derived class
class Derived : public Base {
public:
    // Derived class constructor
    Derived() {
        std::cout << "Derived class constructor called." << std::endl;
    }
    
    // Derived class destructor
    ~Derived() override {
        std::cout << "Derived class destructor called." << std::endl;
    }
};

int main() {
    std::cout << "Creating Derived object." << std::endl;
    Derived derivedObj;
    
    std::cout << "Derived object going out of scope." << std::endl;
    // When main returns, derivedObj is destroyed. Destructors are called.
    return 0;
}
