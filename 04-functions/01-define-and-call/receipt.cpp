#include <iostream>

void drawLine() {
    for (int i = 0; i < 24; ++i) {
        std::cout << '-';
    }
    std::cout << '\n';
}

int main() {
    drawLine();
    std::cout << "Notebook      12000 so'm\n";
    std::cout << "Pen            3000 so'm\n";
    drawLine();
    std::cout << "Total         15000 so'm\n";
    drawLine();
}
