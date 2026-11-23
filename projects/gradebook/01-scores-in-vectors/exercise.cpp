// Gradebook, step 1: Scores in vectors
// The assignment is in README.md. This starter knows two commands: count and quit.
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Prints every decimal number with two digits after the point, such as 82.33.
    // Chapter 06 explains this line. Keep it as it is.
    std::cout << std::fixed << std::setprecision(2);

    std::vector<std::string> names;
    std::vector<int> scores;            // scores[i] is the score of names[i]

    std::string command;
    while (std::cin >> command && command != "quit") {
        if (command == "count") {
            std::cout << "students: " << names.size() << '\n';
        } else {
            // TODO: add, list, show, average and best.
            std::cout << "error: unknown command " << command << '\n';
        }
        // TODO: skip what is left of the line, so that the next command starts on a new line.
    }
}
