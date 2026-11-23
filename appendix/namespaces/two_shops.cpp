#include <iostream>

namespace bakery {
    int price() { return 4000; }        // one loaf of bread, in so'm
}

namespace bookshop {
    int price() { return 45000; }       // one set of notebooks, in so'm
}

int main() {
    std::cout << "Bread: " << bakery::price() << " so'm\n";
    std::cout << "Notebooks: " << bookshop::price() << " so'm\n";
}
