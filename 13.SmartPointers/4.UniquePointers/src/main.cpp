#include <iostream>
#include <memory>  // Include for std::unique_ptr

class Example {
public:
    Example() {
        std::cout << "Example created" << std::endl;
    }
    ~Example() {
        std::cout << "Example destroyed" << std::endl;
    }
    void doWork() {
        std::cout << "Example is working" << std::endl;
    }
};

// Function that uses unique_ptr
void processWithUniquePtr() {
    // Creating a unique_ptr to a new Example
    std::unique_ptr<Example> uniqueEx = std::make_unique<Example>();
    
    // Use -> to call a member function of the underlying object
    uniqueEx->doWork();
    
    // unique_ptr will automatically delete the associated object
    // when it goes out of scope (RAII principle)
}

// Function that tries to copy a unique_ptr (which should fail to compile)
void attemptToCopyUniquePtr(std::unique_ptr<Example> uPtr) {
    // This function body is intentionally empty because it's meant to illustrate
    // that you cannot copy a unique_ptr. If you uncomment the following line,
    // the code will fail to compile:
    
    // std::unique_ptr<Example> anotherUPtr = uPtr;  // This will cause a compile-time error.
}

// Function that transfers ownership with std::move
std::unique_ptr<Example> transferOwnership(std::unique_ptr<Example> uPtr) {
    // Ownership of the resource is transferred out of the function with std::move
    return std::move(uPtr);
}

int main() {
    // Demonstrate the automatic destruction of the managed object
    processWithUniquePtr();
    
    // Transfer ownership to a new unique_ptr
    std::unique_ptr<Example> mainUniquePtr = std::make_unique<Example>();
    std::unique_ptr<Example> receivedPtr = transferOwnership(std::move(mainUniquePtr));
    // At this point, mainUniquePtr is nullptr, and receivedPtr owns the resource
    
    // receivedPtr will be destroyed at the end of main, releasing its resource
    
    return 0;
}
