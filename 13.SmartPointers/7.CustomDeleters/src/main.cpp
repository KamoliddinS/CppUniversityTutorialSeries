#include <iostream>
#include <memory>

// A simple class to demonstrate clean-up
class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

// Custom deleter function
void customDeleter(Resource* r) {
    std::cout << "Custom deleter called\n";
    delete r;  // Perform the actual deletion
}

// Custom deleter functor
struct FunctorDeleter {
    void operator()(Resource* r) const {
        std::cout << "FunctorDeleter called\n";
        delete r;  // Perform the actual deletion
    }
};

int main() {
    // Using custom deleter with std::unique_ptr
    {
        std::unique_ptr<Resource, decltype(&customDeleter)> uniqueWithCustomDeleter(new Resource(), customDeleter);
        // Resource will be automatically deleted using customDeleter when going out of scope
    }

    std::cout << "uniqueWithCustomDeleter out of scope\n";

    // Using custom deleter functor with std::unique_ptr
    {
        std::unique_ptr<Resource, FunctorDeleter> uniqueWithFunctorDeleter(new Resource());
        // Resource will be automatically deleted using FunctorDeleter when going out of scope
    }

    std::cout << "uniqueWithFunctorDeleter out of scope\n";

    // Using custom deleter with std::shared_ptr
    {
        std::shared_ptr<Resource> sharedWithCustomDeleter(new Resource(), customDeleter);
        // Resource will be automatically deleted using customDeleter when the last shared_ptr is destroyed
    }

    std::cout << "sharedWithCustomDeleter out of scope\n";

    // Using lambda expression as a custom deleter with std::shared_ptr
    {
        auto lambdaDeleter = [](Resource* r) {
            std::cout << "Lambda deleter called\n";
            delete r;  // Perform the actual deletion
        };
        std::shared_ptr<Resource> sharedWithLambdaDeleter(new Resource(), lambdaDeleter);
        // Resource will be automatically deleted using lambda deleter when the last shared_ptr is destroyed
    }

    std::cout << "sharedWithLambdaDeleter out of scope\n";

    // The program will exit and the destructors for shared_ptr will be called automatically.
    return 0;
}

/* Output:
Resource acquired
Custom deleter called
Resource destroyed
uniqueWithCustomDeleter out of scope
Resource acquired
FunctorDeleter called
Resource destroyed
uniqueWithFunctorDeleter out of scope
Resource acquired
Custom deleter called
Resource destroyed
sharedWithCustomDeleter out of scope
Resource acquired
Lambda deleter called
Resource destroyed
sharedWithLambdaDeleter out of scope
*/
