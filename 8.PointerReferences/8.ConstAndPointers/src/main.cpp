#include <iostream>

using namespace std;

int main() {
    int x = 10, y = 20;

    // Constant pointer
    int* const p1 = &x;
    *p1 = 15;         // Allowed: Modifying the data pointed by p1
    // p1 = &y;      // Error: Can't change the address p1 is pointing to

    cout << "x after modifying via constant pointer: " << x << endl;  // Outputs 15

    // Pointer to constant data
    const int* p2 = &x;
    // *p2 = 25;     // Error: Can't modify the data pointed by p2
    p2 = &y;         // Allowed: Changing the address p2 is pointing to

    cout << "p2 now points to y with value: " << *p2 << endl;  // Outputs 20

    // Constant pointer to constant data
    const int z = 30;
    const int* const p3 = &z;
    // *p3 = 35;     // Error: Can't modify the data pointed by p3
    // p3 = &x;      // Error: Can't change the address p3 is pointing to

    cout << "p3 points to a constant integer z with value: " << *p3 << endl;  // Outputs 30

    return 0;
}
