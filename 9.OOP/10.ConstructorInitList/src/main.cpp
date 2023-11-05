#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    const int studentID;
    std::string name;
    std::vector<int> grades;

public:
    // Constructor with an initialization list
    Student(int id, std::string studentName, const std::vector<int>& studentGrades)
        : studentID(id), // Initialize the const member variable
          name(studentName), // Initialize the name
          grades(studentGrades) // Initialize the grades vector with a copy of studentGrades
    {
        // The body of the constructor is empty because we've already initialized all members
    }

    // Function to print student details
    void printDetails() const {
        std::cout << "Student ID: " << studentID << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Grades: ";
        for (int grade : grades) {
            std::cout << grade << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Initialize the grades for the student
    std::vector<int> johnGrades = {85, 92, 76, 81};

    // Create a Student object using the constructor
    Student john(12345, "John Doe", johnGrades);

    // Print the student details
    john.printDetails();

    return 0;
}
