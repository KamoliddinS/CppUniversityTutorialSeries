#include <iostream>
#include <vector>

void removeLast(std::vector<int> numbers) {
    numbers.pop_back();
}

void addZero(std::vector<int>& numbers) {
    numbers.push_back(0);
}

int main() {
    std::vector<int> numbers = {1, 2, 3};
    removeLast(numbers);
    addZero(numbers);
    std::cout << numbers.size() << ' ' << numbers.back() << '\n';
}
