#ifndef CUSTOMER_H                                                                      // this is header guard, it prevents the compiler from including the same header file more than once
#define CUSTOMER_H



#include <string>


using namespace std; 

class Customer { 

    string name; 
    string phone;
    string email;

    public:
    Customer(string n, string p, string e);


    string getName() const;
    string getPhone() const;
    string getEmail() const;

    void setName(string name);
    void setPhone(string phone);
    void setEmail(string email);


};






#endif
