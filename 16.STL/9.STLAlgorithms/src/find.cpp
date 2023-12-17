#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int val = 3;

    auto result = std::find(vec.begin(), vec.end(), val);
    if (result != vec.end()) {
        std::cout << "Element " << val << " found at position: " << (result - vec.begin()) << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
