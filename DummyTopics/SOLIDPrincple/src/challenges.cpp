#include <iostream>
#include <vector>

// Class that violates SRP
class User {
public:
    void addUser(const std::string& name) {
        users.push_back(name);
        std::cout << "User added: " << name << std::endl;
    }

    void saveUsersToFile(const std::string& filename) {
        // Some code to save users to a file
        std::cout << "Users saved to file: " << filename << std::endl;
    }

private:
    std::vector<std::string> users;
};

int main() {
    User user;
    user.addUser("Alice");
    user.saveUsersToFile("users.txt");

    return 0;
}


#include <iostream>
#include <vector>

// Shape type enumeration
enum class ShapeType { CIRCLE, RECTANGLE };

// Shape class that violates OCP
// it would take lots of afford to add aditional functionalties 
class Shape {
public:
    Shape(ShapeType type) : type(type) {}

    void draw() {
        if (type == ShapeType::CIRCLE) {
            std::cout << "Drawing Circle" << std::endl;
        } else if (type == ShapeType::RECTANGLE) {
            std::cout << "Drawing Rectangle" << std::endl;
        }
    }

private:
    ShapeType type;
};

int main() {
    Shape circle(ShapeType::CIRCLE);
    Shape rectangle(ShapeType::RECTANGLE);

    circle.draw();
    rectangle.draw();

    return 0;
}


#include <iostream>

// Base class
class Vehicle {
public:
    virtual void startEngine() {
        std::cout << "Engine started." << std::endl;
    }
};

// Derived class
class ElectricCar : public Vehicle {
public:
    void startEngine() override {
        throw std::runtime_error("Electric car does not have an engine to start!");
    }
};

void startVehicleEngine(Vehicle& vehicle) {
    vehicle.startEngine();
}

int main() {
    Vehicle car;
    ElectricCar tesla;

    startVehicleEngine(car);
    startVehicleEngine(tesla); 

    return 0;
}

#include <iostream>

class IDevice {
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};

class Printer : public IDevice {
public:
    void print() override {
        std::cout << "Printing document." << std::endl;
    }

    void scan() override {
        // Unnecessary implementation
    }

    void fax() override {
        // we don't need to override unnecessary implementation 
    }
};

int main() {
    Printer printer;
    printer.print();
    printer.scan(); // Unnecessary for Printer
    printer.fax(); 

    return 0;
}
