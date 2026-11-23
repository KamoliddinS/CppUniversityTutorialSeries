#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<double> weights = {1.5, 2.5, 3.5};     // kilograms

    // Each weight becomes weight * 1000. The results go back into the same vector.
    std::transform(weights.begin(), weights.end(), weights.begin(),
                   [](double kilos) { return kilos * 1000; });

    std::erase_if(weights, [](double grams) { return grams > 3000; });
    for (double grams : weights) {
        std::cout << grams << ' ';
    }
    std::cout << '\n';

    double total = std::accumulate(weights.begin(), weights.end(), 0.0);   // 0.0, not 0
    std::cout << "total: " << total << '\n';

    if (std::binary_search(weights.begin(), weights.end(), 2500.0)) {      // sorted data only
        std::cout << "2500 is there\n";
    }
}
