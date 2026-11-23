#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> scores = {72, 85, 90};     // a list of three ints

    std::cout << "Size: " << scores.size() << '\n';
    std::cout << "First: " << scores[0] << ", last: " << scores.back() << '\n';

    scores.push_back(64);                       // add at the end
    scores[0] = 75;                             // change the first element
    std::cout << "Size: " << scores.size() << ", first: " << scores[0]
              << ", last: " << scores.back() << '\n';

    scores.pop_back();                          // remove the last element
    std::cout << "Size: " << scores.size() << ", last: " << scores.back() << '\n';

    std::vector<std::string> absent;            // an empty list of strings
    if (absent.empty()) {
        std::cout << "Nobody is absent.\n";
    }
}
