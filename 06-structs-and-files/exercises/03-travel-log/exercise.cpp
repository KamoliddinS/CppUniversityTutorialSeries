// Exercise 3: Travel log
// The program should save three stops of a trip in trip.txt, add a fourth one,
// and then print the whole list. It builds and runs, but the output is wrong.
// Find the two bugs and fix them.
#include <fstream>
#include <iostream>
#include <string>

bool saveStops() {
    std::ofstream out("trip.txt");
    if (!out) {
        return false;
    }
    out << "Tashkent\n";
    out << "Samarkand\n";
    out << "Bukhara\n";
    return true;
}

bool addStop(const std::string& city) {
    std::ofstream out("trip.txt");
    if (!out) {
        return false;
    }
    out << city << '\n';
    return true;
}

int main() {
    if (!saveStops() || !addStop("Khiva")) {
        std::cout << "Cannot write trip.txt\n";
        return 1;
    }

    std::ifstream in("trip.txt");
    if (!in) {
        std::cout << "Cannot open trip.txt\n";
        return 1;
    }

    std::string city;
    int count = 0;
    while (!in.eof()) {
        in >> city;
        ++count;
        std::cout << count << ". " << city << '\n';
    }
    std::cout << "Stops: " << count << '\n';
}
