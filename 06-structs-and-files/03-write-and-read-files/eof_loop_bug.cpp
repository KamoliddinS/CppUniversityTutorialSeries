#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream in("scores.txt");
    if (!in) {
        std::cout << "Cannot open scores.txt\n";
        return 1;
    }

    std::string name;
    int score = 0;
    int total = 0;
    while (!in.eof()) {                 // wrong: still false after the last score
        in >> name >> score;            // the fourth read fails and changes nothing
        std::cout << name << " has " << score << '\n';
        total += score;
    }
    std::cout << "Total: " << total << '\n';
}
