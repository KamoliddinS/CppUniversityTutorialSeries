
#ifndef CAR_H                                                                       // this is header guard, it prevents the compiler from including the same header file more than once
#define CAR_H

#include <string>

using namespace std;

class Car {
    std::string make;
    std::string model;
    std::string plateNumber;

    int year;
    double rental_price;
    bool isAvailable;


public:
    Car(std::string make, std::string model, int year, double price, bool isAvailable, std::string plateNumber);
    // Getters and setters
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    double getPrice() const;
    bool getIsAvailable() const;
    std::string getPlateNumber() const;

    void setMake(std::string make);
    void setModel(std::string model);
    void setYear(int year);
    void setPrice(double price);
    void setIsAvailable(bool isAvailable);


};

#endif // this is the end of the header guard