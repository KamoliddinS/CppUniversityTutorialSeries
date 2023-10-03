#include <iostream>

// Function that increments an integer by a given value using pass by reference
void incrementByReference(int &x, int increment) {
    x += increment;
}

int main() {
    int number = 5;
    int incrementValue = 3;

    std::cout << "Original number: " << number << std::endl;

    // Call the incrementByReference function with 'number' by reference
    incrementByReference(number, incrementValue);

    std::cout << "Updated number: " << number << std::endl;

    return 0;
}
