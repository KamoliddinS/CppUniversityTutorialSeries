
#include <iostream> // For input-output stream operations

// Function Prototypes
double computeAverage(int, int); // A prototype for a function that calculates the average of two integers
void displayMessage(); // A prototype for a function that displays a message

int main() {
    // Introduction
    std::cout << "Demonstrating Function Prototypes in C++\n" << std::endl;

    // Calling the displayMessage function
    displayMessage();

    // Using the computeAverage function
    int num1 = 10, num2 = 20;
    double average = computeAverage(num1, num2);
    std::cout << "The average of " << num1 << " and " << num2 << " is: " << average << std::endl;

    return 0;
}

// Function Definitions
double computeAverage(int a, int b) {
    return (static_cast<double>(a) + b) / 2;
}

void displayMessage() {
    std::cout << "This is an example demonstrating function prototypes!" << std::endl;
}

