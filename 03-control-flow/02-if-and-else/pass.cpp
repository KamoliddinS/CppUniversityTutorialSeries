#include <iostream>

int main() {
    std::cout << "Score (0 to 100): ";
    int score = 0;
    std::cin >> score;

    if (score >= 60) {
        std::cout << "Passed.\n";
        if (score >= 90) {              // tested only when the score is 60 or more
            std::cout << "With distinction.\n";
        }
    } else {
        std::cout << "Not passed.\n";
    }
}
