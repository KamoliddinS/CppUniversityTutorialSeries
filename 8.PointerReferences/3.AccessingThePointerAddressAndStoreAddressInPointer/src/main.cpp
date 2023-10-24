#include <iostream>

using namespace std;

int main() {
    // Pointer Basics
    cout << "---- Pointer Basics ----" << endl;
    int value = 100;
    int* valuePtr;
    cout << "Initial value of valuePtr (uninitialized): " << valuePtr << endl; // This may print some garbage value

    // Storing an Address in a Pointer
    cout << "\n---- Storing an Address in a Pointer ----" << endl;
    valuePtr = &value;
    cout << "Address of 'value' variable: " << &value << endl;
    cout << "Value stored inside 'valuePtr': " << valuePtr << endl;

    // Accessing the Address of a Pointer
    cout << "\n---- Accessing the Address of a Pointer ----" << endl;
    cout << "Address of 'valuePtr' itself: " << &valuePtr << endl;

    // Key Takeaways
    cout << "\n---- Key Takeaways ----" << endl;
    cout << "1. The address of 'value' is: " << &value << endl;
    cout << "2. The value stored inside 'valuePtr' (which points to 'value') is: " << valuePtr << endl;
    cout << "3. The address of the pointer 'valuePtr' itself is: " << &valuePtr << endl;

    return 0;
}
