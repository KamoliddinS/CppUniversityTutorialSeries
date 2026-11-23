#include <iostream>
#include <stdexcept>
#include <string>

class Reporter {
public:
    explicit Reporter(const std::string& name) : name_(name) {
        std::cout << "create " << name_ << '\n';
    }
    ~Reporter() { std::cout << "destroy " << name_ << '\n'; }

private:
    std::string name_;
};

void inner() {
    Reporter c("c");
    throw std::runtime_error("inner failed");
}

void middle() {
    Reporter b("b");
    try {
        inner();
    } catch (const std::runtime_error& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
    std::cout << "middle goes on\n";
}

void outer() {
    Reporter a("a");
    middle();
    std::cout << "outer goes on\n";
}

int main() {
    outer();
}
