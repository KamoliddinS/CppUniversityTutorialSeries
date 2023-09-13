#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n = 35;  // Adjust this value for longer/shorter computation times
    cout << fibonacci(n) << endl;
    return 0;
}