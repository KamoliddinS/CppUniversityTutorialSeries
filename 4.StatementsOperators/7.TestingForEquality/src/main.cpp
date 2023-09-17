#include <iostream>
#include <cmath>      // For fabs function
#include <string>

int main() {
    // Testing basic integer equality
    int a = 5;
    int b = 5;
    if (a == b) {
        std::cout << "a and b are equal." << std::endl;
    } else {
        std::cout << "a and b are not equal." << std::endl;
    }

    // Testing integer inequality
    int x = 10;
    int y = 20;
    if (x != y) {
        std::cout << "x and y are not equal." << std::endl;
    } else {
        std::cout << "x and y are equal." << std::endl;
    }

    // Testing floating point equality with a threshold
    double m = 0.1 + 0.1 + 0.1;
    double n = 0.3;
    if (fabs(m - n) < 1e-9) {
        std::cout << "m and n are almost equal." << std::endl;
    } else {
        std::cout << "m and n are not equal." << std::endl;
    }

    // Testing string equality
    std::string str1 = "hello";
    std::string str2 = "hello";
    if (str1 == str2) {
        std::cout << "Both strings are equal." << std::endl;
    } else {
        std::cout << "Strings are not equal." << std::endl;
    }

    return 0;
}

