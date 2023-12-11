#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
    char *name; // Dynamically allocated memory for the student's name
    int id;
    float gpa;

public:
    Student(const char *name = "", int id = 0, float gpa = 0.0f);

    Student(const Student &source);

    // Overloaded Assignment Operator
    Student& operator=(const Student &source);

    ~Student();

    void display() const;
};

#endif 
