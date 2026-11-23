#include <iostream>

void printA() {
    std::cout << "A\n";
}

void printB() {
    std::cout << "B\n";
    printA();
}

int main() {
    std::cout << "start\n";
    printB();
    printA();
    std::cout << "end\n";
}
