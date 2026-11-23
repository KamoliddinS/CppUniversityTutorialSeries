// Binary converter: Convert and add
// The assignment is in README.md. This starter knows one command: quit.
#include <iostream>
#include <string>

int main() {
    std::string command;
    while (std::cin >> command && command != "quit") {
        // TODO: to-binary, to-decimal and add. Read every number as a word: a std::string.
        std::cout << "error: unknown command " << command << '\n';
        // TODO: skip what is left of the line, so that the next command starts on a new line.
    }
}
