// Exercise 1: Predict the order
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>

class Engine {
public:
    Engine() { std::cout << "Engine on\n"; }
    ~Engine() { std::cout << "Engine off\n"; }
};

class Vehicle {
public:
    Vehicle() { std::cout << "Vehicle ready\n"; }
    ~Vehicle() { std::cout << "Vehicle gone\n"; }
};

class Bus : public Vehicle {
public:
    Bus() { std::cout << "Bus ready\n"; }
    ~Bus() { std::cout << "Bus gone\n"; }

private:
    Engine engine_;
};

int main() {
    Bus bus;
    std::cout << "Next stop: Chorsu\n";
}
