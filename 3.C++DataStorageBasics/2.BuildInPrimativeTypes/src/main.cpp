// main.cpp
#include <iostream>
#include <limits>

using namespace std;
int main() {
    // // Integer Types
    // int myInt = 2147483647;
    // short myShort = 32767;
    // long myLong = 2147483647L;
    // long long myLongLong = 9223372036854775807LL;
    // unsigned int myUnsignedInt = 4294967295;

    // std::cout << "Integer Types:" << std::endl;
    // std::cout << "int: " << myInt << std::endl;
    // std::cout << "short: " << myShort << std::endl;
    // std::cout << "long: " << myLong << std::endl;
    // std::cout << "long long: " << myLongLong << std::endl;
    // std::cout << "unsigned int: " << myUnsignedInt << std::endl;

    // // Floating-Point Types
    // float myFloat = 3.14159f;
    // double myDouble = 3.141592653589793;
    // long double myLongDouble = 3.141592653589793238L;

    // std::cout << "\nFloating-Point Types:" << std::endl;
    // std::cout << "float: " << myFloat << std::endl;
    // std::cout << "double: " << myDouble << std::endl;
    // std::cout << "long double: " << myLongDouble << std::endl;

    // // Character Types
    // char myChar = 'A';
    // unsigned char myUnsignedChar = 255;
    // wchar_t myWideChar = L'Z';

    // std::cout << "\nCharacter Types:" << std::endl;
    // std::cout << "char: " << myChar << std::endl;
    // std::cout << "unsigned char: " << static_cast<int>(myUnsignedChar) << std::endl;  // Casting to int for display
    // std::wcout << L"wchar_t: " << myWideChar << std::endl;

    // // Boolean Type
    // bool myBool = true;

    // std::cout << "\nBoolean Type:" << std::endl;
    // std::cout << "bool: " << std::boolalpha << myBool << std::endl;  // boolalpha to print true/false instead of 1/0

    // return 0;

    /***********************************************
    *  Character type
    **********************************************/
    char middle_initial {'J'};  // Notice the single quotes around characters
    cout << "My middle initial is " << middle_initial << endl;
    
    /***********************************************
    *  Integer types
    **********************************************/
    unsigned short int exam_score {55};  // same as unsigned short exam_score {55};
    cout << "My exam score was " << exam_score << endl;

    int countries_represented {65};
    cout << "There were " << countries_represented << " countries represented in my meeting" << endl;
    
    long people_in_florida {20610000};
    cout << "There are about " << people_in_florida << " people in Florida" << endl;
   
    long long people_on_earth  {7'600'000'000};     // make sure this is a long long and not just a long
    cout << "There are about " << people_on_earth << " people on earth" << endl;
    
    long long distance_to_alpha_centauri {9'461'000'000'000};
    cout << "The distance to alpha centauri is " << distance_to_alpha_centauri << " kilometers" << endl;
    
   
    /***********************************************
    *  Floating point types
    **********************************************/
    float  car_payment { 401.23};
    cout << "My car payment is " << car_payment << endl;
    
    double pi {3.14159};
    cout << "PI is " << pi << endl;
    
    long double large_amount {2.7e120};
    cout << large_amount << " is a very big number" << endl;
    
    /***********************************************
    *  Boolean type
    **********************************************/
    bool game_over {false};
    cout << "The value of gameOver is " << game_over << endl;
    
    /***********************************************
    *  Overflow example
    **********************************************/
    short value1 {30000};
    short value2 {1000};
    short  product {value1 * value2};
    
    cout << "The product of " << value1 <<  " and " << value2 << " is " <<  product << endl;
    
    return 0;
}
