#include <iostream>
#include <stdexcept>
#include <string>

int toAge(const std::string& text) {
    int age = std::stoi(text);      // may throw std::invalid_argument or std::out_of_range
    if (age < 0) {
        throw std::runtime_error("an age cannot be negative");
    }
    return age;
}

void show(const std::string& text) {
    try {
        int age = toAge(text);
        std::cout << text << ": age " << age << '\n';
    } catch (const std::invalid_argument&) {
        std::cout << text << ": not a number\n";
    } catch (const std::out_of_range&) {
        std::cout << text << ": too large for an int\n";
    } catch (const std::exception& e) {     // every other standard exception
        std::cout << text << ": " << e.what() << '\n';
    }
}

int main() {
    show("19");
    show("abc");
    show("99999999999");
    show("-5");
}
