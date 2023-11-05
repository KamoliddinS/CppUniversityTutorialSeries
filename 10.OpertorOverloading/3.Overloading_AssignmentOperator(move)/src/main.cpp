#include <iostream>
#include <utility> // for std::move

// A simple Widget class that has a move assignment operator.
class Widget {
public:
    // Constructor that allocates resources.
    Widget(int size) : size_(size), data_(new int[size]) {
        std::cout << "Widget created with size " << size_ << std::endl;
    }

    // Destructor to free resources.
    ~Widget() {
        delete[] data_;
        std::cout << "Widget destroyed." << std::endl;
    }

    // Move constructor
    Widget(Widget&& other) noexcept : data_(other.data_), size_(other.size_) {
        other.data_ = nullptr;
        other.size_ = 0;
        std::cout << "Widget moved via move constructor." << std::endl;
    }

    // Move assignment operator
    Widget& operator=(Widget&& other) noexcept {
        std::cout << "Widget moved via move assignment operator." << std::endl;
        if (this != &other) { // Guard against self-assignment
            // Release any existing resources
            delete[] data_;

            // Transfer ownership of resources
            data_ = other.data_;
            size_ = other.size_;

            // Leave the source in a state safe to destroy
            other.data_ = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    // Utility function to print the contents of the Widget
    void print() const {
        if (data_) {
            std::cout << "Widget data address: " << data_ << std::endl;
        } else {
            std::cout << "Widget is empty (resources moved out)." << std::endl;
        }
    }

private:
    int* data_;
    int size_;
};

int main() {
    Widget widgetA(10); // Normal constructor
    Widget widgetB(5); // Normal constructor

    std::cout << "Before move assignment:" << std::endl;
    widgetA.print();
    widgetB.print();

    // Move assignment - resources are moved from widgetB to widgetA
    widgetA = std::move(widgetB);

    std::cout << "After move assignment:" << std::endl;
    widgetA.print();
    widgetB.print(); // widgetB is now in a moved-from state

    return 0;
}
