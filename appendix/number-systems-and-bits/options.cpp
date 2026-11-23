#include <bitset>
#include <iostream>

int main() {
    constexpr int bold = 0b001;        // each option has its own bit
    constexpr int italic = 0b010;
    constexpr int underline = 0b100;

    int style = bold | underline;             // switch two options on
    std::cout << std::bitset<3>(style) << '\n';

    style = style & ~bold;                    // switch one option off
    style = style ^ italic;                   // flip one option
    std::cout << std::bitset<3>(style) << '\n';

    if ((style & underline) != 0) {           // test one option
        std::cout << "underline is on\n";
    }
}
