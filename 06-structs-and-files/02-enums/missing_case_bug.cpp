#include <iostream>

enum class Level { beginner, middle, advanced };

int main() {
    Level level = Level::advanced;

    switch (level) {
    case Level::beginner:
        std::cout << "Start with lesson 1.\n";
        break;
    case Level::middle:
        std::cout << "Start with lesson 10.\n";
        break;
    }
}
