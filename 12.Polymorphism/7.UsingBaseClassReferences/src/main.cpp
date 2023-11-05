// Filename: PolymorphismWithReferences.cpp
// Compile with: g++ PolymorphismWithReferences.cpp -o PolymorphismWithReferences

#include <iostream>
#include <vector>

// Abstract base class with a virtual function
class Animal {
public:
    virtual void speak() const = 0; // Pure virtual function makes this class abstract

    virtual ~Animal() {} // Virtual destructor for proper cleanup
};

// Derived class Dog
class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof!" << std::endl;
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow!" << std::endl;
    }
};

// A function that invokes the speak method on an Animal reference
void makeAnimalSpeak(const Animal& animal) {
    animal.speak(); // Dynamic dispatch to the actual object's speak method
}

int main() {
    Dog dog;
    Cat cat;

    // Notice we're passing derived class instances to a function expecting a base class reference
    makeAnimalSpeak(dog); // Outputs: Woof!
    makeAnimalSpeak(cat); // Outputs: Meow!

    return 0;
}
