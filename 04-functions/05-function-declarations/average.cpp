#include <iostream>

double average(int first, int second);      // declarations: these functions exist
void printReport(int first, int second);

int main() {
    printReport(80, 91);
    printReport(60, 75);
}

void printReport(int first, int second) {   // definitions: the bodies
    std::cout << first << " and " << second << ": " << average(first, second) << '\n';
}

double average(int first, int second) {
    return (first + second) / 2.0;
}
