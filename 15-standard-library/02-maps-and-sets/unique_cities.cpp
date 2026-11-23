#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> cities;
    cities.insert("Samarkand");
    cities.insert("Khiva");
    cities.insert("Samarkand");             // already there: nothing happens
    cities.insert("Bukhara");

    for (const std::string& city : cities) {
        std::cout << city << '\n';
    }
    std::cout << cities.size() << " cities\n";
}
