#include <iostream>
#include <string>

struct Book {
    std::string title;
    int pages = 0;
};

template <typename T>
T larger(const T& a, const T& b) {
    return (a > b) ? a : b;   // needs > for T
}

int main() {
    Book atlas{"Atlas", 120};
    Book novel{"O'tkan kunlar", 400};
    Book thicker = larger(atlas, novel);
    std::cout << thicker.title << '\n';
}
