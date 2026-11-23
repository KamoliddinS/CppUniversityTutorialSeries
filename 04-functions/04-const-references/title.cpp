#include <iostream>
#include <string>

void printTitle(const std::string& title) {     // no copy, no change
    std::cout << "== " << title << " ==\n";
}

int main() {
    std::string city = "Samarkand";
    printTitle(city);               // a variable
    printTitle(city + " 2026");     // a result that has no name
    printTitle("Khiva");            // a literal
}
