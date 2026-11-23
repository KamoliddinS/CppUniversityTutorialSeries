#include <iostream>

class Printer {
public:
    virtual ~Printer() = default;
    virtual void print() const = 0;
};

class Scanner {
public:
    virtual ~Scanner() = default;
    virtual void scan() const = 0;
};

class Copier : public Printer, public Scanner {
public:
    void print() const override { std::cout << "Copier prints\n"; }
    void scan() const override { std::cout << "Copier scans\n"; }
};

class SimplePrinter : public Printer {
public:
    void print() const override { std::cout << "Printer prints\n"; }
};

void scanPage(const Scanner& device) {
    device.scan();
}

int main() {
    Copier copier;
    SimplePrinter printer;
    printer.print();
    scanPage(copier);
}
