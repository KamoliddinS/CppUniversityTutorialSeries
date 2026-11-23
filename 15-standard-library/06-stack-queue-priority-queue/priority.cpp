#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int> largestFirst;
    std::priority_queue<int, std::vector<int>, std::greater<>> smallestFirst;

    const std::vector<int> values = {30, 50, 10, 40};
    for (int value : values) {
        largestFirst.push(value);
        smallestFirst.push(value);
    }

    while (!largestFirst.empty()) {
        std::cout << largestFirst.top() << ' ';
        largestFirst.pop();
    }
    std::cout << '\n';
    while (!smallestFirst.empty()) {
        std::cout << smallestFirst.top() << ' ';
        smallestFirst.pop();
    }
    std::cout << '\n';
}
