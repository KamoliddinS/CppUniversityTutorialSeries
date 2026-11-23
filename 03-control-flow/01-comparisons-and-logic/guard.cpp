#include <iostream>

int main() {
    int total = 0;      // sum of all marks
    int count = 0;      // number of marks: there are none yet

    bool goodAverage = count != 0 && total / count >= 60;
    std::cout << std::boolalpha << "good average: " << goodAverage << '\n';
}
