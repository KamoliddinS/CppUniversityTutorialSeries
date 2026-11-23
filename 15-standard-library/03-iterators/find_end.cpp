#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> names = {"Aziz", "Malika", "Jasur"};
    auto it = std::ranges::find(names, "Malika");
    if (it != names.end()) {                       // not end(): Malika was found
        std::cout << *it << " is at index " << it - names.begin() << '\n';
    }
    if (std::ranges::find(names, "Nodira") == names.end()) {
        std::cout << "Nodira is not in the list\n";
    }

    std::map<std::string, int> scores = {{"Aziz", 90}, {"Malika", 95}};
    auto entry = scores.find("Aziz");              // a map has its own find
    if (entry != scores.end()) {
        std::cout << entry->first << " has " << entry->second << '\n';
    }
}
