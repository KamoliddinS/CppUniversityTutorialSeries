#include <iostream>
#include <iomanip>  // For output formatting

int main() {
    // Basic Output using cout
    std::cout << "Welcome to the I/O demo program!" << std::endl;

    // Reading a single value using cin
    int age;
    std::cout << "Please enter your age: ";
    std::cin >> age;
    std::cin.ignore();  // Clearing the input buffer

    // Reading a line of text using getline
    std::string name;
    std::cout << "Please enter your full name: ";
    std::getline(std::cin, name);

    // Displaying entered values
    std::cout << "Hello, " << name << "! You are " << age << " years old." << std::endl;

    // Reading multiple values using cin
    double length, width;
    std::cout << "Enter the length and width of a rectangle (separated by space): ";
    std::cin >> length >> width;

    // Calculating and displaying area with formatted output
    double area = length * width;
    std::cout << std::fixed << std::setprecision(2);  // Displaying up to 2 decimal places
    std::cout << "The area of the rectangle is: " << area << " square units." << std::endl;

    // Error handling demonstration
    std::cout << "Enter an integer value: ";
    int value;
    std::cin >> value;

    if (std::cin.fail()) {
        std::cout << "That was not a valid integer!" << std::endl;
        std::cin.clear();  // Clearing the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clearing the input buffer
    } else {
        std::cout << "You entered: " << value << std::endl;
    }

    return 0;
}
