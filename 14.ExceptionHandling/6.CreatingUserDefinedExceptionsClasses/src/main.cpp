#include <iostream>
#include <stdexcept>

// Define a custom exception class that inherits from std::exception
class DivisionByZeroException : public std::exception {
private:
    const char* message;

public:
    DivisionByZeroException(const char* msg) : message(msg) {}

    // Override the what() method to return our custom error message
    const char* what() const noexcept override {
        return message;
    }
};

// A function that might throw our custom exception
double safeDivide(double numerator, double denominator) {
    if (denominator == 0) {
        // Throw an instance of our custom exception instead of a standard one
        throw DivisionByZeroException("Attempted to divide by zero.");
    }
    return numerator / denominator;
}

int main() {
    try {
        double result = safeDivide(10.0, 0.0); // This should trigger a division by zero
        std::cout << "The result is: " << result << std::endl;
    } catch (const DivisionByZeroException& e) {
        // Catch our custom exception and print its message
        std::cerr << "Caught a DivisionByZeroException: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // This block catches any other exceptions derived from std::exception
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}
