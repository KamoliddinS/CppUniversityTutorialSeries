# Parse lines

> **Goal:** split a line of text into its parts and turn the parts into numbers.

## One line

A data file often has one line for each student, with commas between the values:
`Malika,19,4.8`. There are no spaces, so `>>` would read the whole line as one word.
To **parse** a line means to split it into its parts and convert each part to the right type.

```text
the line        Malika,19,4.8
                   ↓  split at the commas
three texts     "Malika"   "19"   "4.8"
                   ↓  convert
three values    Malika      19     4.8        a std::string, an int, a double
```

**`split_line.cpp`**
<!-- file: split_line.cpp -->
```cpp
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line = "Malika,19,4.8";
    std::istringstream fields(line);        // a stream that reads from the string

    std::string name;
    std::string ageText;
    std::string gradeText;
    std::getline(fields, name, ',');        // read up to the next comma
    std::getline(fields, ageText, ',');
    std::getline(fields, gradeText);        // read the rest

    int age = std::stoi(ageText);           // text "19" becomes the number 19
    double grade = std::stod(gradeText);

    std::cout << name << " is " << age << ", next year " << age + 1 << '\n';
    std::cout << "Grade: " << grade << '\n';
}
```

<!-- output: split_line -->
```text
Malika is 19, next year 20
Grade: 4.8
```

- `std::istringstream` (from `<sstream>`) is a **string stream**: it works like a file
  stream, but it reads from a string. `>>` and `std::getline` work on it as on a file.
- With a third argument, `std::getline` reads up to that character, not to the end of the
  line. The comma itself is thrown away.
- Each part is still text. `std::stoi` makes an `int` of it, `std::stod` a `double`.

## A whole file

`students.csv` (comma-separated values) has one line without a grade:

**`students.csv`**
<!-- file: students.csv -->
```text
Malika,19,4.8
Aziz,20,4.5
Jasur,18
Dilnoza,19,4.2
```

**`read_students.cpp`**
<!-- file: read_students.cpp -->
```cpp
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int age = 0;
    double grade = 0.0;
};

int main() {
    std::ifstream in("students.csv");
    if (!in) {
        std::cout << "Cannot open students.csv\n";
        return 1;
    }

    std::vector<Student> students;
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream fields(line);
        Student student;
        std::string ageText;
        std::string gradeText;
        std::getline(fields, student.name, ',');
        std::getline(fields, ageText, ',');
        std::getline(fields, gradeText);
        if (fields) {                           // all three reads worked
            student.age = std::stoi(ageText);
            student.grade = std::stod(gradeText);
            students.push_back(student);
        } else {
            std::cout << "Skipped: " << line << '\n';
        }
    }

    for (const Student& s : students) {
        std::cout << s.name << ", " << s.age << ", grade " << s.grade << '\n';
    }
}
```

<!-- output: read_students -->
```text
Skipped: Jasur,18
Malika, 19, grade 4.8
Aziz, 20, grade 4.5
Dilnoza, 19, grade 4.2
```

- The loop reads the file line by line. Each line gets its own string stream.
- In the third line the last `std::getline` finds nothing to read. That puts `fields` in a
  failed state, like a file that did not open, so the line is reported and not stored.

## Watch out

- Three fields are not yet three good fields. `std::stoi("abc")` throws an *exception*
  ([chapter 13](../../13-exceptions/README.md)). Until you learn to catch it, the program
  stops with `terminate called after throwing an instance of 'std::invalid_argument'`.
- `std::stoi("19 years")` gives `19`, and `std::stoi("4.8")` gives `4`: the conversion stops
  at the first character that does not belong to the number.

## Try it

1. Predict the output:

   ```cpp
   std::istringstream words("Aziz 5 4 3");
   std::string name;
   int mark = 0;
   words >> name;
   while (words >> mark) {
       std::cout << name << " got " << mark << '\n';
   }
   ```

2. Add the line `Laziz;21;4.1` to `students.csv`. Is Laziz stored or skipped? Why?

<details>
<summary>Answers</summary>

1. Three lines: `Aziz got 5`, `Aziz got 4`, `Aziz got 3`. `>>` works on a string stream as
   on a file: first the name, then one number per round until the text is used up.
2. Skipped. The line has no comma, so the first `std::getline` takes all of it as the name,
   and the second one finds nothing to read.
</details>

**Next:** [Format output](../05-format-output/README.md)
