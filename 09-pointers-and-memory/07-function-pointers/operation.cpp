#include <iostream>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int (*operation)(int, int) = add;       // operation points to the function add
    std::cout << operation(2, 3) << '\n';

    operation = multiply;                   // now it points to multiply
    std::cout << operation(2, 3) << '\n';
}
