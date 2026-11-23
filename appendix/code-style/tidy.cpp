#include <iostream>

int freeSeats(int taken) {
    constexpr int maxSeats = 40;
    return maxSeats - taken;
}

int main() {
    int taken = 28;
    std::cout << "Free seats: " << freeSeats(taken) << '\n';
}
