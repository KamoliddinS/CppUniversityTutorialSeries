# 11 · Inheritance

After this chapter you can build a new class on top of an existing one, and you know when not to.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Has-a or is-a](01-has-a-or-is-a/README.md) | choose between composition and inheritance |
| 2 | [Derive a class](02-derive-a-class/README.md) | write a derived class and know which base members it may use |
| 3 | [Constructors in a hierarchy](03-constructors-in-a-hierarchy/README.md) | pass arguments to the base constructor, and know the order of construction and destruction |
| 4 | [Redefine a function](04-redefine-a-function/README.md) | replace a base function, still call the original, and predict which version runs |
| 5 | [Multiple inheritance](05-multiple-inheritance/README.md) | inherit from two classes and solve the diamond problem |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| composition | building a class from members of other classes: a car has an engine |
| inheritance | building a class on top of another one: the new class gets the members of the old class and adds its own |
| base class | the class that another class inherits from, such as `Person` |
| derived class | the class that inherits, such as `Student` |
| base part | the part of a derived object that holds the members of the base class |
| `protected` | an access level: for the class itself and for its derived classes, not for code outside |
| hide | a function in a derived class hides every function of the base class that has the same name |
| static binding | the compiler chooses the function while it builds the program, from the type of the variable, reference or pointer |
| slicing | copying a derived object into a base variable copies only the base part |
| multiple inheritance | a class with more than one base class |
| diamond problem | two base classes share a base class, so the object contains that class twice |
| virtual inheritance | `class Student : virtual public Person`: all base classes that say this share one `Person` part |
