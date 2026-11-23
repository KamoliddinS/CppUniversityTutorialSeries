#include <iostream>

void swapValues(int& a, int& b) {
    int old = a;
    a = b;
    b = old;
}

void splitMinutes(int total, int& hours, int& minutes) {
    hours = total / 60;
    minutes = total % 60;
}

int main() {
    int aziz = 70;
    int jasur = 95;
    swapValues(aziz, jasur);
    std::cout << "Aziz " << aziz << ", Jasur " << jasur << '\n';

    int hours = 0;
    int minutes = 0;
    splitMinutes(135, hours, minutes);
    std::cout << "135 minutes = " << hours << " h " << minutes << " min\n";
}
