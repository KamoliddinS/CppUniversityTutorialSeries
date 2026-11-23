#include <iostream>
#include <string>
#include <utility>

int main() {
    std::string a = "Samarkand";
    std::string b = a;                // copy: a and b each have the text
    std::string c = std::move(a);     // move: c takes the text out of a
    std::cout << "b = " << b << ", c = " << c << '\n';
    std::cout << "a has " << a.size() << " letters\n";   // builds without a warning
}
