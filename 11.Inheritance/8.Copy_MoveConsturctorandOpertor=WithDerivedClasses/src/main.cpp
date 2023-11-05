#include <iostream>
#include <utility> // For std::move
#include <vector>

class Base {
public:
    std::vector<int> data;

    Base() {}

    // Base class copy constructor
    Base(const Base& other) : data(other.data) {
        std::cout << "Base copy constructor called." << std::endl;
    }

    // Base class move constructor
    Base(Base&& other) noexcept : data(std::move(other.data)) {
        std::cout << "Base move constructor called." << std::endl;
    }

    // Base class copy assignment operator
    Base& operator=(const Base& other) {
        if (this != &other) {
            data = other.data;
            std::cout << "Base copy assignment operator called." << std::endl;
        }
        return *this;
    }

    // Base class move assignment operator
    Base& operator=(Base&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
            std::cout << "Base move assignment operator called." << std::endl;
        }
        return *this;
    }

    virtual ~Base() {} // Virtual to allow for clean polymorphic deletion
};

class Derived : public Base {
public:
    std::string name;

    Derived(std::string n) : name(std::move(n)) {}

    // Derived class copy constructor
    Derived(const Derived& other) : Base(other), name(other.name) {
        std::cout << "Derived copy constructor called." << std::endl;
    }

    // Derived class move constructor
    Derived(Derived&& other) noexcept : Base(std::move(other)), name(std::move(other.name)) {
        std::cout << "Derived move constructor called." << std::endl;
    }

    // Derived class copy assignment operator
    Derived& operator=(const Derived& other) {
        if (this != &other) {
            Base::operator=(other); // Call Base class copy assignment operator
            name = other.name;
            std::cout << "Derived copy assignment operator called." << std::endl;
        }
        return *this;
    }

    // Derived class move assignment operator
    Derived& operator=(Derived&& other) noexcept {
        if (this != &other) {
            Base::operator=(std::move(other)); // Call Base class move assignment operator
            name = std::move(other.name);
            std::cout << "Derived move assignment operator called." << std::endl;
        }
        return *this;
    }
};

int main() {
    Derived d1("Original");
    Derived d2 = d1; // Calls copy constructor
    Derived d3("Temporary");
    d3 = std::move(d1); // Calls move assignment operator

    // Output will show which operations were called during execution.
    return 0;
}
