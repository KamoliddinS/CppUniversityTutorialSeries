#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Using an algorithm with iterators
    std::cout << "Vector contains 3: "
              << (std::find(vec.begin(), vec.end(), 3) != vec.end() ? "Yes" : "No") << std::endl;

    return 0;
}
