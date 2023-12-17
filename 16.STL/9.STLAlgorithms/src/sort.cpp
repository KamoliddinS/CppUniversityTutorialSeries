#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 3, 1, 4, 2};

    std::sort(vec.begin(), vec.end());

    std::cout << "Sorted Vector: ";
    for(auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
