#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> counts;
    std::string word;
    while (std::cin >> word) {
        ++counts[word];
    }

    for (const auto& [text, count] : counts) {
        std::cout << text << ": " << count << '\n';
    }
}
