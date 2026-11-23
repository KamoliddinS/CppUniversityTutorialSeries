// Exercise 2: Fix the build
// This file does not compile yet. Fixing it is the exercise.
#include <iostream>
#include <string>

int main() {
    std::string city = "Bukhara";
    printTicket(city, 2);
    printTicket("Khiva");
}

int ticketPrice(int count) {
    int price = count * 45000;
}

void printTicket(std::string& city, int count = 1) {
    std::cout << "Tickets to " << city << ": " << count << ", price "
              << ticketPrice() << " so'm\n";
}
