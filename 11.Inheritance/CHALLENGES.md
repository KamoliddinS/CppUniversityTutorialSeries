


### Challenge 1: Basic Inheritance
Create a `Vehicle` class with attributes like `speed` and `color`. Derive a `Car` class from `Vehicle` and add an attribute `numberOfDoors`. Instantiate a `Car` object and demonstrate access to the inherited attributes.

### Challenge 2: Multi-level Inheritance
Define a `Shape` class with a method to calculate area. Derive a `Rectangle` class from it, and then derive a `Cuboid` class from `Rectangle`. Add appropriate attributes and demonstrate calculating the area and volume of a `Cuboid`.


### Challenge 3: Inheritance and Composition
Design a `Timer` class that has a start and stop method. Then create two classes, `CookingTimer` using inheritance and `RunningTimer` using composition of the `Timer` class. Compare how methods are accessed and used.

### Challenge 4: Operator Overloading in Inheritance
Overload the `+` operator in a `Point` class to add two point objects. Then derive a `ColorPoint` class that adds both the position and color values of two `ColorPoint` objects.


### Challenge 5: Abstract Base Classes
Define an abstract base class `Instrument` with a pure virtual function `play()`. Derive classes `Guitar`, `Piano`, and `Violin` from it, implementing the `play()` function for each. Create an array of `Instrument` pointers and invoke `play()` on each.
