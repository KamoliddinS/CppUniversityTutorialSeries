#include <iostream>
#include <stdexcept>

// Custom exception classes
class MyNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Not Found Exception: Item not found.";
    }
};

class MyDatabaseException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Database Exception: Database error occurred.";
    }
};

// A function that could throw multiple types of exceptions
void fetchData(int condition) {
    if (condition == 1) {
        throw MyNotFoundException();
    } else if (condition == 2) {
        throw MyDatabaseException();
    } else if (condition == 3) {
        throw std::overflow_error("Standard Overflow Error: Value too large.");
    }
    // Imagine more conditions that could lead to different exceptions...
}

// Main function to demonstrate exception handling
int main() {
    for (int i = 1; i <= 4; ++i) {
        try {
            fetchData(i); // Call a function that may throw exceptions
        } catch (const MyNotFoundException& e) {
            // Catch and handle not found exceptions
            std::cerr << "Error: " << e.what() << std::endl;
        } catch (const MyDatabaseException& e) {
            // Catch and handle database exceptions
            std::cerr << "Error: " << e.what() << std::endl;
        } catch (const std::overflow_error& e) {
            // Catch and handle overflow exceptions
            std::cerr << "Error: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            // Catch all other standard exceptions
            std::cerr << "Error: " << e.what() << std::endl;
        } catch (...) {
            // Catch-all handler for any other exceptions not covered above
            std::cerr << "Error: An unknown exception has occurred!" << std::endl;
        }
    }

    return 0;
}
