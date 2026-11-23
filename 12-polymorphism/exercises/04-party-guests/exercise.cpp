// Exercise 4: Party guests
// Every guest says hello in their own way, and leaves when the party is over.
// The program builds without a warning, but its output is wrong. Change two lines.
#include <iostream>
#include <memory>
#include <string>

class Guest {
public:
    explicit Guest(const std::string& name) : name_(name) {}
    ~Guest() { std::cout << name_ << " leaves\n"; }
    virtual std::string hello() const { return "Hello"; }
    const std::string& name() const { return name_; }

private:
    std::string name_;
};

class Musician : public Guest {
public:
    explicit Musician(const std::string& name) : Guest(name) {}
    ~Musician() { std::cout << name() << " packs the dutar\n"; }
    std::string hello() const override { return "Salom"; }
};

void greet(Guest guest) {
    std::cout << guest.name() << " says " << guest.hello() << '\n';
}

int main() {
    std::unique_ptr<Guest> first = std::make_unique<Guest>("Aziz");
    std::unique_ptr<Guest> second = std::make_unique<Musician>("Malika");

    greet(*first);
    greet(*second);
    std::cout << "The party is over\n";
}
