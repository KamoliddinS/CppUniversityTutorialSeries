#include <iostream>

// Here we have macro definitions
#define PI 3.14159
#define SQUARE(x) ((x) * (x))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#define DEBUG

int main() {
    std::cout << "Value of PI: " << PI << std::endl;

    int num = 5;
    std::cout << "Square of " << num << " is " << SQUARE(num) << std::endl;

    int a = 10, b = 20;
    std::cout << "Minimum of " << a << " and " << b << " is " << MIN(a, b) << std::endl;

    #ifdef DEBUG
        std::cout << "Debugging is enabled" << std::endl;
    #endif

    return 0;
}
