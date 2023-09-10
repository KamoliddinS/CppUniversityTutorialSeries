// main.cpp
#include <iostream>
#include <limits>

int main() {
    // Integer Types
    int myInt = 2147483647;
    short myShort = 32767;
    long myLong = 2147483647L;
    long long myLongLong = 9223372036854775807LL;
    unsigned int myUnsignedInt = 4294967295;

    std::cout << "Integer Types:" << std::endl;
    std::cout << "int: " << myInt << std::endl;
    std::cout << "short: " << myShort << std::endl;
    std::cout << "long: " << myLong << std::endl;
    std::cout << "long long: " << myLongLong << std::endl;
    std::cout << "unsigned int: " << myUnsignedInt << std::endl;

    // Floating-Point Types
    float myFloat = 3.14159f;
    double myDouble = 3.141592653589793;
    long double myLongDouble = 3.141592653589793238L;

    std::cout << "\nFloating-Point Types:" << std::endl;
    std::cout << "float: " << myFloat << std::endl;
    std::cout << "double: " << myDouble << std::endl;
    std::cout << "long double: " << myLongDouble << std::endl;

    // Character Types
    char myChar = 'A';
    unsigned char myUnsignedChar = 255;
    wchar_t myWideChar = L'Z';

    std::cout << "\nCharacter Types:" << std::endl;
    std::cout << "char: " << myChar << std::endl;
    std::cout << "unsigned char: " << static_cast<int>(myUnsignedChar) << std::endl;  // Casting to int for display
    std::wcout << L"wchar_t: " << myWideChar << std::endl;

    // Boolean Type
    bool myBool = true;

    std::cout << "\nBoolean Type:" << std::endl;
    std::cout << "bool: " << std::boolalpha << myBool << std::endl;  // boolalpha to print true/false instead of 1/0

    return 0;
}
