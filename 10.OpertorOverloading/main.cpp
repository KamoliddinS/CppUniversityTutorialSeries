

#include <iostream>


class Unviersity {
 int numberOfStudents;
 int numberOfTeachers;
 int numberOfBuildings;

public:
    Unviersity(int numberOfStudents, int numberOfTeachers, int numberOfBuildings) {
    this->numberOfStudents = numberOfStudents;
    this->numberOfTeachers = numberOfTeachers;
    this->numberOfBuildings = numberOfBuildings;
    }


    Unviersity& operator+(const Unviersity& other) {
        this->numberOfStudents += other.numberOfStudents;
        this->numberOfTeachers += other.numberOfTeachers;
        this->numberOfBuildings += other.numberOfBuildings;
        return *this;
    }

    bool operator==( const  Unviersity&  other) const{
        return this->numberOfStudents == other.numberOfStudents &&
               this->numberOfTeachers == other.numberOfTeachers &&
               this->numberOfBuildings == other.numberOfBuildings;
    }


    void print() {
        std::cout << "Number of students: " << numberOfStudents << std::endl;
        std::cout << "Number of teachers: " << numberOfTeachers << std::endl;
        std::cout << "Number of buildings: " << numberOfBuildings << std::endl;
    }
    bool isEqual(const Unviersity& other) const {
        return this->numberOfStudents == other.numberOfStudents &&
               this->numberOfTeachers == other.numberOfTeachers &&
               this->numberOfBuildings == other.numberOfBuildings;
    }


};

int main(){
    Unviersity akfaUniversity(200, 20, 10);
    // akfaUniversity.print();

    Unviersity nationalUniversity(200, 20, 10);
    std::cout<< "before calling operator +"<< std::endl;
    // akfaUniversity + nationalUniversity;
    // akfaUniversity.print();
    // int a =10; 
    // int b = 30;
    // int a = a+b; 
    // // is this unvisrties are same?

    std::cout<< "Equal: "<< (akfaUniversity == nationalUniversity) << std::endl;

    // it is just like this
    std::cout<< "Equal: "<< ("aziz" == "laziz") << std::endl;

        std::cout<< "Equal: "<< (akfaUniversity.isEqual(nationalUniversity)) << std::endl;



}
