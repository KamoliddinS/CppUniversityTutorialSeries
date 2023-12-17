#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource acquired.\n"; }
    ~Resource() { std::cout << "Resource destroyed.\n"; }
    void sayHello() { std::cout << "Hello!\n"; }
};

void useUniquePointer() {
    std::unique_ptr<Resource> uniquePtr = std::make_unique<Resource>();
    uniquePtr->sayHello();
    
    // Resource is automatically released when uniquePtr goes out of scope
}

int main() {
    std::cout << "Creating uniquePtr\n";
    useUniquePointer();
    std::cout << "uniquePtr is out of scope and destroyed\n";
    return 0;
}
