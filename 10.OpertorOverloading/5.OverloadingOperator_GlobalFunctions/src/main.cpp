#include <iostream>

class Point {
private:
    int x, y;

public:
    // Constructor
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Accessor methods for x and y
    int getX() const { return x; }
    int getY() const { return y; }

    // Friend declarations for global operator functions
    friend Point operator+(const Point& lhs, const Point& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

// Global operator function to overload the '+' operator for Point objects
Point operator+(const Point& lhs, const Point& rhs) {
    // Create a new Point that is the sum of lhs and rhs
    return Point(lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY());
}

// Global operator function to overload the '<<' operator for Point objects
std::ostream& operator<<(std::ostream& os, const Point& p) {
    // Write the Point to the output stream
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point p1(1, 2), p2(3, 4);

    // Use the overloaded '+' operator
    Point sum = p1 + p2;

    // Use the overloaded '<<' operator to print the Point
    std::cout << "The sum of " << p1 << " and " << p2 << " is " << sum << std::endl;

    return 0;
}
