#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> scores = {72, 90, 64, 85, 90};

    std::cout << "Largest: " << std::ranges::max(scores) << '\n';
    std::cout << "Smallest: " << std::ranges::min(scores) << '\n';
    std::cout << "Sum: " << std::accumulate(scores.begin(), scores.end(), 0) << '\n';
    std::cout << "Number of 90s: " << std::ranges::count(scores, 90) << '\n';

    if (std::ranges::find(scores, 85) != scores.end()) {    // read: "85 was found"
        std::cout << "Somebody got 85.\n";
    }

    std::ranges::sort(scores);                              // smallest first
    for (int score : scores) {
        std::cout << score << ' ';
    }
    std::cout << '\n';
}
