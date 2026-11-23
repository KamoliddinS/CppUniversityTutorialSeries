#include <iostream>

int main() {
    char grade = 'B';           // single quotes: exactly one character
    int code = grade;           // a char is stored as a small number
    char better = grade - 1;    // so you can calculate with it

    std::cout << grade << " is stored as " << code << '\n';
    std::cout << "One step better: " << better << '\n';
}
