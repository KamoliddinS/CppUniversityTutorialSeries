#include <iostream>

int main() {
    double score;

    // Prompt the user for their score
    std::cout << "Enter your score: ";
    std::cin >> score;

    // Determine the letter grade based on the score
    if (score >= 90.0) {
        std::cout << "Your grade is A." << std::endl;
    } else if (score >= 80.0) {
        std::cout << "Your grade is B." << std::endl;
    } else if (score >= 70.0) {
        std::cout << "Your grade is C." << std::endl;
    } else if (score >= 60.0) {
        std::cout << "Your grade is D." << std::endl;
    } else {
        std::cout << "Your grade is F." << std::endl;
    }
    return 0;
}
