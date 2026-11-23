// Exercise 1: Predict the output
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>
#include <string>

class Lamp {
public:
    explicit Lamp(const std::string& room) : room_(room) {
        ++count_;
        std::cout << room_ << " on\n";
    }

    ~Lamp() {
        --count_;
        std::cout << room_ << " off\n";
    }

    static int count() { return count_; }

private:
    inline static int count_ = 0;
    std::string room_;
};

int main() {
    Lamp hall("hall");
    {
        Lamp kitchen("kitchen");
        Lamp bedroom("bedroom");
        std::cout << Lamp::count() << " lamps on\n";
    }
    Lamp garden("garden");
    std::cout << Lamp::count() << " lamps on\n";
}
