#include <iostream>

int main() {
    int a = 7;
    int b = 2;
    double x = a / b;
    double y = a / 2.0;
    double z = static_cast<double>(a / b);
    int w = a / 2.0;
    std::cout << x << ' ' << y << ' ' << z << ' ' << w << '\n';
}
