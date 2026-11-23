// Exercise 2: Hours, minutes, seconds
// Read a number of seconds. Print it as hours, minutes and seconds, for example:
//     3725 s = 1 h 2 min 5 s
#include <iostream>

int main() {
    constexpr int secondsPerMinute = 60;
    constexpr int secondsPerHour = 60 * secondsPerMinute;

    int total = 0;
    std::cin >> total;

    int hours = total / secondsPerHour;
    int minutes = 0;    // TODO: the full minutes that are left after the hours
    int seconds = 0;    // TODO: the seconds that are left after the minutes

    std::cout << total << " s = " << hours << " h " << minutes << " min " << seconds << " s\n";
}
