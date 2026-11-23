#include <fstream>
#include <iostream>

int main() {
    std::ofstream out("scores.txt");    // creates the file, or empties an old one
    if (!out) {
        std::cout << "Cannot create scores.txt\n";
        return 1;
    }

    out << "Aziz " << 85 << '\n';       // write with <<, as with std::cout
    out << "Malika " << 92 << '\n';
    out << "Jasur " << 78 << '\n';
    std::cout << "Saved 3 scores.\n";
}
