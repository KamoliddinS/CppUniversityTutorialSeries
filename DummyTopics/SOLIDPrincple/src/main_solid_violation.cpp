// #include <iostream>
// #include <vector>
// #include <string>

// // This class violates the Single Responsibility Principle
// class Employee {
// public:
//     Employee(const std::string& name, const std::string& department)
//         : name_(name), department_(department) {}

//     void saveEmployeeToDatabase() {
//         std::cout << "Saving employee " << name_ << " to database." << std::endl;
//     }

//     void generatePerformanceReport() {
//         std::cout << "Generating performance report for " << name_ << "." << std::endl;
//     }

//     //  We mightn have other employee-related methods...

// private:
//     std::string name_;
//     std::string department_;
// };

// int main() {
//     Employee emp("John Doe", "Engineering");
//     emp.saveEmployeeToDatabase();
//     emp.generatePerformanceReport();

//     return 0;
// }











// //////////////// VIOLTION OF OCP PRINCPLE////////////////
// #include <iostream>
// #include <string>
// #include <vector>

// enum class ShapeType {
//     CIRCLE,
//     RECTANGLE,
//     TRIANGLE
// };
// class Shape {
// public:
//     virtual ShapeType getType() const = 0;
// };
// class Circle : public Shape {
// public:
//     ShapeType getType() const override {
//         return ShapeType::CIRCLE;
//     }
// };
// class Rectangle : public Shape {
// public:
//     ShapeType getType() const override {
//         return ShapeType::RECTANGLE;
//     }
// };

// class Triangle: public Shape {
//     public:
//     ShapeType getType() const override{
//         return ShapeType::TRIANGLE;
//     }
// }
// ///////////////// THIS  CLASS  VIOLATES  OCP //////////////////////
// class ShapePrinter {
// public:
//     void printShape(const Shape& shape) {
//         switch (shape.getType()) {
//             case ShapeType::CIRCLE:
//                 std::cout << "Printing a circle." << std::endl;
//                 break;
//             case ShapeType::RECTANGLE:
//                 std::cout << "Printing a rectangle." << std::endl;
//                 break;
//             case ShapeType::TRIANGLE:
//                 std::cout<< "Printing a triangel"<<std::endl;
//                 break;
//             // Adding a new shape requires modifying this switch statement
//         }
//     }
// };

// int main() {
//     Circle circle;
//     Rectangle rectangle;
//     ShapePrinter printer;
//     printer.printShape(circle);
//     printer.printShape(rectangle);

//     return 0;
// }





//////////////// VIOLATING LSP //////////////////////////////

// #include <iostream>
// #include <vector>

// class Bird {
// public:
//     virtual void fly() {
//         std::cout << "Bird is flying." << std::endl;
//     }
// };

// class Eagle : public Bird {
// public:
//     void fly() override {
//         std::cout << "Eagle is soaring high." << std::endl;
//     }
// };

// class Penguin : public Bird {
// public:
//     void fly() override {
//         // throw std::runtime_error("Penguins cannot fly!");
//         // penguins cannot fly 
//     }
// };

// void makeBirdFly(Bird& bird) {
//     bird.fly();
// }

// int main() {
//     Eagle eagle;
//     Penguin penguin;

//     makeBirdFly(eagle);
//     makeBirdFly(penguin); // This will throw an exception, violating LSP

//     return 0;
// }


/////////////////// VOLATING ISP ////////////////////////////
#include <iostream>
class IWorker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual void takeBreak() = 0;
};
// A working class that needs all methods of IWorker
class OfficeWorker : public IWorker {
public:
    void work() override {
        std::cout << "Office Worker is working." << std::endl;
    }
    void eat() override {
        std::cout << "Office Worker is eating." << std::endl;
    }
    void takeBreak() override {
        std::cout << "Office Worker is taking a break." << std::endl;
    }
};
class Robot : public IWorker {
public:
    void work() override {
        std::cout << "Robot is working." << std::endl;
    }
    void eat() override {
        // Robots do not eat, but have to provide an implementation
    }
    void takeBreak() override {
        // Robots do not take breaks, but have to provide an implementation
    }
};
int main() {
    OfficeWorker john;
    Robot r2d2;
    john.work();
    john.eat();
    john.takeBreak();

    r2d2.work();
    r2d2.eat();     // Irrelevant to Robot
    r2d2.takeBreak(); // Irrelevant to Robot
    return 0;
}





/////////////// VOIOLATED DEPENDENCYU INVERSION PRINCPLE //////////////
#include <iostream>
#include <string>

// Low-level module
class HardDrive {
public:
    std::string readData() {
        return "Data from Hard Drive";
    }
};

// Low-level module
class SolidStateMemory {
public:
    std::string load() {
        return "Data from SSD ";
    }
};

// High-level module
class Computer {
private:
    HardDrive hardDrive;
    SolidStateMemory solidStateDrive;
public:
    void start() {
        std::string hdData = hardDrive.readData();
        std::string memData = solidStateDrive.load();
        std::cout << "Computer using " << hdData << " and " << memData << std::endl;
    }
};

int main() {
    Computer computer;
    computer.start();
    return 0;
}
