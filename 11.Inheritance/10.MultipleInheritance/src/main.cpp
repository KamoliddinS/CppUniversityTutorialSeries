#include <iostream>
#include <string>

// Base class for Printer functionality
class Printer {
public:
    void print(const std::string& document) {
        std::cout << "Printing document: " << document << std::endl;
    }
};

// Base class for Scanner functionality
class Scanner {
public:
    void scan(const std::string& document) {
        std::cout << "Scanning document: " << document << std::endl;
    }
};

// Derived class inheriting from both Printer and Scanner
class Photocopier : public Printer, public Scanner {
public:
    // Photocopier's members and methods
    void photocopy(const std::string& document) {
        print(document); // Uses Printer's print method
        scan(document);  // Uses Scanner's scan method
    }
};

// Demonstration of the Photocopier class
int main() {
    Photocopier xeroxMachine;
    xeroxMachine.photocopy("Annual Report"); // Performs both print and scan

    // Alternatively, using individual functionalities
    xeroxMachine.print("Project Proposal"); // Only prints
    xeroxMachine.scan("Contract Agreement"); // Only scans

    return 0;
}





//DIMOND PROBLEM



// #include <iostream>

// // Base class Device
// class Device {
// public:
//     void powerOn() {
//         std::cout << "Device is powered on." << std::endl;
//     }
// };

// // Intermediate class Printer using virtual inheritance
// class Printer : virtual public Device {
// public:
//     void print() {
//         std::cout << "Printing..." << std::endl;
//     }
// };

// // Intermediate class Scanner using virtual inheritance
// class Scanner : virtual public Device {
// public:
//     void scan() {
//         std::cout << "Scanning..." << std::endl;
//     }
// };

// // Derived class from both Printer and Scanner
// class Photocopier : public Printer, public Scanner {
// public:
//     void photocopy() {
//         print(); // Print the document
//         scan();  // Scan the document
//     }
// };

// // Main function to demonstrate Photocopier class with virtual inheritance
// int main() {
//     Photocopier xeroxMachine;
//     xeroxMachine.powerOn();    // No ambiguity, Device::powerOn() is called
//     xeroxMachine.photocopy();  // Uses both print and scan

//     return 0;
// }
