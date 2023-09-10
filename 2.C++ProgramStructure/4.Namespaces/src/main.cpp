#include <iostream>

// Defining a namespace
namespace MyNamespace {
    int myVar = 10;

    void myFunction() {
        std::cout << "Function inside MyNamespace called!" << std::endl;
    }
}

// Nested namespaces
namespace Outer {
    namespace Inner {
        int innerVar = 20;
    }

    inline namespace InlineInner {
        int inlineVar = 40;
    }
}

// Anonymous namespace
namespace {
    int anonymousVar = 30;
}

int main() {
    // Accessing members using the scope resolution operator
    std::cout << "MyNamespace::myVar: " << MyNamespace::myVar << std::endl;
    MyNamespace::myFunction();

    // Accessing nested namespace members
    std::cout << "Outer::Inner::innerVar: " << Outer::Inner::innerVar << std::endl;

    // Accessing inline namespace members
    std::cout << "Outer::inlineVar: " << Outer::inlineVar << std::endl;

    // Accessing anonymous namespace members
    std::cout << "anonymousVar: " << anonymousVar << std::endl;

    return 0;
}
