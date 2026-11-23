#include <iostream>

int main() {
    double sum = 0.0;                   // double: sum / count keeps the decimals
    int count = 0;
    bool anyFailed = false;

    while (true) {
        std::cout << "Mark (0 to finish): ";
        int mark = 0;
        std::cin >> mark;
        if (mark == 0) {
            break;
        }
        sum += mark;                    // sum: add every value
        ++count;                        // count: add 1 for every value
        if (mark < 60) {
            anyFailed = true;           // search: remember that one was found
        }
    }

    if (count != 0) {
        std::cout << count << " marks, average " << sum / count << '\n';
    }
    if (anyFailed) {
        std::cout << "Somebody did not pass.\n";
    }
}
