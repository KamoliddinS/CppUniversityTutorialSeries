// Compile with: g++ VirtualFunctionsDemo.cpp -o VirtualFunctionsDemo

#include <iostream>
#include <vector>

// Base class with a virtual function
class Animal {
public:
    // Virtual function 'speak'
    virtual void speak() const {
        std::cout << "Some animal sound!" << std::endl;
    }

    // Virtual destructor is important for a class with virtual functions
    virtual ~Animal() {
        std::cout << "Animal destroyed." << std::endl;
    }
};

// Derived class 'Dog'
class Dog : public Animal {
public:
    // Overridden virtual function 'speak'
    void speak() const override {
        std::cout << "Woof!" << std::endl;
    }

    ~Dog() {
        std::cout << "Dog destroyed." << std::endl;
    }
};

// Derived class 'Cat'
class Cat : public Animal {
public:
    // Overridden virtual function 'speak'
    void speak() const override {
        std::cout << "Meow!" << std::endl;
    }

    ~Cat() {
        std::cout << "Cat destroyed." << std::endl;
    }
};

int main() {
    // Pointer to base class type 'Animal'
    Animal* myAnimal;

    // Dog instance, accessed through a pointer to Animal
    Dog myDog;
    myAnimal = &myDog;
    myAnimal->speak(); // Polymorphism in action - calls Dog's speak method

    // Cat instance, accessed through a pointer to Animal
    Cat myCat;
    myAnimal = &myCat;
    myAnimal->speak(); // Polymorphism in action - calls Cat's speak method

    // No need to delete anything since we're not using dynamic allocation
    return 0;
}
