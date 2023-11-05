#include <iostream>
#include <vector>

class Car {
private:
    std::string model;
    static int count; // Static member variable to keep track of the number of Car objects

public:
    // Constructor that increments the static count for each object created
    Car(std::string mdl) : model(mdl) {
        count++;
    }

    // Static member function to get the current count of Car objects
    static int getCount() {
        return count;
    }

    // Regular member function to output the car model
    void displayModel() const {
        std::cout << "Car model: " << model << std::endl;
    }
};

// Initialize static member variable
int Car::count = 0;

int main() {
    Car car1("Toyota");
    Car car2("Honda");
    Car car3("Ford");

    // Output the total number of Car objects created
    std::cout << "Total cars created: " << Car::getCount() << std::endl;

    // Display models using the non-static member function
    car1.displayModel();
    car2.displayModel();
    car3.displayModel();

    return 0;
}
