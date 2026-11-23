#include <iostream>
#include <string>

void printTitle(std::string& title) {       // a plain reference
    std::cout << "== " << title << " ==\n";
}

int main() {
    std::string city = "Samarkand";
    printTitle(city);
    printTitle(city + " 2026");
}
