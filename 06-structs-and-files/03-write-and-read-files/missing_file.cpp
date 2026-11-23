#include <fstream>
#include <iostream>

int main() {
    std::ifstream in("marks.txt");      // there is no such file
    int mark = 0;
    int total = 0;
    while (in >> mark) {
        total += mark;
    }
    std::cout << "Total: " << total << '\n';
}
