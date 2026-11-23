#include <functional>
#include <iostream>

int main() {
    int bonus = 5;

    std::function<int(int)> change = [](int x) { return x * 2; };
    std::cout << change(10) << '\n';

    change = [bonus](int x) { return x + bonus; };   // another lambda, the same variable
    std::cout << change(10) << '\n';
}
