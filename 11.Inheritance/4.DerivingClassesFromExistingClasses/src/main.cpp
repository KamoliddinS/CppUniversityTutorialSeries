#include <iostream>

// Base class
class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle: Constructor called" << std::endl;
    }
    
    virtual ~Vehicle() {
        std::cout << "Vehicle: Destructor called" << std::endl;
    }

    virtual void displayType() {
        std::cout << "I am a Vehicle" << std::endl;
    }
};

// Derived class Car
class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car: Constructor called" << std::endl;
    }
    
    ~Car() {
        std::cout << "Car: Destructor called" << std::endl;
    }

    void displayType() override {
        std::cout << "I am a Car" << std::endl;
    }
};

// Derived class Bike
class Bike : public Vehicle {
public:
    Bike() {
        std::cout << "Bike: Constructor called" << std::endl;
    }
    
    ~Bike() {
        std::cout << "Bike: Destructor called" << std::endl;
    }

    void displayType() override {
        std::cout << "I am a Bike" << std::endl;
    }
};

// Main function
int main() {
    Vehicle* v1 = new Car(); // Upcasting, Vehicle pointer to a Car object
    Vehicle* v2 = new Bike(); // Upcasting, Vehicle pointer to a Bike object


    std::cout << "v1 is a ";
    v1->displayType(); // Displays: I am a Car

    std::cout << "v2 is a ";
    v2->displayType(); // Displays: I am a Bike

    delete v1; // Cleanup
    delete v2; // Cleanup

    return 0;
}
