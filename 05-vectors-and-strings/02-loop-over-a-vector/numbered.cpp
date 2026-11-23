#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> names = {"Aziz", "Malika", "Jasur"};
    std::vector<int> scores = {85, 92, 70};

    for (std::size_t i = 0; i < names.size(); ++i) {
        std::cout << i + 1 << ". " << names[i] << ": " << scores[i] << '\n';
    }
}
