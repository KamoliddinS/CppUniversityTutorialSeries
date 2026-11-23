#include <iostream>

void drawLine(int length = 20, char symbol = '-');      // the defaults are written here

int main() {
    drawLine();             // 20 times '-'
    drawLine(10);           // 10 times '-'
    drawLine(10, '=');      // 10 times '='
}

void drawLine(int length, char symbol) {                // and not again here
    for (int i = 0; i < length; ++i) {
        std::cout << symbol;
    }
    std::cout << '\n';
}
