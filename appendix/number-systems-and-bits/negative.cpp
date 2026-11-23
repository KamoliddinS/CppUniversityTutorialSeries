#include <bitset>
#include <iostream>

int main() {
    int n = 5;
    std::cout << std::bitset<8>(n) << "  " << n << '\n';
    std::cout << std::bitset<8>(~n) << "  " << ~n << '\n';           // every bit flipped
    std::cout << std::bitset<8>(~n + 1) << "  " << ~n + 1 << '\n';   // flipped, then 1 added
}
