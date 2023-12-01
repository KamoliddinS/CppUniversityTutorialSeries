#include <iostream>
#include <chrono> // is for date and time managment
#include <ctime>

#include <CarRentalSystem.h>


using namespace std;


bool getUserPrompt( string prompt, string* input){
    cout<< "Enter: "<<prompt<<endl;
    cin>>*input;
    return true;
}

void mainPrompt( int* choice){
    cout<<"1. Add a car"<<endl;
    cout<<"2. Add a customer"<<endl;
    cout<<"3. Rent a car"<<endl;
    cout<<"4. Return a car"<<endl;
    cout<<"5. Display all cars"<<endl;
    cout<<"6. Display all available cars"<<endl;
    cout<<"7. Display all rented cars"<<endl;
    cout<<"8. Display all customers"<<endl;
    cout<<"9. Display all rentals"<<endl;
    cout<<"10. Exit"<<endl;
    cin>>*choice;
}



int main() {
   
    CarRentalSystem carRentalSystem("Ahmadjon Boy car rental system");    

    int choice;

    int* pChoice = &choice;
    mainPrompt(pChoice);

    do
    {
        switch (choice)
        {
        case 1:
            {
            string make, model, plateNumber;
            
            getUserPrompt("make", &make);
            getUserPrompt("model", &model);
            getUserPrompt("plate number", &plateNumber);

           

            // carRentalSystem.addCar(make, model, year, price, isAvailable, plateNumber);

            carRentalSystem.displayAllCars();
            cout<<"DISPLAYED"<<endl;

            cin.ignore();
            
            mainPrompt(pChoice);
        
            break;
            }
        default:
            break;
        }




    } while (choice != 10);
    




    return 0;
}






















//  // Get the current time as a std::chrono::system_clock object
//     std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

//     // Convert to a time_t object
//     std::time_t now_c = std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));
//     cout<<now_c<<endl; // th

//     // Convert to a tm struct for breaking down into year/month/day etc.
//     std::tm* now_tm = std::localtime(&now_c);

//     std::cout << "Yesterday's Year: " << (now_tm->tm_year + 1900) << '\n';
//     std::cout << "Yesterday's Month: " << (now_tm->tm_mon + 1) << '\n';
//     std::cout << "Yesterday's Day: " << now_tm->tm_mday << '\n';

//     // Time 
//     std::cout << "Yesterday's Hour: " << now_tm->tm_hour << '\n';
//     std::cout << "Yesterday's Minutes: " << now_tm->tm_min << '\n';
//     std::cout << "Yesterday's Seconds: " << now_tm->tm_sec << '\n';
