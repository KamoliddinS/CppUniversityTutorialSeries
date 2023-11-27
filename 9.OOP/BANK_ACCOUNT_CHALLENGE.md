
# Bank Account Challenge
Hi, this is our last challenge on Basics of OOP in C++.
I hope this challenge helps you to grasp the concepts of OOP in C++. 
Next Week, we will be learning about Advanced OOP in C++. Such as Inheritance, Polymorphism, and more.
That is why it is important to understand the basics of OOP in C++.

1. **Implementing a Basic BankAccount Class with Constructors**
   - Challenge: Design a `BankAccount` class with different types of constructors. The class should include data members like `accountNumber`, `accountHolderName`, and `balance`. Implement a default constructor, a parameterized constructor, and an overloaded constructor which takes different numbers of arguments. Demonstrate how each constructor is called and its effect.

2. **Deep Copy vs. Shallow Copy in Copy Constructors**
   - Challenge: Extend the `BankAccount` class to include a dynamic data member (e.g., an array representing transaction history). Implement both a shallow copy and a deep copy constructor. Demonstrate the difference between the two, particularly in scenarios like copying objects. To your LAB teacher,  highlight the issues that might arise with shallow copying and how deep copying resolves them.

3. **Utilizing Move Constructors and The 'this' Pointer**
   - Challenge: Add a move constructor to the `BankAccount` class to efficiently handle temporary objects. Also, implement a method that uses the `this` pointer to compare two bank accounts. For instance, a method that checks if two accounts have the same account number, comparing the `this` object with the one passed as an argument.

4. **Static Members and Friend Functions**
   - Challenge: Add a static data member to the `BankAccount` class, such as a static counter to keep track of the total number of accounts created. Also, implement a friend function that can access the private members of the class. This function might be used to perform operations like transferring funds between two accounts, requiring access to private members of both objects.
