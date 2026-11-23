#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> names = {"Malika", "Aziz", "Jasur"};

    for (auto it = names.begin(); it != names.end(); ++it) {
        std::cout << *it << " has " << it->size() << " letters\n";
    }

    std::set<int> years = {2026, 2024, 2025};
    for (auto it = years.begin(); it != years.end(); ++it) {   // the same loop
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}
