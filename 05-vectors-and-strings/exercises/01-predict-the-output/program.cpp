// Exercise 1: Predict the output
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> numbers = {4, 8};
    numbers.push_back(15);
    numbers.push_back(16);
    numbers.pop_back();
    std::cout << numbers.size() << ' ' << numbers[1] << ' ' << numbers.back() << '\n';

    for (int n : numbers) {
        n = n * 2;
    }
    for (int& n : numbers) {
        n = n + 1;
    }
    for (int n : numbers) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    std::string city = "Samarkand";
    std::cout << city.size() << ' ' << city.find('a') << ' ' << city.substr(3, 2) << '\n';
}
