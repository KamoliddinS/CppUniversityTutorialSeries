// Gradebook, step 3: A gradebook class
// This file reads the commands and prints. All work on the students is done by the class
// Gradebook (gradebook.h and gradebook.cpp). This starter knows two commands: count and quit.
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "gradebook.h"

int main() {
    std::cout << std::fixed << std::setprecision(2);

    Gradebook book;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream words(line);
        std::string command;
        if (!(words >> command)) {
            continue;                           // an empty line
        }
        if (command == "quit") {
            break;
        }
        if (command == "count") {
            std::cout << "students: " << book.size() << '\n';
        } else {
            // TODO: the other commands. Each one calls a member function of book, such as
            // book.addStudent(name, score). The error lines are printed here, not in the class.
            std::cout << "error: unknown command " << command << '\n';
        }
    }
}
