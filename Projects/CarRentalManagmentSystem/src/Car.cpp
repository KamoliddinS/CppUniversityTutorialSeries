#include "Car.h"


using namespace std;

Car::Car(std::string make, std::string model, int year, double price, bool isAvailable, string plateNumber)
    : make(make), model(model), year(year),rental_price(price), isAvailable(isAvailable), plateNumber(plateNumber) {}

std::string Car::getMake() const {
    return make;
}

std::string Car::getModel() const {
    return model;
}

int Car::getYear() const {
    return year;
}

double Car::getPrice() const {
    return rental_price;
}

bool Car::getIsAvailable() const {
    return isAvailable;
}

void Car::setMake(std::string make) {
    this->make = make;
}

void Car::setModel(std::string model) {
    this->model = model;
}

string Car::getPlateNumber() const {
    return plateNumber;
}

void Car::setYear(int year) {
    this->year = year;
}

void Car::setPrice(double price) {
    this->rental_price = price;
}

void Car::setIsAvailable(bool isAvailable) {
    this->isAvailable = isAvailable;
}
