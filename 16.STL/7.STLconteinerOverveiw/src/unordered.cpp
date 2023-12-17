#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> wordCount;
    wordCount["hello"] = 1;
    wordCount["world"] = 2;

    // Accessing elements
    std::cout << "Word count for 'hello': " << wordCount["hello"] << std::endl;

    // Iterating over the unordered map
    std::cout << "Word Count:" << std::endl;
    for(auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
