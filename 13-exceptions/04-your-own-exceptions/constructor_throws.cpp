#include <iostream>
#include <stdexcept>

class Engine {
public:
    Engine() { std::cout << "Engine built\n"; }
    ~Engine() { std::cout << "Engine destroyed\n"; }
};

class Car {
public:
    explicit Car(int seats) {
        if (seats < 1) {
            throw std::invalid_argument("a car needs a seat");
        }
        std::cout << "Car built\n";
    }
    ~Car() { std::cout << "Car destroyed\n"; }

private:
    Engine engine_;
};

int main() {
    try {
        Car car(0);
        std::cout << "driving\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
}
