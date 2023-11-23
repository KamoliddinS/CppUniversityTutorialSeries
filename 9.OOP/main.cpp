#include <iostream>
#include <string>
using namespace std;

// Define the Student class
class Student {
    private: 
        string name;
        int age;
        int score;
        int* p;

    public:
    // Constructor
    Student(string n, int a, int s): name(n), age(a), score(s){

        p = new int;
        *p = 100;
        cout<< "Constructor called for "<<name<<endl;
    }

    Student(string n, int a): Student(n, a, 0){}

    Student(): Student("None", 0){}

    void display(){
        cout<< "-------------"<<endl;
        cout<< "Name: "<<name<<endl;
        cout<< "Age: "<<age<<endl;
        cout<< "Score: "<<score<<endl;
        cout<< "-------------"<< endl;
    }

    ~Student(){
        delete p;
        cout<< "Destructor called for "<<name<<endl;
    }
};



int main(){


    Student jack("jack", 18, 100); 
    jack.display();

    Student tom("tom", 20);
    tom.display();


    Student jerry;
    jerry.display();


    
    return 0; 
}