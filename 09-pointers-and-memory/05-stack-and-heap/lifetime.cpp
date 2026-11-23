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

Reporter* make() {
    Reporter local("stack object");
    return new Reporter("heap object");
}   // local is destroyed here; the heap object lives on

int main() {
    Reporter* p = make();
    std::cout << "back in main\n";
    delete p;               // the heap object is destroyed here
    std::cout << "end of main\n";
}
