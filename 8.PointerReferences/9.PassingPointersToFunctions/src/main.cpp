#include <iostream>

using namespace std;

// A function that modifies the integer value pointed by the pointer
void modifyValue(int* p) {
    *p *= 2;  // Double the value of what p is pointing to
}

// A function that modifies the values of an array using a pointer
void modifyArray(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        *(arr + i) += 10;  // Add 10 to each element in the array
    }
}


// void display( const vector<string> *const  v) {
// //(*v).at(0) = "Funny";
//     for (auto str: *v)
//         cout << str << " ";
//     cout << endl;
  
//  //   v = nullptr;
// }

// void display(int *array, int sentinel) {
//     while (*array != sentinel)
//         cout << *array++ << " ";
//     cout << endl;
// }
// A function that returns a pointer
int* getLarger(int* a, int* b) {
    return (*a > *b) ? a : b;  // Return the pointer to the larger integer
}

int main() {
    int x = 5;
    modifyValue(&x);
    cout << "Modified x: " << x << endl;  // Outputs 10 (5*2)

    int arr[3] = {1, 2, 3};
    modifyArray(arr, 3);
    cout << "Modified array: ";
    for(int i = 0; i < 3; i++) {
        cout << arr[i] << " ";  // Outputs 11 12 13
    }
    cout << endl;
    //    cout << "-----------------------------" << endl;
    //    vector<string> stooges {"Larry", "Moe", "Curly"};
    //    display(&stooges);
    int a = 7, b = 8;
    int* largerValuePtr = getLarger(&a, &b);
    cout << "Larger value is: " << *largerValuePtr << endl;  // Outputs 8

    return 0;
}
