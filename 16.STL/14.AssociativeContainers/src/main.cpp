#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

int main() {
    // Demonstrating set
    std::set<int> numSet = {1, 2, 3, 4, 5};
    numSet.insert(6); // Inserting a new element
    std::cout << "Set contains: ";
    for (int n : numSet) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Demonstrating map
    std::map<std::string, int> ageMap;
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    std::cout << "Bob's age: " << ageMap["Bob"] << std::endl;

    // Demonstrating unordered_set
    std::unordered_set<int> numUSet = {10, 20, 30, 40, 50};
    numUSet.insert(60);
    std::cout << "Unordered set contains: ";
    for (int n : numUSet) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Demonstrating unordered_map
    std::unordered_map<std::string, double> salaryMap;
    salaryMap["Eve"] = 50000.0;
    salaryMap["John"] = 60000.0;
    std::cout << "Eve's salary: " << salaryMap["Eve"] << std::endl;

    return 0;
}
