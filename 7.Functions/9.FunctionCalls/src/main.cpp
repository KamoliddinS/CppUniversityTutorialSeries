// main.cpp

#include <iostream>   // For input-output stream operations

// Function Declaration
void callByValue(int num);
void callByReference(int& num);
void callByPointer(int* num);
int factorial(int n);

int main() {
    // Introduction
    std::cout << "Demonstrating Function Calls in C++\n" << std::endl;

    // Call by Value
    int val = 10;
    std::cout << "Original value (Before Call by Value): " << val << std::endl;
    callByValue(val);
    std::cout << "Value after Call by Value: " << val << std::endl;  // No change in value

    // Call by Reference
    int ref = 10;
    std::cout << "\nOriginal value (Before Call by Reference): " << ref << std::endl;
    callByReference(ref);
    std::cout << "Value after Call by Reference: " << ref << std::endl;  // Value changed

    // Call by Pointer
    int ptrVal = 10;
    int* ptr = &ptrVal;
    std::cout << "\nOriginal value (Before Call by Pointer): " << ptrVal << std::endl;
    callByPointer(ptr);
    std::cout << "Value after Call by Pointer: " << ptrVal << std::endl;  // Value changed

    // Recursive Function Call
    int num = 5;
    std::cout << "\nFactorial of " << num << " is: " << factorial(num) << std::endl;

    return 0;
}

// Function Definitions

void callByValue(int num) {
    num += 5;  // Modifying the local copy of the variable
}

void callByReference(int& num) {
    num += 5;  // Modifying the original variable
}

void callByPointer(int* num) {
    *num += 5;  // Modifying the original variable using pointer
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n-1);  // Recursive function call
}
