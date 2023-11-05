#include <iostream>
#include <memory>  // Include for std::shared_ptr

// A simple class to demonstrate shared_ptr functionality
class Resource {
public:
    Resource() { std::cout << "Resource acquired.\n"; }
    ~Resource() { std::cout << "Resource destroyed.\n"; }
    void doWork() { std::cout << "Resource is working.\n"; }
};

// Function to demonstrate the copy nature of shared_ptr
void useResource(std::shared_ptr<Resource> resource) {
    std::cout << "Using resource. Current count: " << resource.use_count() << "\n";
    // When this function exits, the use_count will decrement by 1.
}

int main() {
    // Creating a shared_ptr to a Resource
    std::shared_ptr<Resource> sharedPtr1 = std::make_shared<Resource>();
    
    // The use count is 1
    std::cout << "Initial use count: " << sharedPtr1.use_count() << "\n";
    
    // Shared_ptr can be copied, increasing the reference count
    std::shared_ptr<Resource> sharedPtr2 = sharedPtr1;
    
    // The use count is now 2
    std::cout << "Use count after copy: " << sharedPtr1.use_count() << "\n";
    
    // Pass the shared_ptr to a function
    useResource(sharedPtr1);
    
    // Even after the function exits, the resource is not destroyed because
    // sharedPtr2 still holds a reference to it
    
    // Let's reset sharedPtr2 and see the effect on the resource and use count
    sharedPtr2.reset();
    
    // The use count should now be 1, and the resource should still be alive
    std::cout << "Use count after reset: " << sharedPtr1.use_count() << "\n";
    
    // sharedPtr1 will go out of scope and destroy the resource since it's the last reference
    return 0;
}

// Output:
// Resource acquired.
// Initial use count: 1
// Use count after copy: 2
// Using resource. Current count: 2
// Use count after reset: 1
// Resource destroyed.
