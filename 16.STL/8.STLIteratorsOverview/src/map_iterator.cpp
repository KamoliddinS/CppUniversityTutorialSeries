#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> ageMap = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};

    // Iterating over a map using iterators
    std::cout << "Age Map:" << std::endl;
    for(auto it = ageMap.begin(); it != ageMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
