#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource acquired.\n"; }
    ~Resource() { std::cout << "Resource destroyed.\n"; }
    void sayHello() { std::cout << "Hello!\n"; }
};

void shareTheResource(std::shared_ptr<Resource> sharedPtr) {
    std::cout << "Shared count inside function: " << sharedPtr.use_count() << "\n";
    // The resource is shared with the calling function
}

int main() {
    std::shared_ptr<Resource> sharedPtr = std::make_shared<Resource>();
    std::cout << "Shared count before function call: " << sharedPtr.use_count() << "\n";
    shareTheResource(sharedPtr);
    std::cout << "Shared count after function call: " << sharedPtr.use_count() << "\n";
    // Resource is automatically released when the last shared_ptr (sharedPtr) goes out of scope
    return 0;
}
