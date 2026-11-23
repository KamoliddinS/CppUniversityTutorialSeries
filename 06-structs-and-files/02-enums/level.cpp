#include <iostream>
#include <string>

enum class Level { beginner, middle, advanced };

std::string toText(Level level) {
    switch (level) {
    case Level::beginner:
        return "beginner";      // return leaves the function: no break needed
    case Level::middle:
        return "middle";
    case Level::advanced:
        return "advanced";
    }
    return "unknown";
}

int main() {
    Level level = Level::middle;

    if (level == Level::middle) {
        std::cout << "You are in the middle group.\n";
    }
    std::cout << "As text:     " << toText(level) << '\n';
    std::cout << "As a number: " << static_cast<int>(level) << '\n';
}
