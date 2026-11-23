// Exercise 5: Three files
// This program does not compile yet. Fixing it is the exercise.
// It is made of three files: main.cpp, thermostat.cpp and thermostat.h.
#include <iostream>

#include <thermostat.h>

int main() {
    int start = 0;
    std::cin >> start;
    Thermostat thermostat(start);
    std::cout << "Start: " << thermostat.degrees() << '\n';

    char key = ' ';
    while (std::cin >> key) {
        if (key == '+') {
            thermostat.warmer();
        } else if (key == '-') {
            thermostat.cooler();
        }
        std::cout << thermostat.degrees() << '\n';
    }
}
