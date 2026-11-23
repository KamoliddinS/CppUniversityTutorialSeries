#include <iostream>

int main() {
    int flat = 900000000;           // one flat costs 900 million so'm
    int total = flat * 3;           // 2 700 000 000 is too big for an int
    std::cout << "Three flats: " << total << " so'm\n";
}
