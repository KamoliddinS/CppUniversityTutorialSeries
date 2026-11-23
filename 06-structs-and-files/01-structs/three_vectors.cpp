#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> names = {"Malika", "Aziz", "Jasur"};
    std::vector<int> ages = {19, 20, 18};
    std::vector<double> grades = {4.8, 4.5, 3.9};

    std::ranges::sort(names);   // only the names move

    for (std::size_t i = 0; i < names.size(); ++i) {
        std::cout << names[i] << ' ' << ages[i] << ' ' << grades[i] << '\n';
    }
}
