#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3};
    for (int n : numbers) {
        n = n * 10;
    }
    for (int& n : numbers) {
        n = n + 1;
    }
    for (int n : numbers) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}
