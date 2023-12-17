#include <iostream>
#include <set>

int main() {
    std::set<int> numSet = {1, 2, 3, 4, 5};

    // Adding an element
    numSet.insert(6);

    // Iterating over the set
    std::cout << "Set elements: ";
    for(int i : numSet) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
