#include <iostream>

void greet();   // promised here, but written nowhere

int main() {
    greet();
    std::cout << "Done.\n";
}
