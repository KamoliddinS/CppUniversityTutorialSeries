#include <iostream>
#include <string>

// Base class
class Animal {
public:
    Animal() { std::cout << "An animal has been created\n"; }
    virtual ~Animal() { std::cout << "An animal has been destroyed\n"; }

    // Virtual function to be overridden by the derived class
    virtual void speak() const {
        std::cout << "This animal makes a sound\n";
    }
};

// Derived class
class Dog : public Animal {
public:
    Dog() { std::cout << "A dog has been created\n"; }
    ~Dog() { std::cout << "A dog has been destroyed\n"; }

    // Overriding the speak function from the Animal base class
    void speak() const override {
        std::cout << "Woof woof!\n";
    }
};

// Main function to demonstrate inheritance
int main() {
    // Creating an object of the base class
    Animal animal;
    animal.speak();  // Calls Animal's speak method

    std::cout << "\n";

    // Creating an object of the derived class
    Dog dog;
    dog.speak();     // Calls Dog's speak method, which overrides Animal's speak method

    return 0;
}
