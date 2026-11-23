#include <iostream>
#include <string>

class Person {
public:
    const std::string& name() const { return name_; }

protected:
    void setName(const std::string& name) { name_ = name; }

private:
    std::string name_ = "no name";
};

class Student : public Person {
public:
    void enrol(const std::string& name, int id) {
        setName(name);      // protected in Person: a Student may call it
        id_ = id;
    }
    int id() const { return id_; }

private:
    int id_ = 0;
};

int main() {
    Student malika;
    malika.enrol("Malika", 1042);
    std::cout << malika.name() << ' ' << malika.id() << '\n';   // name() comes from Person
}
