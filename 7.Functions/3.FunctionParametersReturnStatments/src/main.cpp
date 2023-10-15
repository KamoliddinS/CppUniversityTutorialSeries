// main.cpp

#include <iostream> // For input-output stream operations

// Function Prototypes
int add(int, int);                           // Takes two value parameters and returns an integer.
void swap(int&, int&);                       // Takes two reference parameters and does not return.
void displayMessage(const std::string&);     // Takes a constant reference parameter and does not return.

int main() {
    // Introduction
    std::cout << "Exploring Function Parameters and Return Statements in C++\n" << std::endl;

    // Demonstration: Function with Value Parameters
    int num1 = 5, num2 = 10;
    int sum = add(num1, num2);
    std::cout << "Sum of " << num1 << " and " << num2 << " is: " << sum << std::endl;

    // Demonstration: Function with Reference Parameters
    std::cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;
    swap(num1, num2);
    std::cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    // Demonstration: Function without Return Value
    displayMessage("Hello from the displayMessage function!");

    return 0;
}

// Function Definitions
int add(int a, int b) {
    return a + b;  // Return the sum
}

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;  // Swaps values of x and y
}

void displayMessage(const std::string &message) {
    std::cout << message << std::endl;
}

