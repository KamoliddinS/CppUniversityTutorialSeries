#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    std::transform(vec.begin(), vec.end(), vec.begin(), [](int x) { return x * 2; });

    std::cout << "Transformed Vector: ";
    for(auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
