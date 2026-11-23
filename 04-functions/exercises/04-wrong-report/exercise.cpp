// Exercise 4: Wrong report
// Every score gets 5 bonus points, but no score goes above 100. The report
// ends with the number of students and the best score.
// The program builds and runs, but its numbers are wrong. Find the two bugs.
#include <iostream>

void addBonus(int score, int bonus) {
    score += bonus;
    if (score > 100) {
        score = 100;
    }
}

int main() {
    int best = 0;
    int count = 0;
    int score = 0;

    while (std::cin >> score) {         // a read is a condition: false when the input ends
        addBonus(score, 5);
        std::cout << "with bonus: " << score << '\n';
        if (score > best) {
            int best = score;
            std::cout << "new best: " << best << '\n';
        }
        ++count;
    }

    std::cout << "students: " << count << '\n';
    std::cout << "best: " << best << '\n';
}
