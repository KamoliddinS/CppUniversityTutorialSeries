#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores = {70, 85, 90};
    int& first = scores[0];        // refers to an element inside the vector

    scores.push_back(60);          // the block is full: the vector moves

    std::cout << first << '\n';    // first still refers to the old block
}
