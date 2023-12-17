#include <iostream>
#include <vector>
using namespace std;

class Animal { 

public:
    Animal(){
        cout<<" Animal is created "<< endl;
    }

    virtual void breath()=0;  // this is pure virtual member method 
    // that means class inheriting Animal needs to implement this member method to be this Class which is Animal
    
    virtual ~Animal(){
        cout<< " Animal is being distroyed"<< endl;
    }

};

class I_Hunt {

    public:
    virtual void run()=0; 

    virtual ~I_Hunt(){
        cout<<"I_HUNT IS distructed"<<endl;
    }
};

class Dog final: public Animal, public I_Hunt {

    public:
        Dog(){
            cout<<"Dog has been created"<<endl;
        }
        void breath()  override {
            cout<<" Ha ha ha I can breath faster"<< endl;
        }
        void run ()  override {
            cout<< " I can run very fast"<<endl;
        }

        ~Dog(){
            cout<< "Dog has been distroyed"<<endl;
        }
};

// class Pitbul: public Dog { 
// //  // you can not inherate any more because of final keyword in Dog Class 
// };


class Cat: public Animal, public I_Hunt { 

    public: 
     Cat(){
        cout<< "Cat has been created"<< endl;
     }
    
     virtual void breath() override { 

        cout<<" meow meow i can breath as well"<<endl;
     }
        void run() override {
            cout<< " meow meow I can run but not that fast but i can climb a tree unlike dogs  "<< endl;
        }

      ~Cat(){
        cout << "Cat is being distructed"<< endl;
     }
};

int main(){

    Animal *mydoggy = new Dog();
    Animal *mykitten = new Cat(); 

    // Animal *myAnimal = new Animal(); I cannot do this because Animal class has become abstract
    // Abstract class cannot be create object from. 

    vector< Animal*> animals { mydoggy, mykitten};
    for (auto animal : animals)
    {
        animal->breath();
    }
    I_Hunt *mydoggyHunter= new Dog();
    I_Hunt *myCatHunter=new Cat();

    vector< I_Hunt*> cornivours {mydoggyHunter, myCatHunter};

    for (auto cornivoursAnimal : cornivours)
    {
        cornivoursAnimal->run();
    }
    
    
    delete mykitten;
    delete mydoggy;
    delete mydoggyHunter;
    delete myCatHunter;
    return 0; 
}