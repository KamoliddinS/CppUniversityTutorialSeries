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

void send(bool online) {
    Reporter* message = new Reporter("message");
    if (!online) {
        throw std::runtime_error("no connection");      // leaves before the delete
    }
    std::cout << "sending\n";
    delete message;
}

int main() {
    try {
        send(false);
    } catch (const std::runtime_error& e) {
        std::cout << "caught: " << e.what() << '\n';
    }
}
