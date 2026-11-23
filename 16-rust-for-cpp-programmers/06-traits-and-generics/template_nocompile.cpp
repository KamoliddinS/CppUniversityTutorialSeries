#include <iostream>
#include <string>

struct Book {
    std::string title;
    int pages = 0;
};

template <typename T>
T larger(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    Book atlas{"Atlas", 120};
    Book novel{"Novel", 400};
    std::cout << larger(atlas, novel).title << '\n';
}
