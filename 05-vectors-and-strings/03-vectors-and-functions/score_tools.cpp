#include <iostream>
#include <vector>

int total(const std::vector<int>& scores) {               // only reads
    int sum = 0;
    for (int score : scores) {
        sum += score;
    }
    return sum;
}

void addBonus(std::vector<int>& scores, int bonus) {      // changes the caller's vector
    for (int& score : scores) {
        score += bonus;
    }
}

std::vector<int> passed(const std::vector<int>& scores) { // makes a new vector
    std::vector<int> result;
    for (int score : scores) {
        if (score >= 60) {
            result.push_back(score);
        }
    }
    return result;
}

int main() {
    std::vector<int> scores = {72, 45, 90};
    addBonus(scores, 5);
    std::cout << "Total: " << total(scores) << '\n';

    std::vector<int> good = passed(scores);
    std::cout << good.size() << " of " << scores.size() << " passed\n";
}
