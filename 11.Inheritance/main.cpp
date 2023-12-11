#include <iostream> 
#include <vector>

using namespace std;

class Engine{
    private:
        int fuel;
        int silinder;
        float capacity;
    

    public:

        Engine(){
            fuel = 0;
            silinder = 0;
            capacity = 0;
        }
        Engine(int fuel, int silinder, float capacity){
            this->fuel = fuel;
            this->silinder = silinder;
            this->capacity = capacity;
        }

        void start(){
            std::cout << "Engine started" << std::endl;
        }
};

class Tire{
    private:
        int diameter;
        int width;

    public:
        Tire(int diameter, int width){
            this->diameter = diameter;
            this->width = width;
        }

        void roll(){
            std::cout << "Tire is rolling" << std::endl;
        }
};

class Seat{
    private:
        int material;
        int color;

    public:
        Seat(int material, int color){
            this->material = material;
            this->color = color;
        }

        void sit(){
            std::cout << "Sitting on the seat" << std::endl;
        }
};

class Car{
    private:
        Engine engine;
        vector<Tire> tires;
        vector<Seat> seats;


    public:
        Car( int fuelConsumption, int numberOfSillinders, float capacity, int numberOfTires, int numberOfSeats){
            
            engine = Engine(fuelConsumption, numberOfSillinders, capacity);


            // this is initialization of tires for the car
            for (int i = 0; i < numberOfTires; i++){
                Tire tire(10, 10);
                tires.push_back(tire);
            }

            // this is initialization of seats for the car
            for (int i = 0; i < numberOfSeats; i++){
                Seat seat(10, 10);
                seats.push_back(seat);
            }

        }

        void drive(){
            engine.start();
            for (int i = 0; i < tires.size(); i++){
                tires[i].roll();
            }
            std::cout << "Driving the car" << std::endl;
        }
};

int main(){
    Car car(10, 4, 10, 4, 4);
    car.drive();
    return 0;
}