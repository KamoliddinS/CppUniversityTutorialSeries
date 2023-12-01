#ifndef RENTAL_H
#define RENTAL_H

#include <string>
#include "Car.h"
class Rental {
    std::string customerName;
    std::string customerPhone;
    std::string carMake;
    std::string carModel;
    int rentalDays;
    double rentalPrice;
    double totalPrice;
    std::string rentalDate;
    std::string returnDate;
    bool isReturned;
    Car car; 
    

public:
    Rental(std::string customerName, std::string customerPhone, std::string carMake, std::string carModel, int rentalDays, double rentalPrice, double totalPrice, std::string rentalDate, std::string returnDate, bool isReturned);
    // Getters and setters
    std::string getCustomerName() const;
    std::string getCustomerPhone() const;
    std::string getCarMake() const;
    std::string getCarModel() const;
    int getRentalDays() const;
    double getRentalPrice() const;
    double getTotalPrice() const;
    std::string getRentalDate() const;
    std::string getReturnDate() const;
    bool getIsReturned() const;
    void setCustomerName(std::string customerName);
    void setCustomerPhone(std::string customerPhone);
    void setCarMake(std::string carMake);
    void setCarModel(std::string carModel);
    void setRentalDays(int rentalDays);
    void setRentalPrice(double rentalPrice);
    void setTotalPrice(double totalPrice);
    void setRentalDate(std::string rentalDate);
    void setReturnDate(std::string returnDate);
    void setIsReturned(bool isReturned);
};


#endif
