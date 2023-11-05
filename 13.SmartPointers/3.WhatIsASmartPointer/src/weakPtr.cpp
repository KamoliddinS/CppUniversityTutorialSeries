#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource acquired.\n"; }
    ~Resource() { std::cout << "Resource destroyed.\n"; }
};

int main() {
    std::shared_ptr<Resource> sharedPtr = std::make_shared<Resource>();
    std::weak_ptr<Resource> weakPtr(sharedPtr);

    std::cout << "Shared count with weakPtr: " << sharedPtr.use_count() << "\n";
    // The resource is still managed by sharedPtr, weakPtr doesn't increase the count

    if (auto lockedSharedPtr = weakPtr.lock()) { // Convert weak_ptr to shared_ptr to use it
        std::cout << "Resource is still alive and shared count is " << sharedPtr.use_count() << "\n";
    } else {
        std::cout << "Resource is no longer available.\n";
    }
    // After the if scope, lockedSharedPtr goes out of scope, does not affect sharedPtr

    sharedPtr.reset(); // Manually release the resource

    if (weakPtr.expired()) {
        std::cout << "Resource has been released and weakPtr is expired.\n";
    }
    
    return 0;
}
