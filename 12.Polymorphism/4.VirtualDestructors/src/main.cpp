// Filename: VirtualDestructorsDemo.cpp
// Compile with: g++ VirtualDestructorsDemo.cpp -o VirtualDestructorsDemo
// GOLDEN RULE IF YOU HAVE ONE VIRTUAL FUNCTION ALWAYS SPECIFY THAT CLASSES DISTRUCTOR AS VIRTUAL

#include <iostream>

// Base class
class Base {
public:
    // A virtual destructor is essential in a polymorphic base class.
    virtual ~Base() {
        std::cout << "Base destructor called." << std::endl;
    }
};

// Derived class
class Derived : public Base {
private:
    int* array;

public:
    Derived() {
        array = new int[5]; // Allocate some resources
        std::cout << "Derived constructor called. Resources allocated." << std::endl;
    }

    // The destructor for the derived class cleans up the allocated resources.
    ~Derived() override {
        delete[] array; // Free the allocated resources
        std::cout << "Derived destructor called. Resources deallocated." << std::endl;
    }
};

void createPolymorphicObject() {
    // Create a derived object, but use a base class pointer
    Base* basePtr = new Derived();

    // The derived object is destroyed here, when we delete the base pointer.
    // Due to the virtual destructor, the Derived destructor is also called.
    delete basePtr;
}

int main() {
    std::cout << "Creating a polymorphic object:" << std::endl;
    createPolymorphicObject();
    std::cout << "Polymorphic object has been destroyed." << std::endl;

    return 0;
}
