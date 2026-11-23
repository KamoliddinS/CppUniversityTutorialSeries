#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores = {72, 85, 90, 64};

    int sum = 0;
    int largest = scores[0];
    for (int score : scores) {          // score is a copy of the element
        sum += score;
        if (score > largest) {
            largest = score;
        }
    }
    std::cout << "Sum: " << sum << ", largest: " << largest << '\n';

    for (int& score : scores) {         // score is the element itself
        score += 5;
    }
    for (int score : scores) {
        std::cout << score << ' ';
    }
    std::cout << '\n';
}
