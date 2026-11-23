// Exercise 5: Parse a score
// Write parseScore. The program checks it and tells you which cases are wrong.
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>

// Returns the score when text is a whole number from 0 to 100.
// Returns no value for every other text. It never throws.
std::optional<int> parseScore(const std::string& text) {
    // TODO: this line is not enough. Make every check in main pass.
    return std::stoi(text);
}

// Prints one line for a check. Returns the number of mistakes: 0 or 1.
int check(const std::string& text, std::optional<int> expected) {
    std::cout << '"' << text << "\": ";
    try {
        if (parseScore(text) == expected) {
            std::cout << "ok\n";
            return 0;
        }
        std::cout << "WRONG\n";
    } catch (const std::exception& e) {
        std::cout << "WRONG, parseScore threw an exception: " << e.what() << '\n';
    }
    return 1;
}

int main() {
    int wrong = 0;
    wrong += check("87", 87);
    wrong += check("0", 0);
    wrong += check("100", 100);
    wrong += check("101", std::nullopt);
    wrong += check("-3", std::nullopt);
    wrong += check("abc", std::nullopt);
    wrong += check("", std::nullopt);
    wrong += check("99999999999", std::nullopt);

    std::cout << wrong << " wrong\n";
    if (wrong > 0) {
        return 1;       // tells the check that the exercise is not finished
    }
}
