#include <iostream>

int main() {
    int age;

    // Prompt the user for their age
    std::cout << "Enter your age: ";
    std::cin >> age;

    // Check if the user is eligible to vote
    if (age >= 18) {
        std::cout << "You are eligible to vote. Make your voice heard!" << std::endl;
    } else {
        std::cout << "Sorry, you are not eligible to vote yet. Wait until you are 18 or older." << std::endl;
    }

    return 0;
}
