// Exercise 1: Predict the pointers
// Do not run this program yet. Draw the memory table on paper, then write
// what the program prints into prediction.txt.
#include <iostream>

struct Point {
    int x = 0;
    int y = 0;
};

int main() {
    int a = 5;
    int b = 7;
    int* p = &a;
    int* q = &b;

    *p = *q + 1;
    std::cout << a << ' ' << b << '\n';

    q = p;
    *q = 20;
    std::cout << a << ' ' << b << '\n';

    int values[4] = {10, 20, 30, 40};
    p = values + 1;
    std::cout << *p << ' ' << p[1] << ' ' << *(p + 2) << '\n';

    ++p;
    *p = *p + *values;
    std::cout << values[2] << ' ' << p - values << '\n';

    Point corner = {3, 4};
    Point* where = &corner;
    where->x = where->y * 2;
    std::cout << corner.x << ' ' << corner.y << '\n';
}
