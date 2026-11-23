#include <iostream>

int main() {
    std::cout << "Score (0 to 100): ";
    int score = 0;
    std::cin >> score;

    if (score >= 90) {
        std::cout << "Grade 5: excellent\n";
    } else if (score >= 70) {
        std::cout << "Grade 4: good\n";
    } else if (score >= 60) {
        std::cout << "Grade 3: satisfactory\n";
    } else {
        std::cout << "Grade 2: not passed\n";
    }
}
