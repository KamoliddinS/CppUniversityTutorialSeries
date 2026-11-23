#include <iostream>

void addBonus(int score) {          // by value: score is a copy
    score = score + 5;
    std::cout << "in addBonus: " << score << '\n';
}

int main() {
    int malika = 80;
    addBonus(malika);
    std::cout << "in main:     " << malika << '\n';
}
