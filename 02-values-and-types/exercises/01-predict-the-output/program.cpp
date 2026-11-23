// Exercise 1: Predict the output
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>
#include <string>

int main() {
    int a = 17;
    int b = 5;
    std::cout << a / b << ' ' << a % b << '\n';
    std::cout << a - b * 2 << '\n';

    double half = a / 2;
    std::cout << half << ' ' << a / 2.0 << '\n';

    std::string word = "ab";
    std::cout << word + word << ' ' << word.size() << '\n';

    char letter = 'C';          // 'A' is stored as 65
    int code = letter;
    std::cout << letter << ' ' << code << '\n';

    int c = a++;
    std::cout << a << ' ' << c << '\n';
}
