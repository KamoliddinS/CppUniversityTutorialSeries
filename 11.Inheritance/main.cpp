#include <iostream>

class Animal {
    private:
        int weight;
        int height;
    
    public:
        Animal(int weight = 0, int height = 0) : weight(weight), height(height) {}
        virtual int getWeight() const { return weight; }
        int getHeight() const { return height; }
        void setWeight(int weight) { this->weight = weight; }
        void setHeight(int height) { this->height = height; }
};

class Dog : public Animal { 
        private:
        std::string name;
    
    public:
        Dog(std::string name = "", int weight = 0, int height = 0) : Animal(weight, height), name(name) {}
        std::string getName() const { return name; }

        int getWeight() const override{ return Animal::getWeight(); }
};