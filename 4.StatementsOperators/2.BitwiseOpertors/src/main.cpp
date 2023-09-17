#include <iostream>

int main() {
    // Bitwise AND
    int a = 5;  // 0101 in binary
    int b = 3;  // 0011 in binary
    int result = a & b;  // 0001 in binary which is 1 in decimal
    std::cout << "Bitwise AND of " << a << " and " << b << " is: " << result << std::endl;

    // Bitwise OR
    result = a | b;  // 0111 in binary which is 7 in decimal
    std::cout << "Bitwise OR of " << a << " and " << b << " is: " << result << std::endl;

    // Bitwise XOR
    result = a ^ b;  // 0110 in binary which is 6 in decimal
    std::cout << "Bitwise XOR of " << a << " and " << b << " is: " << result << std::endl;

    // Bitwise NOT
    result = ~a;  // 1010 in binary which is -6 in decimal (due to two's complement representation)
    std::cout << "Bitwise NOT of " << a << " is: " << result << std::endl;

    // Left Shift
    result = a << 1;  // 1010 in binary which is 10 in decimal
    std::cout << a << " left shifted by 1 is: " << result << std::endl;

    // Right Shift
    result = a >> 1;  // 0010 in binary which is 2 in decimal
    std::cout << a << " right shifted by 1 is: " << result << std::endl;

    return 0;
}
