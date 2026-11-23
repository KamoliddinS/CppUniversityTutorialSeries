# Structs

> **Goal:** keep the values that describe one thing together in a type of your own.

## Three lists that must stay in step

A student has a name, an age and a grade. Three vectors can store a group, but nothing ties
`names[0]` to `ages[0]`.

**`three_vectors.cpp`**
<!-- file: three_vectors.cpp -->
```cpp
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> names = {"Malika", "Aziz", "Jasur"};
    std::vector<int> ages = {19, 20, 18};
    std::vector<double> grades = {4.8, 4.5, 3.9};

    std::ranges::sort(names);   // only the names move

    for (std::size_t i = 0; i < names.size(); ++i) {
        std::cout << names[i] << ' ' << ages[i] << ' ' << grades[i] << '\n';
    }
}
```

<!-- output: three_vectors -->
```text
Aziz 19 4.8
Jasur 20 4.5
Malika 18 3.9
```

Malika is 19 and has the grade 4.8. After the sort, the program gives her Jasur's age and grade.

## One type for one thing

A **struct** is a type that you define. It groups several values, called its **members**,
under one name.

**`student.cpp`**
<!-- file: student.cpp -->
```cpp
#include <iostream>
#include <string>

struct Student {
    std::string name;       // a string is empty by itself
    int age = 0;            // default values: used when you give none
    double grade = 0.0;
};

int main() {
    Student aziz{"Aziz", 19, 4.5};      // values in the order of the members
    std::cout << aziz.name << " is " << aziz.age << '\n';

    aziz.age = 20;                      // change one member
    std::cout << aziz.name << " is " << aziz.age << '\n';

    Student nobody;                     // every member has its default value
    std::cout << '[' << nobody.name << "] " << nobody.age << ' ' << nobody.grade << '\n';
}
```

<!-- output: student -->
```text
Aziz is 19
Aziz is 20
[] 0 0
```

- The definition ends with `};` and stands above the functions that use it.
- `aziz.age` is one member. With the dot you read it or change it.
- A member can have any type, also a `std::vector` or another struct.
- Give the members default values. Without `= 0`, `nobody.age` would hold garbage, like a
  plain `int age;`, and reading it would be undefined behaviour.

## A vector of structs

One vector can hold whole students:

```text
three vectors:   names    Malika   Aziz     Jasur
                 ages     19       20       18
                 grades   4.8      4.5      3.9

one vector:      ┌────────┬────────┬────────┐
                 │ Malika │ Aziz   │ Jasur  │
                 │ 19     │ 20     │ 18     │    each box is one Student
                 │ 4.8    │ 4.5    │ 3.9    │
                 └────────┴────────┴────────┘
```

**`group.cpp`**
<!-- file: group.cpp -->
```cpp
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int age = 0;
    double grade = 0.0;
};

void print(const Student& student) {
    std::cout << student.name << " (" << student.age << "): " << student.grade << '\n';
}

int main() {
    std::vector<Student> group = {{"Malika", 19, 4.8}, {"Aziz", 20, 4.5}};
    group.push_back({"Jasur", 18, 3.9});

    for (const Student& student : group) {
        print(student);
    }
    std::cout << "First in the list: " << group[0].name << '\n';
}
```

<!-- output: group -->
```text
Malika (19): 4.8
Aziz (20): 4.5
Jasur (18): 3.9
First in the list: Malika
```

- A `Student` is one element of the vector. Its name, age and grade cannot get out of step.
- In the list and in `push_back`, each inner `{...}` makes one `Student`.
- Pass a struct like a string, by `const Student&`: nothing is copied, and the function
  cannot change it ([Const references](../../04-functions/04-const-references/README.md)).

## Watch out

- `std::cout << aziz` and `aziz == malika` do not compile: `no match for 'operator<<'`,
  `no match for 'operator=='`. C++ does not know how to print or compare a `Student` until
  you say how ([chapter 8](../../08-operator-overloading/README.md)). Until then, print and
  compare the members.
- `Student.age = 20;` does not compile. `Student` is the type. The dot needs a variable,
  such as `aziz`.

## Try it

1. Predict the output:

   ```cpp
   Student a{"Laziz", 21, 3.5};
   Student b = a;
   b.age = 30;
   std::cout << a.age << ' ' << b.age << '\n';
   ```

2. In `group.cpp`, add the member `std::string city = "Tashkent";` to `Student` and print it
   in `print`. Then give Jasur the city Samarkand.

<details>
<summary>Answers</summary>

1. `21 30`. `Student b = a;` copies every member. `b` is a separate student, so changing it
   does not change `a`.
2. Add the line to the struct, and `<< ", " << student.city` to `print`. Malika and Aziz get
   the default. Jasur becomes `{"Jasur", 18, 3.9, "Samarkand"}`.
</details>

**Next:** [Enums](../02-enums/README.md)
