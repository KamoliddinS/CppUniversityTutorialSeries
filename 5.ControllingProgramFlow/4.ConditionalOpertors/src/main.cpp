#include <iostream>

int main() {
    int number;
    int absoluteValue;

    // Prompt the user to enter an integer
    std::cout << "Enter an integer: ";
    std::cin >> number;

    // Calculate the absolute value using the ternary operator
    absoluteValue = (number >= 0) ? number : -number;

    // Display the absolute value
    std::cout << "The absolute value of " << number << " is " << absoluteValue << std::endl;

    return 0;
}
