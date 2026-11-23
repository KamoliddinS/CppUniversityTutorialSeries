#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> scores = {{"Aziz", 90}, {"Malika", 95}};
    std::cout << "size: " << scores.size() << '\n';

    if (scores["Nobody"] == 0) {            // looks like a question, but adds "Nobody"
        std::cout << "Nobody has no score\n";
    }
    std::cout << "size: " << scores.size() << '\n';

    if (scores.contains("Dilnoza")) {       // a real question: adds nothing
        std::cout << "Dilnoza: " << scores.at("Dilnoza") << '\n';
    }
    std::cout << "size: " << scores.size() << '\n';
}
