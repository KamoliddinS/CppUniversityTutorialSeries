#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores = {72, 95, 58, 90, 41};
    auto failed = [](int score) { return score < 60; };

    auto first = std::find_if(scores.begin(), scores.end(), failed);
    if (first != scores.end()) {
        std::cout << "first failed score: " << *first << '\n';
    }
    std::cout << "failed: " << std::count_if(scores.begin(), scores.end(), failed) << '\n';

    if (std::any_of(scores.begin(), scores.end(), failed)) {
        std::cout << "somebody failed\n";
    }
    if (!std::all_of(scores.begin(), scores.end(), failed)) {
        std::cout << "but not everybody\n";
    }

    auto best = std::max_element(scores.begin(), scores.end());   // a position
    if (best != scores.end()) {
        std::cout << "best: " << *best << '\n';
    }
}
