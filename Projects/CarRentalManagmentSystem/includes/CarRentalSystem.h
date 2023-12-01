
#ifndef CAR_RENTAL_SYSTEM_H                                                                      // this is header guard, it prevents the compiler from including the same header file more than once
#define CAR_RENTAL_SYSTEM_H

#include <Car.h>
#include <Customer.h>
#include <Rental.h>



#include <string>

using namespace std; 

class CarRentalSystem{ 

    vector<Car> cars;
    vector<Customer> customers; 
    vector<Rental> rentals; 

    string name; 


    public:
    CarRentalSystem(string n  ); 


    bool addCar( string make, string model, int year, double price, bool isAvailable, string plateNumber );

     // Search the cars with plate number
    Car* searchByPlateNumber(string plateNumber);

    //Update the car with plate number
    bool updateCarPrice(string plateNumber, double price); 

    bool updateCarAvailability(string plateNumber, bool isAvailable);


    void displayAllCars() const;






    bool addCustomer( string name, string phone, string email );





    string getName() const;
    

};







#endif


