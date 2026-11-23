// Exercise 5: Bounded queue
// This file does not compile yet: Queue and moveAll are missing.
// Write them where the TODO lines are. Do not change main.
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// TODO: write the class template Queue here.

// TODO: write the function template moveAll here.

int main() {
    Queue<std::string> line(4);
    line.push("Aziz");
    line.push("Malika");
    line.push("Jasur");
    line.push("Nodira");
    std::cout << line.front() << " is first of " << line.size() << '\n';

    try {
        line.push("Laziz");
    } catch (const std::length_error&) {
        std::cout << "The line is full.\n";
    }

    Queue<std::string> taxi(3);
    std::cout << moveAll(line, taxi) << " moved\n";
    std::cout << line.front() << " still waits\n";

    Queue<std::string> bus(40);
    std::cout << moveAll(line, bus) << " moved\n";

    try {
        line.pop();
    } catch (const std::out_of_range&) {
        std::cout << "Nobody to remove.\n";
    }
    try {
        std::cout << line.front() << '\n';
    } catch (const std::out_of_range&) {
        std::cout << "Nobody in front.\n";
    }

    Queue<int> tickets(2);
    tickets.push(17);
    tickets.push(18);
    tickets.pop();
    std::cout << tickets.front() << ' ' << tickets.size() << '\n';
}
