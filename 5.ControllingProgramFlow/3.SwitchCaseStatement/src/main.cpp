#include <iostream>

int main() {
    int dayNumber;

    // Prompt the user for a number from 1 to 7
    std::cout << "Enter a number from 1 to 7: ";
    std::cin >> dayNumber;

    // Determine the day of the week based on the number
    switch (dayNumber) {
        case 1:
            std::cout << "Sunday" << std::endl;
            break;
        case 2:
            std::cout << "Monday" << std::endl;
            break;
        case 3:
            std::cout << "Tuesday" << std::endl;
            break;
        case 4:
            std::cout << "Wednesday" << std::endl;
            break;
        case 5:
            std::cout << "Thursday" << std::endl;
            break;
        case 6:
            std::cout << "Friday" << std::endl;
            break;
        case 7:
            std::cout << "Saturday" << std::endl;
            break;
        default:
            std::cout << "Invalid input. Please enter a number from 1 to 7." << std::endl;
    }

    return 0;
}
