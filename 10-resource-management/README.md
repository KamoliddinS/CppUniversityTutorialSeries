# 10 · Resource management

After this chapter your classes clean up after themselves and copy correctly, and you rarely need `new` and `delete`.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [RAII](01-raii/README.md) | release a resource automatically in the destructor |
| 2 | [Copying objects](02-copying-objects/README.md) | copy a class that owns memory without sharing it by accident |
| 3 | [Moving objects](03-moving-objects/README.md) | hand over a resource instead of copying it |
| 4 | [The rule of zero](04-rule-of-zero/README.md) | let `std::vector` and `std::string` do the work, and forbid copies with `= delete` |
| 5 | [unique_ptr](05-unique-ptr/README.md) | own a heap object without writing `delete` |
| 6 | [shared_ptr and weak_ptr](06-shared-ptr-and-weak-ptr/README.md) | share an object between several owners without a leak |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| resource | anything a program must give back after use, such as heap memory or an open file |
| RAII | the pattern in which the constructor takes a resource and the destructor gives it back |
| memberwise copy | a copy that gives each member the value of the same member of the other object |
| copy constructor | the constructor that builds a new object from an existing one: `T(const T& other)` |
| copy assignment operator | the `operator=` that gives an existing object the value of another one |
| rule of three | a class that needs a destructor, a copy constructor or a copy assignment operator needs all three |
| move | take over the resource of another object and leave that object empty, instead of copying |
| temporary | an object without a name that disappears at the end of the statement, such as a returned value |
| rule of five | the rule of three plus the move constructor and the move assignment operator |
| rule of zero | let the members own the resources, and write none of the five functions |
| smart pointer | an object that owns a heap object and deletes it automatically |
| reference count | the number of `shared_ptr`s that own the same object |
