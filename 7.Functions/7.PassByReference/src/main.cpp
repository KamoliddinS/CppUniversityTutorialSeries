// main.cpp

#include <iostream>   // For input-output stream operations
#include <string>     // For string operations

// Function Prototypes
void modifyValue(int& x);
void display(const std::string& str);
void swap(int& a, int& b);

int main() {
    // Introduction
    std::cout << "Demonstrating Pass By Reference in C++\n" << std::endl;

    // Basic Pass By Reference
    int value = 5;
    std::cout << "Original Value: " << value << std::endl;

    modifyValue(value);   // Modifying the value by reference
    std::cout << "Modified Value: " << value << std::endl;
    
    // Using const with Pass By Reference
    std::string message = "Hello, World!";
    display(message);   // Displaying string without modifying it

    // Swapping two values using Pass By Reference
    int a = 10, b = 20;
    std::cout << "\nBefore Swapping - a: " << a << ", b: " << b << std::endl;

    swap(a, b);   // Swapping values by reference
    std::cout << "After Swapping - a: " << a << ", b: " << b << std::endl;

    return 0;
}

// Function Definitions
void modifyValue(int& x) {
    x *= 2;  // Double the value
}

void display(const std::string& str) {
    std::cout << str << std::endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
