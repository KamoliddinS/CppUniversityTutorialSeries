#include <iostream>

using namespace std;

class House{
    private:
        int rooms; 
        int doors; 
        int windows;
        bool isDoorOpen;
    
    public: 
        House(int numberOfRooms, int numberOfDoors, int numberOfwindows){
            rooms = numberOfRooms;
            doors = numberOfDoors;
            windows = numberOfwindows;
            isDoorOpen = false;
        }
        void openDoor(){
            isDoorOpen = true;
        }
        void closeDoor(){
            isDoorOpen = false;
        }
        void setRooms(int numberOfRooms){
            if( numberOfRooms < 0 || numberOfRooms > 20){
                cout<<"Number of rooms can not be negative or room numbers cannot exceed 20"<<endl;
            }else{
                rooms = numberOfRooms;
            }
        }
        int getRooms(){
            return rooms;
        }
};

int main() {

    House amalsHouse(3, 2, 4);
    amalsHouse.setRooms(-1);
    amalsHouse.setRooms(21);
    cout<<amalsHouse.getRooms()<<endl;
    
    House kamoliddinHouse(4, 3, 5);
    cout<< kamoliddinHouse.getRooms()<<endl;
    return 0;
}