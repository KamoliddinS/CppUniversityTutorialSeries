#include <cstddef>
#include <iostream>

void report(std::size_t days) {
    int* visitors = new int[days]{};        // take: one counter for each day
    if (days < 7) {
        std::cout << "Need at least a week of data.\n";
        return;                             // leaves early: the delete[] below never runs
    }
    visitors[0] = 120;
    std::cout << "First day: " << visitors[0] << " visitors\n";
    delete[] visitors;                      // give back
}

int main() {
    report(7);
    report(3);
}
