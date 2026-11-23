// Exercise 2: Fix the calls
// This file does not compile yet. Fixing it is the exercise.
// The template larger is correct: do not change it. Fix the code that uses it.
#include <iostream>
#include <string>

struct Room {
    std::string name;
    double area = 0.0;   // in square metres
};

template <typename T>
T larger(const T& a, const T& b) {
    return (a > b) ? a : b;
}

int main() {
    int laps = 12;
    double best = 11.5;
    std::cout << larger(laps, best) << '\n';

    std::cout << larger(7, 2.5) / 2 << '\n';

    std::string home = "Khiva";
    std::cout << larger(home, "Bukhara") << '\n';

    Room kitchen{"kitchen", 12.5};
    Room hall{"hall", 20.0};
    std::cout << larger(kitchen, hall).name << '\n';
}
