#include <iostream>

using namespace std;

// Function to modify the value using reference
void modifyValue(int &ref) {
    // Changing the value of 'ref' will change the value of the variable it references
    ref = 20;
}

// Function to swap two values using references
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int y = 15;

    // Declaring a reference to x
    int &ref = x;

    cout << "Initial value of x: " << x << endl;  // Expected: 10

    // Modifying x through the reference
    ref = 12;
    cout << "Value of x after modifying through reference: " << x << endl;  // Expected: 12

    // Using function to modify x
    modifyValue(x);
    cout << "Value of x after calling modifyValue: " << x << endl;  // Expected: 20

    cout << "Values before swapping - x: " << x << ", y: " << y << endl;  // Expected: x: 20, y: 15

    // Using function to swap x and y
    swap(x, y);
    cout << "Values after swapping - x: " << x << ", y: " << y << endl;  // Expected: x: 15, y: 20

    return 0;
}
