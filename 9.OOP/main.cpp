#include <iostream>

using namespace std;


class AA;

class Student{
private: //by default everything is private
    string name; 
    int age; 
    int student_id; 

public:

    Student( string name, int a, int id): name(name), age(a), student_id(id){
    };

    friend void display(Student &s); //friend function can access private members of a class

    friend class AA; 
};


class AA{

public:

    void display(Student &s){

        cout << s.name << endl;
        cout << s.age << endl;
        cout << s.student_id << endl;

    }
};

void display(Student &s){

    cout << s.name << endl;
    cout << s.age << endl;
    cout << s.student_id << endl;

}


int main() {
    
    Student s1("John", 20, 1234);

    display(s1);
    

    AA a1;
    a1.display(s1);


    return 0;
}