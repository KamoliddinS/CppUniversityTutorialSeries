


### Challenge 1: Basic Inheritance
Create a `Vehicle` class with attributes like `speed` and `color`. Derive a `Car` class from `Vehicle` and add an attribute `numberOfDoors`. Instantiate a `Car` object and demonstrate access to the inherited attributes.

### Challenge 2: Multi-level Inheritance
Define a `Shape` class with a method to calculate area. Derive a `Rectangle` class from it, and then derive a `Cuboid` class from `Rectangle`. Add appropriate attributes and demonstrate calculating the area and volume of a `Cuboid`.

### Challenge 3: Method Overriding
Create a `Base` class with a `virtual` method `display()` that prints "Base class". Derive a `Derived` class from `Base` and override the `display()` method to print "Derived class". Show the effect of overriding when using base class pointers.

### Challenge 4: Access Control
Construct a base class with `public`, `protected`, and `private` members. Create a derived class and try to access each of these members from within the derived class to illustrate the inheritance access control.

### Challenge 5: Constructor Invocation Order
Create a base class `A` with a constructor that prints "Base", and a derived class `B` that prints "Derived" in its constructor. Instantiate an object of class `B` and observe the order of constructor calls.

### Challenge 6: Destructor Invocation Order
Similar to Challenge 5, add destructors in both base and derived classes that print messages when they are called. Create an object in a scoped block to see the order of destructor calls upon exiting the block.

### Challenge 7: Inheritance and Composition
Design a `Timer` class that has a start and stop method. Then create two classes, `CookingTimer` using inheritance and `RunningTimer` using composition of the `Timer` class. Compare how methods are accessed and used.

### Challenge 8: Operator Overloading in Inheritance
Overload the `+` operator in a `Point` class to add two point objects. Then derive a `ColorPoint` class that adds both the position and color values of two `ColorPoint` objects.

### Challenge 9: Virtual Base Classes
Create a diamond inheritance structure with classes `A`, `B` and `C` inheriting from `A`, and `D` inheriting from both `B` and `C`. Use virtual inheritance to ensure there is only one copy of `A`'s members in `D`.

### Challenge 10: Abstract Base Classes
Define an abstract base class `Instrument` with a pure virtual function `play()`. Derive classes `Guitar`, `Piano`, and `Violin` from it, implementing the `play()` function for each. Create an array of `Instrument` pointers and invoke `play()` on each.
