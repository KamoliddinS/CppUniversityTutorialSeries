#include <iostream>

int main() {
    int score = 10;
    score += 5;             // score = score + 5
    score *= 2;             // score = score * 2
    score++;                // score = score + 1
    std::cout << score << '\n';

    int a = 5;
    int b = a++;            // b gets the old value, then a grows
    int c = ++a;            // a grows first, then c gets the new value
    std::cout << a << ' ' << b << ' ' << c << '\n';
}
