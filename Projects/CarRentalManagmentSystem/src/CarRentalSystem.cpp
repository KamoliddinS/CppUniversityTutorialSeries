#include <CarRentalSystem.h>

#include <string>
#include <iostream>

using namespace std;

CarRentalSystem::CarRentalSystem(string n): name(n){};


bool CarRentalSystem::addCar( string make, string model, int year, double price, bool isAvailable, string plateNumber ){
    
    Car car(make, model, year, price, isAvailable, plateNumber);
    cars.push_back(car);

    return true;
}


bool CarRentalSystem::addCustomer( string name, string phone, string email ){

    Customer customer(name, phone, email);
    customers.push_back(customer);

    return true;
}

Car* CarRentalSystem::searchByPlateNumber(string plateNumber){
    for (int i = 0; i < cars.size(); i++){
        if (cars[i].getPlateNumber() == plateNumber){
            return &cars[i];
        }
    }
    return nullptr;
}

bool CarRentalSystem::updateCarPrice(string plateNumber, double price){
    Car* car = searchByPlateNumber(plateNumber);
    if (car != nullptr){
        car->setPrice(price);
        return true;
    }
    return false;
}


bool CarRentalSystem::updateCarAvailability(string plateNumber, bool isAvailable){
    Car* car = searchByPlateNumber(plateNumber);
    if (car != nullptr){
        car->setIsAvailable(isAvailable);
        return true;
    }
    return false;
}


void CarRentalSystem::displayAllCars() const{
    for (int i = 0; i < cars.size(); i++){
        cout << cars[i].getMake() << " " << cars[i].getModel() << " " << cars[i].getYear() << " " << cars[i].getPrice() << " " << cars[i].getIsAvailable() << " " << cars[i].getPlateNumber() << endl;
    }
}




string CarRentalSystem::getName() const{
    return name;
}