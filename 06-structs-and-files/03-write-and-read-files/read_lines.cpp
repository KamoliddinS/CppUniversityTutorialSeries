#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream in("scores.txt");
    if (!in) {
        std::cout << "Cannot open scores.txt\n";
        return 1;
    }

    std::string line;
    int count = 0;
    while (std::getline(in, line)) {
        ++count;
        std::cout << count << ": " << line << '\n';
    }
}
