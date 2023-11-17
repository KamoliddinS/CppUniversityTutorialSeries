#include <iostream>
using namespace std;

int main() {
    const int size=5;
    int arr[size] = {1,2,3,4,5};
    //interate over array without this []
    int *p = arr;

    for ( int i=0; i<size; i++){
        cout << *(p+i) << endl;
    }
    


    return 0;
}


