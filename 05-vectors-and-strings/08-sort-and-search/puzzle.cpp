#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> names = {"Malika", "aziz", "Jasur", "Dilnoza"};
    std::ranges::sort(names);
    for (const std::string& name : names) {
        std::cout << name << ' ';
    }
    std::cout << '\n';
}
