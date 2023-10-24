#include <iostream>


using namespace std;



int add( int a, int b) { 
    return a+b; 
}



int main()
{
    int result = add(7,4);
    cout<< "This is sum of  7+5 is "<<result<<endl;

    cout<< "The sum fo 8+7 is "<< add(8,7)<<endl;
    return result;
}
