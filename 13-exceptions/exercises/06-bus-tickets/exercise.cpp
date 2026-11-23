// Exercise 6: Bus tickets
// The exercise text describes the commands and what to print.
// Write the four TODO parts. The program must go on after every error.
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

// TODO 1: write the class SeatTaken. It derives from std::runtime_error
// and stores the number of the seat. Its member function seat() returns that number.

class Bus {
public:
    explicit Bus(std::size_t seats) : names_(seats) {}

    // Gives the seat to name.
    // TODO 2: throw std::out_of_range("no such seat") when the bus has no seat with this
    // number, and SeatTaken when the seat already has a passenger.
    void book(std::size_t seat, const std::string& name) { names_.at(seat - 1) = name; }

    // TODO 3: return the name of the passenger, or no value when the seat is free.
    // Throw std::out_of_range("no such seat") when the bus has no seat with this number.
    std::optional<std::string> passenger(std::size_t seat) const { return names_.at(seat - 1); }

private:
    std::vector<std::string> names_;    // names_[0] is seat 1; an empty name means "free"
};

int main() {
    Bus bus(4);
    std::string command;
    std::size_t seat = 0;
    while (std::cin >> command >> seat) {
        // TODO 4: answer the commands "book" and "who".
        // Catch the exceptions and print the "error: ..." lines.
    }
}
