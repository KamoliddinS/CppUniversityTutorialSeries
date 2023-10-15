// main.cpp

#include <iostream>   // For input-output stream operations

// Global variable (File/Global Scope)
int globalVar = 20;

// Namespace declaration
namespace MyNamespace {
    int namespaceVar = 30;
}

// Class declaration
class MyClass {
public:
    int classVar = 40;  // Class Scope
    void showClassVar() {
        std::cout << "Class variable (classVar): " << classVar << std::endl;
    }
};

int main() {
    // Introduction
    std::cout << "Demonstrating Scope Rules in C++\n" << std::endl;

    // Local Scope
    int localVar = 10;
    std::cout << "Local variable (localVar): " << localVar << std::endl;

    // Global Scope
    std::cout << "Global variable (globalVar): " << globalVar << std::endl;

    // Namespace Scope
    std::cout << "Namespace variable (namespaceVar): " << MyNamespace::namespaceVar << std::endl;

    // Class Scope
    MyClass obj;
    obj.showClassVar();

    // Local Scope overriding Global Scope
    int globalVar = 100; // This is a new local variable with the same name as the global variable
    std::cout << "\nLocal variable with same name as global (globalVar): " << globalVar << std::endl;

    return 0;
}
