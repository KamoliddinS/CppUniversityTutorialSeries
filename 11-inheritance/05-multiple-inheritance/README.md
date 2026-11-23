# Multiple inheritance

> **Goal:** inherit from two classes, and repair the calls that become ambiguous.

## Two base classes

A teaching assistant is a student and an employee. A class may have several base classes.
This is **multiple inheritance**:

**`two_bases_nocompile.cpp`**
<!-- file: two_bases_nocompile.cpp -->
```cpp
#include <iostream>

class Student {
public:
    int id() const { return 1042; }     // student id
};

class Employee {
public:
    int id() const { return 77; }       // staff id
};

class TeachingAssistant : public Student, public Employee {};

int main() {
    TeachingAssistant aziz;
    std::cout << aziz.id() << '\n';
}
```

<!-- errors: two_bases_nocompile -->
```text
two_bases_nocompile.cpp: In function ‘int main()’:
two_bases_nocompile.cpp:17:23: error: request for member ‘id’ is ambiguous
   17 |     std::cout << aziz.id() << '\n';
      |                       ^~
two_bases_nocompile.cpp:10:9: note: candidates are: ‘int Employee::id() const’
   10 |     int id() const { return 77; }       // staff id
      |         ^~
two_bases_nocompile.cpp:5:9: note:                 ‘int Student::id() const’
    5 |     int id() const { return 1042; }     // student id
      |         ^~
```

"Ambiguous" means: the call has two possible meanings. `TeachingAssistant` inherited two
functions named `id`, and the compiler does not choose for you. Say which one you mean:
`aziz.Student::id()` or `aziz.Employee::id()`.

## The diamond

In this chapter a student is a person. An employee is a person too. Read each arrow as "is a":

```text
            Person
           ↗      ↖
     Student      Employee
           ↖      ↗
      TeachingAssistant
```

**`diamond_nocompile.cpp`**
<!-- file: diamond_nocompile.cpp -->
```cpp
#include <iostream>
#include <string>

class Person {
public:
    explicit Person(const std::string& name) : name_(name) {
        std::cout << "Person(" << name_ << ")\n";
    }
    const std::string& name() const { return name_; }

private:
    std::string name_;
};

class Student : public Person {
public:
    explicit Student(const std::string& name) : Person(name) {}
};

class Employee : public Person {
public:
    explicit Employee(const std::string& name) : Person(name) {}
};

class TeachingAssistant : public Student, public Employee {
public:
    explicit TeachingAssistant(const std::string& name) : Student(name), Employee(name) {}
};

int main() {
    TeachingAssistant aziz("Aziz");
    std::cout << aziz.name() << '\n';
}
```

<!-- errors: diamond_nocompile -->
```text
diamond_nocompile.cpp: In function ‘int main()’:
diamond_nocompile.cpp:32:23: error: request for member ‘name’ is ambiguous
   32 |     std::cout << aziz.name() << '\n';
      |                       ^~~~
diamond_nocompile.cpp:9:24: note: candidates are: ‘const std::string& Person::name() const’
    9 |     const std::string& name() const { return name_; }
      |                        ^~~~
diamond_nocompile.cpp:9:24: note:                 ‘const std::string& Person::name() const’
```

`aziz` contains **two** `Person` parts, one inside each base. `aziz.name()` could read
either of them. This is the **diamond problem**.

| Name | Address | Value |
|------|---------|-------|
| `name_` of the `Person` part inside `Student` | `0x1000` | `"Aziz"` |
| `name_` of the `Person` part inside `Employee` | `0x1020` | `"Aziz"` |

## One shared Person part

The repair changes three lines:

<!-- snippet: diamond.cpp -->
```cpp
class Student : virtual public Person {
public:
    explicit Student(const std::string& name) : Person(name) {}
};

class Employee : virtual public Person {
public:
    explicit Employee(const std::string& name) : Person(name) {}
};

class TeachingAssistant : public Student, public Employee {
public:
    explicit TeachingAssistant(const std::string& name)
        : Person(name), Student(name), Employee(name) {}    // builds the shared Person part
};
```

<!-- output: diamond -->
```text
Person(Aziz)
Aziz
```

- `virtual public Person` means: share one `Person` part with every other base that says
  the same. This is **virtual inheritance**. `Person(Aziz)` is printed only once.
- The shared part is built by the class of the whole object, here `TeachingAssistant`. It
  must name `Person(name)` itself. The `Person(name)` in `Student` and in `Employee` is
  skipped for this object.

## Watch out

- Both `Student` and `Employee` need the word `virtual`. With only one, `aziz` still has
  two `Person` parts.
- Keep to one base class that has data. Chapter 12 shows the safe use of several bases:
  [interfaces](../../12-polymorphism/04-abstract-classes/README.md).
- Chapter 12 also uses the word `virtual` for functions. That is a different feature.

## Try it

1. Repair `two_bases_nocompile.cpp` so that it prints both ids.
2. In `diamond.cpp`, delete both `virtual` words and `Person(name), `, and print
   `aziz.Student::name()`. Predict how often `Person(Aziz)` appears.

<details>
<summary>Answers</summary>

1. `std::cout << aziz.Student::id() << ' ' << aziz.Employee::id() << '\n';` prints `1042 77`.
2. Twice. `Student` and `Employee` each build their own `Person` part again.
   `aziz.Student::name()` compiles, because it says which part to read.
</details>

**Next:** [Exercises for this chapter](../exercises/README.md)
