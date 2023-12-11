
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2D {
public:
    float x, y;

    Vector2D(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    //  I am overloading << operator
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

#endif // VECTOR2D_H
