#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structures to hold student data
struct Student {
    string name;
    int grade;
};

// Function prototypes
void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
int calculateAverage(const vector<Student>& students);
int findHighestGrade(const vector<Student>& students);
int findLowestGrade(const vector<Student>& students);

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "GradeBook Manager\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Calculate Average Grade\n";
        cout << "4. Display Highest Grade\n";
        cout << "5. Display Lowest Grade\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                cout << "Average Grade: " << calculateAverage(students) << endl;
                break;
            case 4:
                cout << "Highest Grade: " << findHighestGrade(students) << endl;
                break;
            case 5:
                cout << "Lowest Grade: " << findLowestGrade(students) << endl;
                break;
            case 6:
                cout << "Goodbye!";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice != 6);

    return 0;

}

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student's name: ";
    cin >> newStudent.name;
    cout << "Enter student's grade: ";
    cin >> newStudent.grade;
    students.push_back(newStudent);
}

void displayStudents(const vector<Student>& students) {
    for (const Student& s : students) {
        cout << s.name << ": " << s.grade << endl;
    }
}

int calculateAverage(const vector<Student>& students) {
    int total = 0;
    for (const Student& s : students) {
        total += s.grade;
    }
    return students.empty() ? 0 : total / students.size();
}

int findHighestGrade(const vector<Student>& students) {
    int highest = INT_MIN;
    for (const Student& s : students) {
        if (s.grade > highest) {
            highest = s.grade;
        }
    }
    return highest;
}

int findLowestGrade(const vector<Student>& students) {
    int lowest = INT_MAX;
    for (const Student& s : students) {
        if (s.grade < lowest) {
            lowest = s.grade;
        }
    }
    return lowest;
}
