// Gradebook, step 3: A gradebook class
#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    std::vector<int> scores;
};

double average(const Student& student);

// Prints a student as "Aziz: 85 90 78", without a line end.
std::ostream& operator<<(std::ostream& out, const Student& student);

// Keeps the students and protects them. Its rules: a name is in the gradebook only once,
// and every score is from 0 to 100.
class Gradebook {
public:
    // These four return false, and change nothing, when they cannot do their work.
    bool addStudent(const std::string& name, int score);    // the name must be new
    bool addScore(const std::string& name, int score);      // the name must be known
    bool save(const std::string& fileName) const;
    bool load(const std::string& fileName);

    bool hasStudent(const std::string& name) const;
    std::size_t size() const;

    // Call these three only when their question has an answer:
    const Student& student(const std::string& name) const;  // needs a known name
    double classAverage() const;                            // needs at least one student
    std::string bestName() const;                           // needs at least one student

    void printList(std::ostream& out) const;
    void printReport(std::ostream& out) const;

private:
    // Returns the position of the student with this name, or students_.size() if there is none.
    std::size_t find(const std::string& name) const;

    std::vector<Student> students_;
};

#endif
