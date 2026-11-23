#include <iostream>

int main() {
    const char* city = "Khiva";                 // points to the 'K'
    std::cout << sizeof("Khiva") << '\n';       // five letters and '\0'

    int letters = 0;
    for (const char* p = city; *p != '\0'; ++p) {
        ++letters;
    }
    std::cout << city << " has " << letters << " letters\n";
}
