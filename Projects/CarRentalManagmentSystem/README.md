
## Car Rental System

### Project Structure:

1. **Classes and Objects:**
   - **Car:** Attributes like make, model, registration number, and rental status.
   - **Customer:** Details like name, driver's license number, and rental history.
   - **Rental:** Information about each rental, including the customer, car, and rental period.
   - **CarRentalSystem:** Central system managing cars, customers, and rentals.

2. **Core Features:**
   - **Manage Car Inventory:** Add, remove, or update cars in the inventory.
   - **Customer Management:** Add new customers or update existing customer information.
   - **Car Rental Processing:** Handle rental transactions, including assigning cars to customers.
   - **Return Process:** Manage the return of rental cars and update their status.
   - **Rental History:** Track and display past rentals for a car or customer.

3. **Additional Features:**
   - **Rate Calculation:** Calculate rental rates based on rental duration or car model.
   - **Availability Check:** Check the availability of cars for specific dates.
   - **Late Fee Calculation:** Calculate late fees for overdue returns.
   - **Data Persistence:** Save and retrieve system data using file handling.

4. **User Interface:**
   - A console-based interface for users to interact with the system.

5. **Data Storage:**
   - Utilize file handling for persistent storage of cars, customers, and rentals.



### How to build and run the project:
```
mkdir build 
cd build
cmake ..
make all
./CarRentalManagmentSystem

```

### Compile with G++:
```
g++ -std=c++17 -Iincludes src/main.cpp  src/Car.cpp src/CarRentalSystem.cpp src/Customer.cpp  -o CarRentalSysteme
```