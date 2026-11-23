#include <iostream>
#include <vector>

void addBonus(std::vector<int> scores, int bonus) {     // by value: a copy
    for (int& score : scores) {
        score += bonus;
    }
}

int main() {
    std::vector<int> scores = {72, 45, 90};
    addBonus(scores, 5);
    for (int score : scores) {
        std::cout << score << ' ';
    }
    std::cout << '\n';
}
