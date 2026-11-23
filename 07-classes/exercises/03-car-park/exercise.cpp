// Exercise 3: Car park
// This class counts the cars in a car park. It works as long as nothing goes
// wrong, but it does not protect its data yet. Complete the four TODO parts.
// Do not change main.
#include <iostream>
#include <string>

class CarPark {
public:
    explicit CarPark(int places) : places_(places) {
        // TODO 1: a negative number of places makes no sense. Store 0 instead.
    }

    // A car drives in. When the car park is full: change nothing, return false.
    bool enter() {
        // TODO 2
        ++cars_;
        return true;
    }

    // A car drives out. When the car park is empty: change nothing, return false.
    bool leave() {
        // TODO 3
        --cars_;
        return true;
    }

    // TODO 4: return the number of free places.
    int freePlaces() const { return 0; }

private:
    int places_ = 0;
    int cars_ = 0;      // invariant: 0 <= cars_ && cars_ <= places_
};

int main() {
    int places = 0;
    std::cin >> places;
    CarPark carPark(places);

    std::string command;
    while (std::cin >> command) {
        bool done = false;
        if (command == "in") {
            done = carPark.enter();
        } else if (command == "out") {
            done = carPark.leave();
        }
        if (done) {
            std::cout << command << ": " << carPark.freePlaces() << " free\n";
        } else {
            std::cout << command << ": refused\n";
        }
    }
}
