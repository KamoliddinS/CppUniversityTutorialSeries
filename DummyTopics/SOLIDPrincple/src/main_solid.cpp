// #include <iostream>
// #include <string>

// //////////SINGLE REPSONSIBILITY PRINCPLE ///////////////
// // Employee class - Manages employee data
// class Employee {
// public:
//     Employee(const std::string& name, const std::string& department)
//         : name_(name), department_(department) {}
//     std::string getName() const { return name_; }
//     std::string getDepartment() const { return department_; }

// private:
//     std::string name_;
//     std::string department_;
// };

// // Database class - Responsible for database operations
// class EmployeeDatabase {
// public:
//     void saveEmployee(const Employee& emp) {
//         // Code to save employee details to database
//         std::cout << "Saving employee " << emp.getName() << " to database." << std::endl;
//     }
// };

// class ReportGenerator {
// public:
//     void generatePerformanceReport(const Employee& emp) {
//         std::cout << "Generating performance report for " << emp.getName() << "." << std::endl;
//     }
// };

// int main() {
//     Employee emp("John Doe", "Engineering");
//     EmployeeDatabase db;
//     ReportGenerator reportGen;

//     db.saveEmployee(emp);
//     reportGen.generatePerformanceReport(emp);

//     return 0;
// }



// ////////////////OPEN/CLOSED PRINCPLE///////////////////////
// #include <iostream>
// #include <string>
// #include <vector>

// class Shape {
// public:
//     virtual void print() const = 0;
//     virtual ~Shape() = default; // Virtual destructor for proper cleanup
// };
// class Circle : public Shape {
// public:
//     void print() const override {
//         std::cout << "Printing a circle." << std::endl;
//     }
// };
// // Rectangle class
// class Rectangle : public Shape {
// public:
//     void print() const override {
//         std::cout << "Printing a rectangle." << std::endl;
//     }
// };
// class Triangle: public Shape
// {
// private:
//     /* data */
// public:
//     void print() const override {
//         std::cout << "Printing a triangle." << std::endl;
//     }
// };

// // ShapePrinter class now adheres to OCP
// class ShapePrinter {
// public:
//     void printShape(const Shape& shape) {
//         shape.print(); // Polymorphic call to print
//         //we don't have to modify this because if new class has been created
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



//////////////LISKOV SUBSTITUTION PRINCPLE//////////////////////
// #include <iostream>
// #include <vector>

// class Bird {
// public:
//     virtual void move() {
//         std::cout << "Bird is moving." << std::endl;
//     }
// };

// class FlyingBird : public Bird {
// public:
//     void move() override {
//         std::cout << "Flying bird is flying." << std::endl;
//     }
// };
// class Eagle : public FlyingBird {
//     // Inherits move behavior from FlyingBird
// };

// class NonFlyingBird : public Bird {
// public:
//     void move() override {
//         std::cout << "Non-flying bird is walking." << std::endl;
//     }
// };
// class Penguin : public NonFlyingBird {
//     // Inherits move behavior from NonFlyingBird
// };

// void makeBirdMove(Bird& bird) {
//     bird.move();
// }

// int main() {
//     Eagle eagle;
//     Penguin penguin;
//     makeBirdMove(eagle); // Works correctly for eagle
//     makeBirdMove(penguin); // Also works correctly for penguin
//     return 0;
// }





////////////////INTERFACE SEGREGATION PRICPLE //////////////
#include <iostream>
class IWorkable {
public:
    virtual void work() = 0;
};
class IEatable {
public:
    virtual void eat() = 0;
};
class IBreakable {
public:
    virtual void takeBreak() = 0;
};

class OfficeWorker : public IWorkable, public IEatable, public IBreakable {
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
class Robot : public IWorkable {
public:
    void work() override {
        std::cout << "Robot is working." << std::endl;
    }
};

int main() {
    OfficeWorker john;
    Robot r2d2;
    john.work();
    john.eat();
    john.takeBreak();
    r2d2.work();
    return 0;
}






////////////DEPENDENCY INVERSION PRINCPLE////////////////////////////
#include <iostream>
#include <string>

// LOOK this is  abstract class representing a generic storage device
/// if class needs to be storage device it has to implement readData method 
/// High level module Computer now dependence on  just Storage device wich is abstract 
class StorageDevice {
public:
    virtual std::string readData() = 0;
    virtual ~StorageDevice() {}
};
/// now if we go one level down abstract class has no implementation 
/// and it is not dependent on details all the details has been implemented by child class
class HardDrive : public StorageDevice {
public:
    std::string readData() override {
        return "Data from Hard Drive";
    }
};
class SolidStateDrive : public StorageDevice {
public:
    std::string readData() override {
        return "DATA FROM SSD";
    }
};

class Nvme: public StorageDevice {
   public:
    std::string readData() override {
        return "DATA FROM NVME ";
    } 
}
class Computer {
private:
    StorageDevice& storageDevice;
public:
    Computer(StorageDevice& device) : storageDevice(device) {}
    void start() {
        std::string data = storageDevice.readData();
        std::cout << "Computer using " << data << std::endl;
    }
};
int main() {
    HardDrive hardDrive;
    SolidStateDrive ssd;
    Nvme mynvme;

    Computer computerWithHDD(hardDrive);
    computerWithHardDrive.start();

    Computer computerWithSSD(ssd);
    computerWithMemory.start();

    Computer computerWithNVME(Nvme);
    computerWithNVME.start();

    return 0;
}
