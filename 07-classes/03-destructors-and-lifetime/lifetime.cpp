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

int main() {
    Reporter a("a");
    Reporter b("b");
    {
        Reporter c("c");
        std::cout << "end of inner block\n";
    }
    std::cout << "end of main\n";
}
