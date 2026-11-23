#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> scores;      // key: a name, value: a score
    scores["Malika"] = 95;
    scores["Aziz"] = 90;
    scores["Jasur"] = 72;
    scores["Aziz"] = 91;                    // the key exists: its value is replaced

    for (const auto& [name, score] : scores) {
        std::cout << name << ": " << score << '\n';
    }
    std::cout << scores.size() << " entries\n";
}
