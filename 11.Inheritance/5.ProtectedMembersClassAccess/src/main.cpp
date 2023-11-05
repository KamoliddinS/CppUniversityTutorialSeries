#include <iostream>

// Base class with protected member
class Base {
protected:
    int protectedValue;

public:
    Base() : protectedValue(0) {}

    void setProtectedValue(int value) {
        protectedValue = value;
    }

    int getProtectedValue() const {
        return protectedValue;
    }
};

// Derived class with public inheritance
class PublicDerived : public Base {
public:
    void display() {
        // Accessing protected member from the base class
        std::cout << "Protected Value (PublicDerived): " << protectedValue << std::endl;
    }
};

// Derived class with protected inheritance
class ProtectedDerived : protected Base {
public:
    void display() {
        // Accessing protected member from the base class
        std::cout << "Protected Value (ProtectedDerived): " << protectedValue << std::endl;
    }
};

// Derived class with private inheritance
class PrivateDerived : private Base {
public:
    void display() {
        // Accessing protected member from the base class
        std::cout << "Protected Value (PrivateDerived): " << protectedValue << std::endl;
    }
};

int main() {
    PublicDerived pubDerived;
    ProtectedDerived protDerived;
    PrivateDerived privDerived;

    // Setting protectedValue through a public method of the base class
    pubDerived.setProtectedValue(10);
    protDerived.setProtectedValue(20);
    privDerived.setProtectedValue(30);

    // Displaying protectedValue through a method of the derived class
    pubDerived.display();  // Output: Protected Value (PublicDerived): 10
    protDerived.display(); // Output: Protected Value (ProtectedDerived): 20
    privDerived.display(); // Output: Protected Value (PrivateDerived): 30

    // Direct access to protectedValue is not possible from outside the class hierarchy
    // std::cout << pubDerived.protectedValue; // Error: 'int Base::protectedValue' is protected within this context
    // std::cout << protDerived.protectedValue; // Error: 'int Base::protectedValue' is inaccessible
    // std::cout << privDerived.protectedValue; // Error: 'int Base::protectedValue' is inaccessible

    // Access to protectedValue through public methods of Base is possible for PublicDerived
    std::cout << "Protected Value via Getter (PublicDerived): " << pubDerived.getProtectedValue() << std::endl;
    // For ProtectedDerived and PrivateDerived, this is not possible without additional methods exposing it

    return 0;
}
