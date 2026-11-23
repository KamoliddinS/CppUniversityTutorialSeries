#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream in("scores.txt");
    if (!in) {                          // always test, right after opening
        std::cout << "Cannot open scores.txt\n";
        return 1;
    }

    std::string name;
    int score = 0;
    int total = 0;
    while (in >> name >> score) {       // the loop ends when a read fails
        std::cout << name << " has " << score << '\n';
        total += score;
    }
    std::cout << "Total: " << total << '\n';
}
