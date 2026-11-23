#include <iostream>

void addBonus(int& score) {         // by reference: score is the caller's variable
    score = score + 5;
    std::cout << "in addBonus: " << score << '\n';
}

int main() {
    int malika = 80;
    addBonus(malika);
    std::cout << "in main:     " << malika << '\n';
}
