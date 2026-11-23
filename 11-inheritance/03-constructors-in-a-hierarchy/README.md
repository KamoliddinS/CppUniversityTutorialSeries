# Constructors in a hierarchy

> **Goal:** pass arguments to the base constructor, and say in which order an object is built and destroyed.

## The base part is built first

A base class and the classes derived from it form a hierarchy. Here `Person` has a
constructor that needs a name. `Student` passes the name on in its member initialiser
list: `: Person(name)`.

**`order.cpp`**
<!-- file: order.cpp -->
```cpp
#include <iostream>
#include <string>

class Person {
public:
    explicit Person(const std::string& name) : name_(name) {
        std::cout << "Person(" << name_ << ")\n";
    }
    ~Person() { std::cout << "~Person(" << name_ << ")\n"; }

private:
    std::string name_;
};

class Laptop {
public:
    Laptop() { std::cout << "Laptop()\n"; }
    ~Laptop() { std::cout << "~Laptop()\n"; }
};

class Student : public Person {
public:
    Student(const std::string& name, int id) : Person(name), id_(id) {
        std::cout << "Student(" << id_ << ")\n";
    }
    ~Student() { std::cout << "~Student(" << id_ << ")\n"; }

private:
    Laptop laptop_;
    int id_ = 0;
};

int main() {
    Student malika("Malika", 1042);
    std::cout << "--- end of main ---\n";
}
```

<!-- output: order -->
```text
Person(Malika)
Laptop()
Student(1042)
--- end of main ---
~Student(1042)
~Laptop()
~Person(Malika)
```

You know the order for members from
[Destructors and lifetime](../../07-classes/03-destructors-and-lifetime/README.md).
The base part comes before them:

1. the base part: `Person(name)`;
2. the members, in the order of their declarations: `laptop_`, then `id_`;
3. the body of the `Student` constructor.

Destruction runs in exactly the reverse order.

## Name the base constructor

This constructor of `Student` forgets the `Person` part:

<!-- snippet: no_default_nocompile.cpp -->
```cpp
    explicit Student(int id) : id_(id) {}       // no base constructor is named
```

<!-- errors: no_default_nocompile -->
```text
no_default_nocompile.cpp: In constructor ‘Student::Student(int)’:
no_default_nocompile.cpp:15:38: error: no matching function for call to ‘Person::Person()’
   15 |     explicit Student(int id) : id_(id) {}       // no base constructor is named
      |                                      ^
no_default_nocompile.cpp:6:14: note: candidate: ‘Person::Person(const std::string&)’
    6 |     explicit Person(const std::string& name) : name_(name) {}
      |              ^~~~~~
no_default_nocompile.cpp:6:14: note:   candidate expects 1 argument, 0 provided
no_default_nocompile.cpp:4:7: note: candidate: ‘constexpr Person::Person(const Person&)’
    4 | class Person {
      |       ^~~~~~
no_default_nocompile.cpp:4:7: note:   candidate expects 1 argument, 0 provided
no_default_nocompile.cpp:4:7: note: candidate: ‘constexpr Person::Person(Person&&)’
no_default_nocompile.cpp:4:7: note:   candidate expects 1 argument, 0 provided
```

When the list names no base constructor, the compiler uses the default constructor
`Person()`. `Person` has none: that is the first `error` line. The fix is the list of
`order.cpp`: `: Person(name), id_(id)`.

## Constructors are not inherited

A derived class does not get the constructors of its base class. It can ask for them:

<!-- snippet: guest.cpp -->
```cpp
class Guest : public Person {
public:
    using Person::Person;       // take over the constructors of Person
    void visit() const { std::cout << name() << " visits the campus\n"; }
};

int main() {
    Guest laziz("Laziz");       // uses the constructor of Person
    Guest copy = laziz;         // the generated copy constructor copies the Person part too
    copy.visit();
}
```

<!-- output: guest -->
```text
Laziz visits the campus
```

- Without the `using` line, `Guest laziz("Laziz");` does not compile. Use the line when the
  derived class adds no member that needs a value.
- The copy constructor and the copy assignment operator that the compiler generates copy
  the base part too.

## Watch out

- `: id_(id), Person(name)` still builds the `Person` part first, and the compiler warns.
  Write the base first.
- `: name_(name)` is an error in `Student`. A constructor initialises its base class and its
  own members, not the members of the base.
- If you write a copy constructor for `Student` yourself, start its list with
  `Person(other)`, so that the `Person` part is copied too.

## Try it

Add a class `GraduateStudent`, derived from `Student`, to `order.cpp`. Its constructor prints
`GraduateStudent()` and its destructor prints `~GraduateStudent()`. Create a `GraduateStudent`
in `main` instead of the `Student`. Predict the output, then run it.

<details>
<summary>Answer</summary>

The constructor passes both arguments up one level:
`GraduateStudent(const std::string& name, int id) : Student(name, id) { ... }`

```text
Person(Malika)
Laptop()
Student(1042)
GraduateStudent()
--- end of main ---
~GraduateStudent()
~Student(1042)
~Laptop()
~Person(Malika)
```
</details>

**Next:** [Redefine a function](../04-redefine-a-function/README.md)
