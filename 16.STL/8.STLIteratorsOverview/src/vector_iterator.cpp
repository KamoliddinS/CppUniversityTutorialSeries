#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Using an iterator to access and modify elements
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        *it *= 2;  // Doubling each element
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
