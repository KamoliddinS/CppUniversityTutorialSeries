#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> ageMap;
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    ageMap["Charlie"] = 35;

    // Accessing elements
    std::cout << "Alice's age: " << ageMap["Alice"] << std::endl;

    // Iterating over the map
    std::cout << "Age Map:" << std::endl;
    for(auto& pair : ageMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
