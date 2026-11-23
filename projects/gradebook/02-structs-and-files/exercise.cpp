// Gradebook, step 2: Structs and files
// The assignment is in README.md. Copy the functions of your step 1 program into this file
// and change them to work with one std::vector<Student>.
// This starter knows two commands: count and quit.
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    std::vector<int> scores;
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    std::vector<Student> students;
    std::string line;
    while (std::getline(std::cin, line)) {      // one whole line is one command
        std::istringstream words(line);         // read the words of the line with >>
        std::string command;
        if (!(words >> command)) {
            continue;                           // an empty line
        }
        if (command == "quit") {
            break;
        }
        if (command == "count") {
            std::cout << "students: " << students.size() << '\n';
        } else {
            // TODO: the commands of step 1, then add-score, report, save and load.
            // Read the arguments from words, not from std::cin.
            std::cout << "error: unknown command " << command << '\n';
        }
    }
}
