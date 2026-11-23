#include <iostream>

int main() {
    int prices[4] = {500, 700, 900, 1200};
    int* p = prices;        // decay: p points to prices[0]

    std::cout << "sizeof(prices): " << sizeof(prices) << '\n';
    std::cout << "sizeof(p):      " << sizeof(p) << '\n';

    std::cout << p << " holds " << *p << '\n';
    std::cout << p + 1 << " holds " << *(p + 1) << '\n';
    std::cout << p + 2 << " holds " << p[2] << '\n';
}
