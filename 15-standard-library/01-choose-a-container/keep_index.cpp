#include <cstddef>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores = {70, 85, 90};
    std::size_t first = 0;         // an index stays correct after a move

    scores.push_back(60);

    std::cout << scores[first] << '\n';
}
