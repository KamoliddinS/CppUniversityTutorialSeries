#include <iostream>
#include <iomanip> // Required for parameterized manipulators

int main() {
    int number = 255;

    // Demonstrating endl manipulator
    std::cout << "Using std::endl to break lines and flush the stream." << std::endl;

    // Demonstrating setw and setfill manipulators
    // setw sets the width, setfill sets the padding character
    std::cout << std::setw(10) << std::setfill('*') << number << std::endl;

    // Demonstrating setprecision manipulator
    // This sets the decimal precision for floating point output
    double pi = 3.14159;
    std::cout << "Pi with precision 3: " << std::setprecision(3) << pi << std::endl;

    // Demonstrating fixed manipulator
    // This forces floating-point numbers to be in fixed decimal point notation
    std::cout << "Pi in fixed format: " << std::fixed << pi << std::endl;

    // Demonstrating scientific manipulator
    // This switches numbers to scientific notation
    std::cout << "Pi in scientific format: " << std::scientific << pi << std::endl;

    // Demonstrating hex, oct, and dec manipulators
    // These change the base for numeric output
    std::cout << "Number in decimal: " << std::dec << number << std::endl;
    std::cout << "Number in hexadecimal: " << std::hex << number << std::endl;
    std::cout << "Number in octal: " << std::oct << number << std::endl;

    // Resetting format to decimal for further operations
    std::cout << std::dec;

    // Demonstrating left and right manipulators
    // These adjust the alignment of the output
    std::cout << std::right << std::setw(10) << "Right aligned" << std::endl;
    std::cout << std::left << std::setw(10) << "Left aligned" << std::endl;

    // Demonstrating boolalpha manipulator
    // This allows for a boolean value to be printed as 'true' or 'false'
    bool flag = true;
    std::cout << "Boolean flag with boolalpha: " << std::boolalpha << flag << std::endl;
    std::cout << "Boolean flag without boolalpha: " << std::noboolalpha << flag << std::endl;

    return 0;
}
