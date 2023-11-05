
# Accessing Class Members in C++

In this segment of our C++ course, we'll explore how to access the different members of a class. This includes the attributes (data members) and methods (member functions) that define what a class knows and can do.

## 🚪 Public vs Private Access

When we define a class, we categorize its members as either `public` or `private`:

- **Public Members** can be accessed from anywhere outside the class where the object is visible.
- **Private Members** can only be accessed by functions that are part of the class.

Let's consider a `Car` class to understand this concept better.

```cpp
class Car {
public:
    // Public attribute
    string model;

    // Public method
    void startEngine() {
        cout << "Engine started!" << endl;
    }

private:
    // Private attribute
    string engineSerialNumber;

    // Private method
    void authenticateDriver() {
        // ... some code to authenticate the driver
    }
};
```

In this example:
- Any code that creates a `Car` object can set or get the `model` and call the `startEngine()` method directly.
- The `engineSerialNumber` and `authenticateDriver()` method cannot be accessed directly from outside the class.

## 🔑 Accessing Public Members

You can access public members using the dot operator `.` on an object. Here's an example of how to do this:

```cpp
Car myCar;          // Create a Car object
myCar.model = "SUV";  // Accessing public data member
myCar.startEngine();  // Calling public member function
```

## 🔒 Accessing Private Members

To access private members, you typically use public methods that act as "getters" and "setters". These methods provide controlled access to the private members:

```cpp
class Car {
public:
    // Setter for private member
    void setEngineSerialNumber(string serial) {
        // You might include checks or logic here
        engineSerialNumber = serial;
    }

    // Getter for private member
    string getEngineSerialNumber() {
        // You might include logic to control who can get this information
        return engineSerialNumber;
    }

private:
    string engineSerialNumber;
};

// ...

Car myCar;
myCar.setEngineSerialNumber("123ABC456");  // Set private member
string serial = myCar.getEngineSerialNumber();  // Get private member
```

In this adjusted `Car` class example, we've added public "setter" and "getter" methods to write and read the private `engineSerialNumber`.

