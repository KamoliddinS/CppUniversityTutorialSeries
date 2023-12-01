#include <Customer.h>

#include <string>


using namespace std;


Customer::Customer(string n, string p, string e)
    : name(n), phone(p), email(e) {}


string Customer::getName() const {
    return name;
}

string Customer::getPhone() const {
    return phone;
}

string Customer::getEmail() const {
    return email;
}

void Customer::setName(string name) {
    this->name = name;
}

void Customer::setPhone(string phone) {
    this->phone = phone;
}

void Customer::setEmail(string email) {
    this->email = email;
}
