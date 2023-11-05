// Filename: FinalSpecifierDemo.cpp
// Compile with: g++ FinalSpecifierDemo.cpp -o FinalSpecifierDemo

#include <iostream>
#include <memory>

// Base class
class Base {
public:
    virtual void introduce() const {
        std::cout << "Hello, I am a Base class." << std::endl;
    }

    // Virtual destructor is good practice for base classes intended for polymorphic use
    virtual ~Base() {
        std::cout << "Destroying a Base object." << std::endl;
    }
};

// Derived class that overrides the introduce function and marks it as final
class Derived final : public Base {
public:
    void introduce() const override {
        std::cout << "Hello, I am a Derived class and you cannot derive from me." << std::endl;
    }

    ~Derived() {
        std::cout << "Destroying a Derived object." << std::endl;
    }
};

/*
// This code will cause a compilation error because Derived is marked as final
class FurtherDerived : public Derived {
public:
    void introduce() const override {
        std::cout << "Hello, I am a FurtherDerived class." << std::endl;
    }
};
*/

int main() {
    std::unique_ptr<Base> myBase = std::make_unique<Derived>();
    myBase->introduce(); // Polymorphic call to the Derived class' introduce method

    // No need to manually delete the object since we are using smart pointers
    return 0;
}
