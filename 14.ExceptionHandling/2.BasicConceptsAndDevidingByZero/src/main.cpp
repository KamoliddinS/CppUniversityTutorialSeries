#include <iostream>
#include <stdexcept> // Include for std::runtime_error

// Function: safe_divide
// This function takes two doubles and returns their division if the denominator is not zero.
// If the denominator is zero, it throws a runtime_error exception.
double safe_divide(double numerator, double denominator) {
    // Check if the denominator is zero
    if (denominator == 0) {
        // Throw a runtime_error exception with an error message
        throw std::runtime_error("Math error: Attempted to divide by Zero");
    }
    // If no exception is thrown, perform the division and return the result
    return numerator / denominator;
}

// Main Function: The entry point of the program
int main() {
    // Variables to store the numerator and denominator
    double numerator = 10.0;
    double denominator = 0.0;

    // Try block contains code that might throw an exception
    try {
        // Attempt to divide two numbers using the safe_divide function
        double result = safe_divide(numerator, denominator);
        // If division is successful, print the result
        std::cout << "The result is: " << result << std::endl;
    }
    // Catch block handles exceptions of type std::runtime_error
    catch (const std::runtime_error& e) {
        // If an exception is caught, print the error message
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }

    // End of program
    return 0;
}
