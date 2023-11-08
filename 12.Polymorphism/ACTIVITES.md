
### Lab Activity 1: Introduction to Polymorphism
**Objective:** Understand and explain the concept of polymorphism in C++.
- Write a short explanation of polymorphism.
- Create a simple program with a base class and a derived class.
- Demonstrate function overriding in the derived class.

### Lab Activity 2: Using a Base Class Pointer
**Objective:** Learn how to use base class pointers for polymorphic behavior.
- Create a base class with a virtual function.
- Derive multiple classes from the base class, overriding the virtual function.
- Use a base class pointer to point to derived class objects and call the overridden functions.

### Lab Activity 3: Virtual Functions
**Objective:** Explore the behavior of virtual functions in a class hierarchy.
- Extend the previous activity's classes with additional virtual functions.
- Investigate the behavior when calling virtual functions from base class pointers and references.

### Lab Activity 4: Virtual Destructors
**Objective:** Understand the significance of virtual destructors in a polymorphic base class.
- Create a base class with a non-virtual destructor and derive a class from it.
- Allocate a derived object using a base class pointer and then delete it to observe incorrect destructor behavior.
- Modify the base class destructor to be virtual and observe the difference.

### Lab Activity 5: Override Specifier
**Objective:** Practice using the `override` specifier in derived class functions.
- Modify the derived classes' overridden functions to include the `override` specifier.
- Introduce a new version of the virtual function in the base class and observe how the `override` specifier helps identify issues at compile time.

### Lab Activity 6: Final Specifier
**Objective:** Implement the `final` specifier in classes and member functions.
- Prevent a class from being further derived using the `final` specifier.
- Prevent a virtual function from being overridden in any derived class using the `final` specifier.

### Lab Activity 7: Base Class References
**Objective:** Utilize base class references to implement polymorphism.
- Rewrite the previous pointer-based polymorphic calls using references instead.
- Compare the behavior of pointers and references in polymorphic scenarios.

### Lab Activity 8: Pure Virtual Functions and Abstract Classes
**Objective:** Define and use pure virtual functions and abstract classes.
- Create an abstract class with at least one pure virtual function.
- Derive classes to implement the pure virtual function.
- Use a vector of pointers to the abstract class to store derived class objects and call the pure virtual function.

### Lab Activity 9: Dynamic Casting and Type Identification
**Objective:** Use dynamic casting and type identification to safely downcast base class pointers.
- Use `typeid` and `dynamic_cast` to ensure safe downcasting.
- Write code to check the actual type of an object before performing a specific operation.

### Lab Activity 10: Polymorphism with Smart Pointers
**Objective:** Manage polymorphic objects with smart pointers.
- Use `std::unique_ptr` and `std::shared_ptr` to handle objects of polymorphic classes.
- Explain the advantages of using smart pointers over raw pointers in the context of dynamic polymorphism.
