#include <iostream>
#include <stdexcept>

// Custom exception class that inherits from std::exception
class NegativeInputException : public std::exception {
public:
    // Overriding the what() method to return a custom error message
    const char* what() const noexcept override {
        return "Negative input exception: Input must be non-negative.";
    }
};

// Function that processes input and throws an exception if input is negative
void processInput(int input) {
    if (input < 0) {
        // Throwing a custom exception when a negative input is encountered
        throw NegativeInputException();
    } else if (input == 0) {
        // Throwing a standard exception for specific case (like dividing by zero)
        throw std::runtime_error("Runtime error: Input must not be zero.");
    }
    // If input is valid, print it
        
    std::cout << "Processing input: " << input << std::endl;
}

// Main function demonstrating exception handling
int main() {
    try {
        // Trying to process an invalid input
        processInput(-10);
    } catch (const NegativeInputException& e) {
        // Catching and handling the custom exception
        std::cerr << "Caught an error: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        // Catching and handling the standard exception
        std::cerr << "Caught a runtime error: " << e.what() << std::endl;
    } catch (...) {
        // Catch-all handler for any other exceptions
        std::cerr << "An unknown error has occurred!" << std::endl;
    }

    return 0;
}
