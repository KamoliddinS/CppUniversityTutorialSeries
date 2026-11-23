#include <iostream>

int main() {
    int limit = 60;
    auto passes = [limit](int score) { return score >= limit; };   // copies limit now

    limit = 90;                          // too late: the lambda keeps its own 60
    if (passes(75)) {
        std::cout << "75 passes\n";
    }

    int total = 0;
    auto add = [&total](int amount) { total += amount; };          // uses total itself
    add(5000);
    add(2500);
    std::cout << "total: " << total << '\n';
}
