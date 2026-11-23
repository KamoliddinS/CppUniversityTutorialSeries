// Exercise 4: Marks
// This file does not compile yet: report and main use a class that is not written.
// Write the class Marks. Do not change report and main.
#include <iomanip>
#include <iostream>
#include <vector>

// TODO: write the class Marks here.

void report(const Marks& marks) {
    std::cout << "Count: " << marks.count() << '\n';
    std::cout << "Best: " << marks.best() << '\n';
    std::cout << "Average: " << std::fixed << std::setprecision(1) << marks.average() << '\n';
}

int main() {
    Marks marks;
    int mark = 0;
    while (std::cin >> mark) {
        if (!marks.add(mark)) {
            std::cout << "Ignored: " << mark << '\n';
        }
    }
    report(marks);
}
