### Lab Activity 1: Understanding Basic Inheritance
**Objective:** To understand how inheritance works in C++.
- Create a simple base class with some properties and methods.
- Derive a class from the base class and add some properties and methods to it.
- Demonstrate object creation and method calling from both classes.

### Lab Activity 2: Inheritance Terminology and Notation
**Objective:** To get familiar with the terminology and notation of inheritance.
- Write code snippets that define base and derived classes using different access specifiers: `public`, `protected`, and `private`.
- Illustrate the different access levels for members in each case.

### Lab Activity 3: Exploring Inheritance vs Composition
**Objective:** To distinguish between inheritance and composition in class design.
- Create two classes that share a common set of functionalities using inheritance.
- Redo the same using composition and compare the approaches in terms of flexibility and code reusability.

### Lab Activity 4: Deriving Classes from Existing Classes
**Objective:** To practice extending existing classes.
- Start with a base class and derive multiple levels of subclasses from it.
- Overload methods and demonstrate polymorphic behavior.

### Lab Activity 5: Protected Members and Class Access
**Objective:** To learn about the `protected` access specifier and its use in inheritance.
- Define a class with `public`, `private`, and `protected` members.
- Derive a subclass and try to access each member to understand the difference between the access specifiers.

### Lab Activity 6: Constructors and Destructors in Inheritance
**Objective:** To understand the order of constructor and destructor calls in inheritance.
- Create a base class and a derived class, each with their constructors and destructors.
- Instantiate the derived class and observe the order in which constructors and destructors are called.

### Lab Activity 7: Passing Arguments to Base Class Constructors
**Objective:** To practice passing arguments from a derived class to a base class constructor.
- Design a base class that accepts parameters in its constructor.
- Derive a class from it and ensure that the base class constructor is properly called with arguments.

### Lab Activity 8: Copy/Move Constructors and Operator= in Inheritance
**Objective:** To learn how to handle copying and moving of derived class objects.
- Implement custom copy and move constructors, and the assignment operator in both base and derived classes.
- Demonstrate deep copying and the importance of resource management in derived classes.

### Lab Activity 9: Redefining Base Class Methods
**Objective:** To practice method overriding and the use of the `virtual` keyword.
- Create a method in the base class and override it in the derived class.
- Use pointers or references to base class objects to demonstrate polymorphic behavior.

### Lab Activity 10: Implementing Multiple Inheritance
**Objective:** To understand and implement multiple inheritance.
- Create two base classes with different methods and a derived class that inherits from both.
- Solve any ambiguity and demonstrate the use of the derived class’s methods inherited from both base classes.