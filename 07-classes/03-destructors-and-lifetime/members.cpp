#include <iostream>
#include <string>

class Reporter {
public:
    explicit Reporter(const std::string& name) : name_(name) {
        std::cout << "create " << name_ << '\n';
    }

    ~Reporter() {
        std::cout << "destroy " << name_ << '\n';
    }

private:
    std::string name_;
};

class Car {
public:
    Car() : engine_("engine"), radio_("radio") {
        std::cout << "create car\n";
    }

    ~Car() {
        std::cout << "destroy car\n";
    }

private:
    Reporter engine_;
    Reporter radio_;
};

int main() {
    Car car;
    std::cout << "driving\n";
}
