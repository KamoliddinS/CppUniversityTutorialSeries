
# Struct in C++

In C++, a `struct` (short for "structure") is a way to combine multiple variables under a single name. These variables inside a `struct` can be of different data types.

## Definition

Think of a `struct` as a box where you can store different kinds of items together. For instance, if you want to describe a student, you can have their name, age, and grade all together in one box.

Here's how you define a `struct`:

```cpp
struct Student {
    string name;
    int age;
    double grade;
};
```

## How to Use

### Creating an instance

Once you define a `struct`, you can create an instance (or object) of it:

```cpp
Student student1;
```

### Accessing and Modifying

You can access or change the data inside the `struct` using the dot `.` operator:

```cpp
student1.name = "Ahmed";
student1.age = 20;
student1.grade = 89.5;

cout << student1.name;  // Outputs: Ahmed
```

### Passing to Functions

You can pass structures to functions and return them as well:

```cpp
void printStudentInfo(Student s) {
    cout << "Name: " << s.name << ", Age: " << s.age << ", Grade: " << s.grade;
}

Student createStudent() {
    Student temp;
    temp.name = "Mona";
    temp.age = 21;
    temp.grade = 91.0;
    return temp;
}
```

## Arrays of Struct

Just like other data types, you can create arrays of structures:

```cpp
Student classOf2023[30];
```

And you can access them like this:

```cpp
classOf2023[0].name = "Ali";
classOf2023[0].age = 19;
```

## Why Use Struct?

- **Organization**: Keep related data together. For instance, all information about a student can be kept together, rather than having separate arrays for names, ages, etc.
  
- **Flexibility**: A function that needs to receive multiple related data points can take a single structure as a parameter, instead of multiple parameters.

## Exercises

1. Define a `struct` named `Book` with fields: title (string), author (string), and pages (int). Create a few instances of the `Book` structure and print their details.

2. Define a `struct` named `Date` with fields: day, month, and year (all integers). Write a function that prints the date in the format `dd/mm/yyyy`.

