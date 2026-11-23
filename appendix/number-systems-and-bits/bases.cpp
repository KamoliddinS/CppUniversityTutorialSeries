#include <bitset>
#include <iostream>

int main() {
    int binary = 0b1010;
    int hexadecimal = 0x1F;
    int octal = 0547;   // careful: a leading 0 means octal (base 8)
    std::cout << binary << ' ' << hexadecimal << ' ' << octal << '\n';

    int n = 31;
    std::cout << std::bitset<8>(n) << '\n';   // n as 8 bits
    std::cout << std::hex << n << '\n';       // n in hexadecimal
    std::cout << std::dec << n << '\n';       // back to decimal
}
