#include <iostream>
#include <string>

int larger(int a, int b) {
    return (a > b) ? a : b;
}

double larger(double a, double b) {
    return (a > b) ? a : b;
}

std::string larger(std::string a, std::string b) {
    return (a > b) ? a : b;
}

int main() {
    std::string first = "Samarkand";
    std::string second = "Tashkent";

    std::cout << larger(3, 7) << '\n';
    std::cout << larger(2.5, 1.5) << '\n';
    std::cout << larger(first, second) << '\n';
}
