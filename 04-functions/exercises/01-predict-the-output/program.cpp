// Exercise 1: Predict the output
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>

int twice(int number) {
    number = number * 2;
    return number;
}

void addTen(int& number) {
    number = number + 10;
}

void show(int number = 0) {
    std::cout << "value: " << number << '\n';
}

int main() {
    int a = 5;
    int b = twice(a);
    show(a);
    show(b);

    addTen(a);
    show(a);
    show(twice(a) + 1);
    show();
}
