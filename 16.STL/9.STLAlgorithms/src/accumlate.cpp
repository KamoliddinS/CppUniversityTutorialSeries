#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    int sum = std::accumulate(vec.begin(), vec.end(), 0);

    std::cout << "Sum of elements: " << sum << std::endl;

    return 0;
}
