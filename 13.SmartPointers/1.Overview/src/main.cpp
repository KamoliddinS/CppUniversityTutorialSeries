#include <iostream>
#include <memory>

// A simple class to demonstrate smart pointers.
class Sample {
public:
    Sample() { std::cout << "Sample Created" << std::endl; }
    ~Sample() { std::cout << "Sample Destroyed" << std::endl; }
    void do_something() { std::cout << "Doing something" << std::endl; }
};

// Function to demonstrate unique_ptr
void unique_ptr_demo() {
    // Creating a unique_ptr through std::make_unique (since C++14)
    std::unique_ptr<Sample> uniqueSamplePtr = std::make_unique<Sample>();

    // Use the pointer
    uniqueSamplePtr->do_something();

    // unique_ptr automatically releases the memory when it goes out of scope
}

// Function to demonstrate shared_ptr
void shared_ptr_demo() {
    // Creating a shared_ptr
    std::shared_ptr<Sample> sharedSamplePtr1 = std::make_shared<Sample>();

    {
        // Creating another shared_ptr sharing ownership of the same object
        std::shared_ptr<Sample> sharedSamplePtr2 = sharedSamplePtr1;
        sharedSamplePtr2->do_something();

        // The object is not destroyed here as sharedSamplePtr1 still owns it
    }

    // The object will be destroyed when the last shared_ptr to it is out of scope
}

// Function to demonstrate weak_ptr
void weak_ptr_demo() {
    // Create a shared_ptr
    std::shared_ptr<Sample> sharedSamplePtr = std::make_shared<Sample>();

    // Create a weak_ptr from a shared_ptr
    std::weak_ptr<Sample> weakSamplePtr = sharedSamplePtr;

    // Use lock() to create a shared_ptr from weak_ptr when you need to access the object
    if (auto tempSharedPtr = weakSamplePtr.lock()) {
        tempSharedPtr->do_something();
        // The object is still owned by sharedSamplePtr and will not be destroyed
    } else {
        std::cout << "The object is no longer available." << std::endl;
    }

    // The object will be destroyed when sharedSamplePtr goes out of scope
}

int main() {
    std::cout << "Unique Pointer Demo:" << std::endl;
    unique_ptr_demo();
    std::cout << std::endl;

    std::cout << "Shared Pointer Demo:" << std::endl;
    shared_ptr_demo();
    std::cout << std::endl;

    std::cout << "Weak Pointer Demo:" << std::endl;
    weak_ptr_demo();

    return 0;
}
