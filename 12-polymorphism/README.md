# 12 · Polymorphism

After this chapter one call can run different code, depending on the real type of the object.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Why virtual](01-why-virtual/README.md) | see the problem that virtual functions solve |
| 2 | [Virtual functions](02-virtual-functions/README.md) | let the object's real type decide which function runs |
| 3 | [Virtual destructors](03-virtual-destructors/README.md) | delete derived objects safely through a base pointer |
| 4 | [Abstract classes](04-abstract-classes/README.md) | say what a type must do without saying how |
| 5 | [Polymorphic collections](05-polymorphic-collections/README.md) | keep different kinds of objects in one container |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| polymorphism | one call runs different code for different kinds of object |
| real type | the type an object was created with, whatever the type of the pointer or reference to it |
| virtual function | a member function that derived classes may replace; the real type of the object decides which version runs |
| dynamic binding | choosing the function while the program runs, from the real type of the object |
| override | to replace a virtual function in a derived class; the word `override` makes the compiler check it |
| `final` | a word that forbids another override of a function, or deriving from a class |
| vtable | the hidden table of a class's virtual functions; each object of the class holds a pointer to it |
| virtual destructor | a destructor marked `virtual`, so that a delete through a base pointer destroys the whole object |
| pure virtual function | a virtual function marked `= 0`; derived classes must override it |
| abstract class | a class with at least one pure virtual function; you cannot create an object of it |
| interface | a class with only pure virtual functions and a virtual destructor |
| `dynamic_cast` | a conversion that checks the real type of an object while the program runs |
