// Exercise 6: Exam report
// Read exam.csv into a vector of Student and print the report from the exercise text.
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum class Result { fail, pass, good, excellent };

struct Student {
    std::string name;
    int score = 0;
};

// TODO: write these three functions.
//   Result resultFor(int score)             86 or more: excellent, 71 or more: good,
//                                           56 or more: pass, less: fail
//   std::string toText(Result result)       "fail", "pass", "good" or "excellent"
//   bool parseStudent(const std::string& line, Student& student)
//                                           fills student from "Aziz,85";
//                                           false if the line has no comma

int main() {
    std::vector<Student> students;

    // TODO: open exam.csv. If that fails, print a message and return 1.
    // TODO: read the file line by line. Store every good line in students.
    //       For every other line print "Skipped: " and the line.
    // TODO: print the table: one row for the titles, one row for each student.
    // TODO: print the number of students and the average score.
    std::cout << "Students: " << students.size() << '\n';
}
