#include <iostream>
#include <memory>

// INHERITANCE EXAMPLE

// Base class
class Animal {
public:
    Animal() { std::cout << "Animal created.\n"; }
    virtual ~Animal() { std::cout << "Animal destroyed.\n"; }

    // Function that all animals can do
    void breathe() {
        std::cout << "Animal breathes.\n";
    }
};

// Derived class
class Dog : public Animal {
public:
    Dog() { std::cout << "Dog created.\n"; }
    ~Dog() { std::cout << "Dog destroyed.\n"; }

    // Dog specific function
    void bark() {
        std::cout << "Dog barks: Woof!\n";
    }
};

// COMPOSITION EXAMPLE

// Another class
class Engine {
public:
    Engine() { std::cout << "Engine created.\n"; }
    ~Engine() { std::cout << "Engine destroyed.\n"; }

    // Engine specific function
    void start() {
        std::cout << "Engine starts. Vroom!\n";
    }
};

// Class that uses composition
class Car {
    // Car has an engine
    Engine engine;

public:
    Car() { std::cout << "Car created.\n"; }
    ~Car() { std::cout << "Car destroyed.\n"; }

    // Function that uses the engine object
    void startCar() {
        std::cout << "Car is starting.\n";
        engine.start(); // Delegates the start function to the engine object
    }
};

int main() {
    std::cout << "Inheritance Example:\n";
    Dog myDog; // Dog is an Animal
    myDog.breathe(); // Inherited function
    myDog.bark(); // Dog's function

    std::cout << "\nComposition Example:\n";
    Car myCar; // Car has an Engine
    myCar.startCar(); // Car's function that uses the Engine

    return 0;
}
