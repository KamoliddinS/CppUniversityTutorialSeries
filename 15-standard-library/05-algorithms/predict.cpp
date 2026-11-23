#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<double> halves = {0.5, 0.5, 0.5, 0.5};
    std::cout << std::accumulate(halves.begin(), halves.end(), 0) << '\n';
}
