// Exercise 3: Wrong percentage
// Read how many answers were correct and how many questions the test had.
// Print the result in percent, for example:
//     7 of 8 is 87.5%
// The program builds and runs, but the percentage is wrong. Find out why and fix it.
#include <iostream>

int main() {
    int correct = 0;
    int questions = 0;
    std::cin >> correct >> questions;

    double percent = correct / questions * 100;
    std::cout << correct << " of " << questions << " is " << percent << "%\n";
}
