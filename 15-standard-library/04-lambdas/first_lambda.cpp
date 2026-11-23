#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    auto twice = [](int x) { return x * 2; };      // a lambda, stored in a variable
    std::cout << twice(21) << '\n';

    std::vector<int> scores = {72, 95, 58, 90};
    auto passed = std::count_if(scores.begin(), scores.end(),
                                [](int score) { return score >= 60; });
    std::cout << passed << " passed\n";
}
