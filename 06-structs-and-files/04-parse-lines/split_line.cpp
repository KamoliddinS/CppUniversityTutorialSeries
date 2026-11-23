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
