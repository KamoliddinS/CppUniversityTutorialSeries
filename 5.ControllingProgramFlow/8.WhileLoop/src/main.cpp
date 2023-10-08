#include <iostream>
#include <vector>
#include "Student.h"

int main() {
    std::vector<Student> students;

    // Collect student data
    while (true) {
        Student student;
        std::cout << "Enter student name (or 'q' to quit): ";
        std::cin >> student.name;

        if (student.name == "q") {
            break;
        }

        std::cout << "Enter student score: ";
        std::cin >> student.score;
        students.push_back(student);
    }

    // Calculate and display grades
    for (const Student& student : students) {
        char grade;

        if (student.score >= 90) {
            grade = 'A';
        } else if (student.score >= 80) {
            grade = 'B';
        } else if (student.score >= 70) {
            grade = 'C';
        } else if (student.score >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }

        std::cout << "Name: " << student.name << ", Score: " << student.score << ", Grade: " << grade << std::endl;
    }

    // Example 2 - Using while loop to validate user input
    // int number {};
    // std:: cout << "Enter an integer less than 100: ";
    // std::cin >> number;

    // while (number >= 100) {
    //     std::cout << "Enter an integer less than 100: ";
    //     std::cin >> number;
    // }
    std::cout << "Thanks!" << std::endl;

    return 0;
}
