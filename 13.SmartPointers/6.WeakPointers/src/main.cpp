#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructed.\n"; }
    ~MyClass() { std::cout << "MyClass destroyed.\n"; }

    // Function to add a weak_ptr as a member variable to illustrate a potential use case
    void setWeakPtr(std::weak_ptr<MyClass> wp) {
        weakPtr_ = wp;
    }

    // Function to check if the weak_ptr still points to a valid object
    void checkWeakPtr() {
        if (auto sp = weakPtr_.lock()) {
            std::cout << "Object is still alive!\n";
        } else {
            std::cout << "Object is no longer alive.\n";
        }
    }

private:
    std::weak_ptr<MyClass> weakPtr_;
};

int main() {
    // Create a shared_ptr
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();

    // Create a weak_ptr from shared_ptr
    std::weak_ptr<MyClass> weakPtr = sharedPtr;

    // Lock the weak_ptr to create a temporary shared_ptr
    if (auto tempSharedPtr = weakPtr.lock()) {
        std::cout << "Managed object is still alive.\n";
        tempSharedPtr->setWeakPtr(weakPtr); // Pass the weak pointer to the object itself
    } else {
        std::cout << "Managed object has been destroyed.\n";
    }

    // The temporary shared_ptr goes out of scope and the use count remains 1

    // Reset the original shared_ptr to see the effect on weakPtr
    sharedPtr.reset();

    // The MyClass instance will be destroyed at this point
    // because the last shared_ptr to it was reset

    // Try to lock the weak_ptr again to check if the object is still there
    if (auto tempSharedPtr = weakPtr.lock()) {
        std::cout << "Managed object is still alive.\n";
    } else {
        std::cout << "Managed object has been destroyed.\n";
    }

    return 0;
}

// Output:
// MyClass constructed.
// Managed object is still alive.
// MyClass destroyed.
// Managed object has been destroyed.
