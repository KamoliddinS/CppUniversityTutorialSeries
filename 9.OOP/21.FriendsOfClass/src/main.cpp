#include <iostream>

// Forward declaration is needed for the friend declaration in 'Box'
class BoxPrinter;

class Box {
    double width;
    double length;
    double height;

public:
    // Constructor
    Box(double w, double l, double h) : width(w), length(l), height(h) {}

    // Friend function declaration
    friend void printBoxInfo(const Box& box);

    // Friend class declaration
    friend class BoxPrinter;
};

// Friend function definition
void printBoxInfo(const Box& box) {
    std::cout << "Box dimensions are (width x length x height): "
              << box.width << " x " << box.length << " x " << box.height << std::endl;
}

// A friend class
class BoxPrinter {
public:
    // This function can access private members of Box
    static void printVolume(const Box& box) {
        double volume = box.width * box.length * box.height;
        std::cout << "Volume of box: " << volume << std::endl;
    }
};

int main() {
    Box myBox(10.5, 6.0, 3.5);
    
    // Using friend function to print box info
    printBoxInfo(myBox);

    // Using friend class to print box volume
    BoxPrinter::printVolume(myBox);

    return 0;
}
