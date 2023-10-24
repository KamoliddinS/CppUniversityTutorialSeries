#include <iostream>
#include <utility> // For std::move

using namespace std;

int main() {
    // L-VALUE
    int x = 10; // 'x' is an l-value
    int &lref = x; // An l-value reference binding to an l-value

    cout << "x: " << x << ", lref: " << lref << endl;
    
    // Uncommenting the line below will result in a compiler error
    // because 20 is an r-value and cannot bind to an l-value reference
    // int &errorRef = 20;
    
    // R-VALUE
    int &&rref = 10 + 5; // r-value reference binding to an r-value (result of 10 + 5)
    cout << "rref: " << rref << endl;

    // MOVE SEMANTICS using r-value references
    string str1 = "hello";
    cout << "Before move, str1: " << str1 << endl;

    // 'std::move' casts str1 to an r-value, enabling efficient resource transfer
    string str2 = std::move(str1); 

    cout << "After move, str1: " << str1 << ", str2: " << str2 << endl;

    // FUNCTIONS & L-VALUE, R-VALUE
    int y = 50;
    int &yRef = y; // l-value reference
    int &&yRValRef = 30 + 20; // r-value reference

    // Uncommenting the lines below will result in compiler errors
    // yRValRef = y;   // You cannot assign an l-value to an r-value reference
    // yRef = 10 + 5; // You cannot assign an r-value to an l-value reference directly

    return 0;
}

