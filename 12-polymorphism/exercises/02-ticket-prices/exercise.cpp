// Exercise 2: Ticket prices
// A museum sells three kinds of ticket. The program builds, but two lines of its
// output are wrong. Find the two mistakes in the derived classes and fix them.
#include <iostream>
#include <string>

class Ticket {
public:
    virtual ~Ticket() = default;
    virtual std::string kind() const { return "Full"; }
    virtual int price() const { return 20000; }   // so'm
};

class StudentTicket : public Ticket {
public:
    std::string kind() const { return "Student"; }
    int price() { return 10000; }
};

class ChildTicket : public Ticket {
public:
    std::string Kind() const { return "Child"; }
    int price() const { return 5000; }
};

void printTicket(const Ticket& ticket) {
    std::cout << ticket.kind() << " ticket: " << ticket.price() << " so'm\n";
}

int main() {
    Ticket full;
    StudentTicket student;
    ChildTicket child;

    printTicket(full);
    printTicket(student);
    printTicket(child);
}
