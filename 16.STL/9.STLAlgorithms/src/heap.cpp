#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 9};

    std::make_heap(vec.begin(), vec.end());

    std::cout << "Max element: " << vec.front() << std::endl;

    std::pop_heap(vec.begin(), vec.end()); 
    vec.pop_back();

    std::cout << "Max element after pop: " << vec.front() << std::endl;

    return 0;
}
