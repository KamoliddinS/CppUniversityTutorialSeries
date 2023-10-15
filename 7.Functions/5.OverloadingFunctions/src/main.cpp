// main.cpp

#include <iostream> // For input-output stream operations

// Function Prototypes for Overloading Demonstrations
void display(int);                   // Overload 1
void display(double);                // Overload 2
void display(int, double);           // Overload 3
void display(double, int);           // Overload 4

int main() {
    // Introduction
    std::cout << "Exploring Function Overloading in C++\n" << std::endl;

    // Demonstration: Overloading Based on Type of Parameters
    int intVal = 5;
    double doubleVal = 7.5;

    display(intVal);      // Calls Overload 1
    display(doubleVal);   // Calls Overload 2

    // Demonstration: Overloading with Different Combinations
    display(intVal, doubleVal);    // Calls Overload 3
    display(doubleVal, intVal);    // Calls Overload 4

    return 0;
}

// Function Definitions
void display(int i) {
    std::cout << "Displaying integer: " << i << std::endl;
}

void display(double d) {
    std::cout << "Displaying double: " << d << std::endl;
}

void display(int i, double d) {
    std::cout << "Displaying integer and double: " << i << ", " << d << std::endl;
}

void display(double d, int i) {
    std::cout << "Displaying double and integer: " << d << ", " << i << std::endl;
}

