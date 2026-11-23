#include <iostream>

void visit() {
    int normal = 0;             // created again at every call
    static int kept = 0;        // created only once
    ++normal;
    ++kept;
    std::cout << "normal: " << normal << "   static: " << kept << '\n';
}

int main() {
    visit();
    visit();
    visit();
}
