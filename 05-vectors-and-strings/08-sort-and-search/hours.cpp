#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<double> hours = {1.5, 2.5, 3.5};      // study time on three days

    double wrong = std::accumulate(hours.begin(), hours.end(), 0);      // adds up as an int
    double right = std::accumulate(hours.begin(), hours.end(), 0.0);    // adds up as a double
    std::cout << wrong << ' ' << right << '\n';
}
