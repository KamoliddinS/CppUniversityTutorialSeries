

# Lab Activities on Basic OOP in C++ 

## Activity 1: Understanding Classes and Objects

**Objective:** Introduce the concept of classes and objects in C++.

**Task:**

1. **Define a Class:**
   - Create a class named `Book`.
   - Add three private attributes: `title`, `author`, and `pageCount`.
   - Provide public methods to set and get the values of these attributes.

2. **Create Objects:**
   - In the main function, create two `Book` objects.
   - Set their attributes using the methods defined.

3. **Display Object Data:**
   - Write a function to display the details of the books.

**Expected Output:** Program should display the details of the two `Book` objects.

---

## Activity 2: Encapsulation and Access Modifiers

**Objective:** Teach students about encapsulation and the use of access modifiers.

**Task:**

1. **Enhance the Book Class:**
   - Ensure that the `title`, `author`, and `pageCount` attributes are private.
   - Implement setter methods that validate the input (e.g., `pageCount` should be positive).

2. **Test Encapsulation:**
   - In the main function, try to set invalid values and observe the output.

**Expected Output:** Program should not allow invalid values for the attributes.

---

## Activity x: Array of Objects

**Objective:** Learn how to create an array of objects.

**Task:**
1. **Create an Array of Objects:**
   - In the main function, create an array of `Book` objects.
   - Initialize the array with some values.

2. **Display the Array:**
   - Write a function to display the details of all the books in the array.



## Activity 3: Basic Polymorphism

**Objective:** Understand polymorphism in the context of method overloading.

**Task:**

1. **Overload Methods:**
   - In the `Book` class, overload a method named `displayInfo`.
   - One version displays all attributes, while another only displays `title` and `author`.

2. **Test Overloaded Methods:**
   - In the main function, create a `Book` object and call both versions of `displayInfo`.

**Expected Output:** Both methods should work correctly, displaying different sets of information.

---

## Activity 4: Constructor Overloading

**Objective:** Learn about constructor overloading in C++.

**Task:**

1. **Overload Constructors:**
   - Implement two constructors for the `Book` class.
   - One should take all three attributes as parameters, and the other should take only `title` and `author`.

2. **Create Objects Using Different Constructors:**
   - In the main function, create `Book` objects using both constructors.

**Expected Output:** Objects should be initialized correctly using different constructors.

