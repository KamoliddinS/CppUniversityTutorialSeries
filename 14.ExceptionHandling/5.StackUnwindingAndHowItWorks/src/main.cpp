#include <iostream>

// A sample resource that needs to be managed
class Resource {
public:
    Resource(const char* name) : name_(name) {
        std::cout << "Resource " << name_ << " acquired.\n";
    }
    ~Resource() {
        std::cout << "Resource " << name_ << " released.\n";
    }
private:
    const char* name_;
};

void functionC() {
    Resource res3("C");
    std::cout << "Throwing an exception in functionC\n";
    throw std::runtime_error("Exception from functionC");
    // Note: res3 destructor will be called due to stack unwinding
}

void functionB() {
    Resource res2("B");
    functionC();
    // Note: res2 destructor will be called due to stack unwinding
}

void functionA() {
    try {
        Resource res1("A");
        functionB();
        // Note: res1 destructor will be called only if no exception is thrown
    } catch (const std::exception& e) {
        std::cout << "Exception caught in functionA: " << e.what() << '\n';
        // Stack unwinding has completed when this block is executed
    }
}

int main() {
    try {
        functionA();
    } catch (...) {
        // This block will not be executed because the exception is
        // already handled in functionA
        std::cout << "Exception caught in main\n";
    }
    return 0;
}
