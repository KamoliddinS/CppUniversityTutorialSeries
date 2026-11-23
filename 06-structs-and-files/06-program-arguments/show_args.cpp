#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "argc is " << argc << '\n';
    for (int i = 1; i < argc; ++i) {
        std::cout << "argv[" << i << "] is " << argv[i] << '\n';
    }
}
