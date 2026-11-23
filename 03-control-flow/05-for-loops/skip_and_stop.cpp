#include <iostream>

int main() {
    for (int day = 1; day <= 7; ++day) {
        if (day == 3) {
            continue;                   // skip the rest of this round
        }
        if (day == 6) {
            break;                      // leave the loop
        }
        std::cout << "Day " << day << '\n';
    }
    std::cout << "Done.\n";
}
