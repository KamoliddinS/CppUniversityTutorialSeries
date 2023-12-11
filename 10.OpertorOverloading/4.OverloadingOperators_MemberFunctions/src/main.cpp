#include <iostream>

// A simple 'Vector2D' class to demonstrate operator overloading as member functions
class Vector2D {
public:
    float x, y;

    // Default constructor
    Vector2D() : x(0.0f), y(0.0f) {}

    // Constructor to initialize the vector
    Vector2D(float x, float y) : x(x), y(y) {}

    // Overloading the unary '+' operator
    Vector2D operator+() const {
        std::cout << "Unary operator " << std::endl;
        return *this; // Returns a copy of the current object
    }

    // Overloading the binary '+' operator to add two vectors
    Vector2D operator+(const Vector2D& rhs) const {
        std::cout << "Binary operator " << std::endl;
        return Vector2D(x + rhs.x, y + rhs.y);
    }

    // Overloading the '==' operator to compare two vectors
    bool operator==(const Vector2D& rhs) const {
        return (x == rhs.x) && (y == rhs.y);
    }

    // Overloading the '!=' operator to compare two vectors
    bool operator!=(const Vector2D& rhs) const {
        return !(*this == rhs); // Reusing the '==' operator
    }

    // Overloading the assignment '=' operator
    Vector2D& operator=(const Vector2D& rhs) {
        std::cout<<"Assignment operator "<<std::endl;
        if (this != &rhs) { // Check for self-assignment
            x = rhs.x;
            y = rhs.y;
        }
        return *this; // Return a reference to the current object
    }

    // Utility function to print vector components
    void print() const {
        std::cout << "Vector(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Vector2D vec1(10.0f, 20.0f);
    Vector2D vec2(5.0f, 7.0f);

    // Demonstrate unary '+' operator
    Vector2D vec3 = +vec1;
    vec3.print();

    // Demonstrate binary '+' operator
    Vector2D vec4 = vec1 + vec2;
    vec4.print();

    // Demonstrate '==' operator
    std::cout << "vec1 and vec2 are " << (vec1 == vec2 ? "equal" : "not equal") << std::endl;

    // Demonstrate '!=' operator
    std::cout << "vec1 and vec3 are " << (vec1 != vec3 ? "not equal" : "equal") << std::endl;

    // Demonstrate '=' operator
    Vector2D vec5 = vec2; // Using Copy constructor
    vec5.print();

    Vector2D vec6;
    vec6 = vec2; // Using assignment operator
    vec6.print();

    return 0;
}
