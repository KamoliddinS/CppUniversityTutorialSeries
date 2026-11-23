// Exercise 1: Predict the output
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>

class Greeter {
public:
    virtual ~Greeter() = default;
    void language() const { std::cout << "English\n"; }
    virtual void greet() const { std::cout << "Hello\n"; }
};

class UzbekGreeter : public Greeter {
public:
    void language() const { std::cout << "Uzbek\n"; }
    void greet() const override { std::cout << "Salom\n"; }
};

void byReference(const Greeter& greeter) {
    greeter.greet();
}

void byValue(Greeter greeter) {
    greeter.greet();
}

int main() {
    UzbekGreeter uzbek;
    const Greeter* pointer = &uzbek;

    uzbek.language();
    pointer->language();
    pointer->greet();
    byReference(uzbek);
    byValue(uzbek);
}
