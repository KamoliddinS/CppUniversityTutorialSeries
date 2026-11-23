#include <iostream>
#include <string>

int main() {
    std::string first = "Malika";
    std::string last = "Karimova";
    std::string full = first + " " + last;      // + joins strings

    std::cout << full << '\n';
    std::cout << full.size() << " characters\n";
}
