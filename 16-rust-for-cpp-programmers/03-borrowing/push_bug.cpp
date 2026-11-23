#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores = {70, 85, 90};
    const int& first = scores[0];     // a reference into the vector
    scores.push_back(60);             // the block is full: every element moves
    std::cout << first << '\n';       // first still refers to the old block
}
