#include <iostream>

int main() {
    int azizScore = 70;
    int malikaScore = azizScore;
    azizScore = 90;
    std::cout << azizScore << ' ' << malikaScore << '\n';
}
