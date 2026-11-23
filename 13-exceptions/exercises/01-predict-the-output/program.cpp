// Exercise 1: Predict the output
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>
#include <stdexcept>
#include <string>

class Step {
public:
    explicit Step(const std::string& name) : name_(name) {
        std::cout << "start " << name_ << '\n';
    }
    ~Step() { std::cout << "end " << name_ << '\n'; }

private:
    std::string name_;
};

void cook(int guests) {
    Step step("cook");
    if (guests > 4) {
        throw std::runtime_error("the pot is too small");
    }
    std::cout << "plov for " << guests << '\n';
}

void dinner(int guests) {
    Step step("dinner");
    cook(guests);
    std::cout << "dinner is ready\n";
}

int main() {
    try {
        dinner(3);
        dinner(6);
        dinner(2);
    } catch (const std::runtime_error& e) {
        std::cout << "problem: " << e.what() << '\n';
    }
    std::cout << "done\n";
}
