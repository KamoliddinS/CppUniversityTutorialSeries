#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

// Decimal to Binary
std::string decToBinary(int n) {
    if (n == 0) return "0";
    std::string binary = "";
    while (n) {
        binary += std::to_string(n % 2);
        n /= 2;
    }
    std::reverse(binary.begin(), binary.end());

    // easy way
    // return std::bitset<32>(n).to_string();;
    return binary;
}

// Binary to Decimal
int binaryToDec(const std::string &binary) {
    int decimal = 0;
    for (int i = 0; i < binary.length(); i++) {
        decimal += (binary[i] - '0') * pow(2, binary.length() - 1 - i);
    }
    //easy way 
    // return std::bitset<32>(binary).to_ulong();
    return decimal;
}

// Decimal to Hex
std::string decToHex(int n) {
    if (n == 0) return "0";
    const char hexChars[] = "0123456789ABCDEF";
    std::string hex = "";
    while (n) {
        hex += hexChars[n % 16];
        n /= 16;
    }
    std::reverse(hex.begin(), hex.end());

    // easy way
    // std::stringstream ss;
    return hex;
}

// Hex to Decimal
int hexToDec(const std::string &hex) {
    int decimal = 0;
    for (int i = 0; i < hex.length(); i++) {
        char c = hex[i];
        int value = (c >= '0' && c <= '9') ? (c - '0') : (c - 'A' + 10);
        decimal += value * pow(16, hex.length() - 1 - i);
    }
    return decimal;
}

// Decimal to Octal
std::string decToOctal(int n) {
    if (n == 0) return "0";
    std::string octal = "";
    while (n) {
        octal += std::to_string(n % 8);
        n /= 8;
    }
    std::reverse(octal.begin(), octal.end());
    return octal;
}

// Octal to Decimal
int octalToDec(const std::string &octal) {
    int decimal = 0;
    for (int i = 0; i < octal.length(); i++) {
        decimal += (octal[i] - '0') * pow(8, octal.length() - 1 - i);
    }
    return decimal;
}

int main() {
    // Test the functions
    int decimal = 255;
    std::cout << "Decimal: " << decimal << std::endl;
    std::cout << "Binary: " << decToBinary(decimal) << std::endl;
    std::cout << "Hex: " << decToHex(decimal) << std::endl;
    std::cout << "Octal: " << decToOctal(decimal) << std::endl;

    std::string binary = "11111111";
    std::cout << "Binary to Decimal: " << binaryToDec(binary) << std::endl;

    std::string hex = "FF";
    std::cout << "Hex to Decimal: " << hexToDec(hex) << std::endl;

    std::string octal = "377";
    std::cout << "Octal to Decimal: " << octalToDec(octal) << std::endl;

    return 0;
}
