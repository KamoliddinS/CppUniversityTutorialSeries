#include <iostream>

// Breaks interface segregation: one big interface. Every device must have
// print() AND scan(), even a device that cannot scan.
class Device {
public:
    virtual ~Device() = default;
    virtual void print() const = 0;
    virtual void scan() const = 0;
};

class Copier : public Device {
public:
    void print() const override { std::cout << "Copier prints\n"; }
    void scan() const override { std::cout << "Copier scans\n"; }
};

class SimplePrinter : public Device {
public:
    void print() const override { std::cout << "Printer prints\n"; }
    void scan() const override {}   // forced to exist: does nothing
};

void scanPage(const Device& device) {
    device.scan();
}

int main() {
    Copier copier;
    SimplePrinter printer;
    printer.print();
    scanPage(copier);
    scanPage(printer);   // builds and runs, but nothing is scanned
}
