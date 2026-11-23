#include <iostream>

void greet();   // a promise: greet is written in another file

int main() {
    greet();
    std::cout << "Back in main.\n";
}
