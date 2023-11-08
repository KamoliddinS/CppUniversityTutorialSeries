
### Coding Challenge 1: Simple Inheritance and Overriding
**Challenge:** Create a class hierarchy with a base class `Shape` and derived classes `Circle` and `Rectangle`. Override a method `draw()` in both derived classes to print out which shape is being drawn.

### Coding Challenge 2: Base Class Pointers to Derived Class Objects
**Challenge:** Write a program that uses a vector of base class pointers to manage and invoke the `draw()` method of various derived shape objects polymorphically.

### Coding Challenge 3: Understanding Virtual Function Mechanics
**Challenge:** Create a function that takes a base class pointer and calls a virtual function. Modify the virtual function's behavior in the derived class and use it to demonstrate the virtual function dispatch mechanism.

### Coding Challenge 4: Custom Polymorphic Behavior
**Challenge:** Extend the shape hierarchy with a `Triangle` class. Implement a virtual function `area()` and demonstrate polymorphic behavior by calculating the area of shapes stored in a collection of base class pointers.

### Coding Challenge 5: The Importance of Virtual Destructors
**Challenge:** Design a scenario where a derived class has a dynamically allocated resource. Demonstrate the memory leak if the base class destructor is not virtual and correct it by making the destructor virtual.

### Coding Challenge 6: Effective Use of `override` and `final`
**Challenge:** Implement classes where methods are correctly marked with `override`. Then, create a class hierarchy where certain methods are marked as `final` and demonstrate the compiler errors when trying to override those methods in further derived classes.

### Coding Challenge 7: Slicing and the Perils of Polymorphism
**Challenge:** Create a program that accidentally causes object slicing. Then, modify the program to use pointers or references to avoid slicing and maintain polymorphic behavior.

### Coding Challenge 8: Abstract Base Classes and Interfaces
**Challenge:** Design an interface as an abstract base class with only pure virtual functions. Implement the interface with derived classes and demonstrate polymorphic usage.

### Coding Challenge 9: Multi-level Inheritance and Polymorphism
**Challenge:** Create a multi-level inheritance hierarchy with at least three levels of inheritance. Use polymorphism to invoke methods across the hierarchy and demonstrate how the most derived method is chosen.

### Coding Challenge 10: Polymorphic Cloning
**Challenge:** Implement a `clone()` method in a polymorphic class hierarchy that allows for making copies of objects without knowing their concrete class. This method should leverage the `virtual` keyword to ensure the correct copy-constructor is called.
