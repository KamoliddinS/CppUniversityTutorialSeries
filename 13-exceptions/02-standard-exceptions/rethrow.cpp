#include <exception>
#include <iostream>
#include <stdexcept>

void writeFile() {
    throw std::runtime_error("disk is full");
}

void saveReport() {
    try {
        writeFile();
    } catch (const std::exception& e) {
        std::cout << "saveReport: " << e.what() << '\n';
        throw;                      // pass the same exception on
    }
}

int main() {
    try {
        saveReport();
    } catch (const std::runtime_error& e) {
        std::cout << "main: " << e.what() << '\n';
    }

    try {
        throw 42;                   // legal, but 42 is not a std::exception
    } catch (const std::exception&) {
        std::cout << "not reached\n";
    } catch (...) {
        std::cout << "main: caught something else\n";
    }
}
