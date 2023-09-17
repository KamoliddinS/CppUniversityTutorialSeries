#include <iostream>

int main() {
    // Demonstrating Logical AND (&&)
    bool isAdult = true;
    bool hasLicense = true;
    if (isAdult && hasLicense) {
        std::cout << "Allowed to drive." << std::endl;
    }

    // Demonstrating Logical OR (||)
    bool isWeekend = true;
    bool isHoliday = false;
    if (isWeekend || isHoliday) {
        std::cout << "Enjoy your day off!" << std::endl;
    }

    // Demonstrating Logical NOT (!)
    bool isRaining = false;
    if (!isRaining) {
        std::cout << "It's a sunny day!" << std::endl;
    }

    // Combining Logical Operators
    bool hasHomework = true;
    bool isSick = false;
    if ((isWeekend || isSick) && !hasHomework) {
        std::cout << "You can relax today." << std::endl;
    } else {
        std::cout << "You have some responsibilities." << std::endl;
    }

    return 0;
}
