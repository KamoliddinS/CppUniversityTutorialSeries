#include "Student.h"


int main() {
    Student s1("John Doe", 123, 3.5);
    Student s2 = s1; // Copy constructor is called

    s1.display();
    s2.display();

    Student s3;
    s3 = s1;  // Assignment operator is called
    s3.display();

    return 0;
}

