#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {                        // the program's name and two arguments
        std::cout << "Usage: first_lines FILE COUNT\n";
        return 1;
    }
    std::string fileName = argv[1];
    int count = std::stoi(argv[2]);         // an argument is text: convert it

    std::ifstream in(fileName);
    if (!in) {
        std::cout << "Cannot open " << fileName << '\n';
        return 1;
    }

    std::string line;
    int shown = 0;
    while (shown < count && std::getline(in, line)) {
        std::cout << line << '\n';
        ++shown;
    }
}
