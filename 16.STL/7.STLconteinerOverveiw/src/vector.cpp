#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Adding an element
    vec.push_back(6);

    // Iterating over the vector
    std::cout << "Vector elements: ";
    for(int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
