// Exercise 2: Fix the build
// This file does not compile yet. Fixing it is the exercise.
// Do not change main.
#include <iostream>

class Weight {
public:
    Weight(int kg, int grams) : grams_(kg * 1000 + grams) {}

    Weight operator+(const Weight& other) {
        return Weight(0, grams_ + other.grams_);
    }

    Weight operator*(int count) const {
        return Weight(0, grams_ * count);
    }

private:
    int grams_ = 0;     // the whole weight in grams: 1 kg = 1000 g
};

void operator<<(std::ostream& out, const Weight& w) {
    out << w.grams_ / 1000 << " kg " << w.grams_ % 1000 << " g";
}

int main() {
    const Weight apples(1, 500);
    const Weight grapes(0, 750);

    Weight bag = apples + grapes;
    Weight box = 4 * bag;
    std::cout << "One bag: " << bag << '\n';
    std::cout << "Four bags: " << box << '\n';
}
