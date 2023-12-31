#include <iostream>
#include <vector>
#include "Student.h"

int main() {
    std::vector<Student> students;

    // Collect student data
   char selection {};
   do {
         Student student;
         std::cout << "Enter student name (or 'q' to quit): ";
         std::cin >> student.name;
    
         if (student.name == "q") {
              break;
         }
    
         std::cout << "Enter student score: ";
         std::cin >> student.score;
         students.push_back(student);
    
         std::cout << "Would you like to enter another student (Y/N)? ";
         std::cin >> selection;
    } while (selection == 'y' || selection == 'Y');

    
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

    return 0;
}
