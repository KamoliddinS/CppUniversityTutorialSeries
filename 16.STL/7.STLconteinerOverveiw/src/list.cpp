#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};

    // Adding elements
    lst.push_front(0);
    lst.push_back(6);

    // Iterating over the list
    std::cout << "List elements: ";
    for(int i : lst) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
