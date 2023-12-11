#include "Student.h"
#include <cstring>
#include <iostream>

Student::Student(const char *name, int id, float gpa) : id(id), gpa(gpa) {
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
}

Student::Student(const Student &source) : id(source.id), gpa(source.gpa) {
    std::cout << "Copy constructor called." << std::endl;
    name = new char[std::strlen(source.name) + 1];
    // this->name= source.name;
    std::strcpy(name, source.name);
}

// Overloaded Assignment Operator
Student& Student::operator=(const Student &source) {

    std::cout << "Assignment operator called." << std::endl;
    if (this != &source) { // Check for self-assignment (A = A)
        delete[] name; // Free existing resource
        name = new char[std::strlen(source.name) + 1];
        std::strcpy(name, source.name);
        id = source.id;
        gpa = source.gpa;
    }
    return *this;
}

// As usual, destructor to free memory allocated by new operator 
// don't forget to delete the dynamically allocated memory
Student::~Student() {
    
    delete[] name;
}

// Method to display student information
void Student::display() const {
    std::cout << "Student Name: " << name << "\nID: " << id << "\nGPA: " << gpa << std::endl;
}
