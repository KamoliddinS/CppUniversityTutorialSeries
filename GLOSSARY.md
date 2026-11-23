# Glossary

Every key term from the chapters, in one place. This page is generated from the
"Key terms" tables: edit those, then run `python3 tools/check.py --fix`.

| Term | Meaning | Chapter |
|------|---------|---------|
| abstract class | a class with at least one pure virtual function; you cannot create an object of it | [12 · Polymorphism](12-polymorphism/README.md) |
| acceptance criteria | the list of things that must be true before a piece of work counts as done | [Projects](projects/README.md) |
| adaptor | a wrapper around a container that allows only one way in and one way out, such as `std::stack` | [15 · The standard library](15-standard-library/README.md) |
| address | the number of the place in memory where a variable lives | [09 · Pointers and memory](09-pointers-and-memory/README.md) |
| algorithm | a ready-made function of the standard library that works on a list, such as `std::ranges::sort` | [05 · Vectors and strings](05-vectors-and-strings/README.md) |
| argument | a value written in a call; it goes into the parameter at the same position | [04 · Functions](04-functions/README.md) |
| array | a list with a fixed number of elements (`std::array`, or the built-in `int a[5]`) | [05 · Vectors and strings](05-vectors-and-strings/README.md) |
| assignment | replacing the value of an existing variable with `=` | [02 · Values and types](02-values-and-types/README.md) |
| base case | the case that a recursive function answers without calling itself | [04 · Functions](04-functions/README.md) |
| base class | the class that another class inherits from, such as `Person` | [11 · Inheritance](11-inheritance/README.md) |
| base part | the part of a derived object that holds the members of the base class | [11 · Inheritance](11-inheritance/README.md) |
| binary | the number system with two digits, `0` and `1` | [Appendix](appendix/README.md) |
| bit | one binary digit: `0` or `1` | [Appendix](appendix/README.md) |
| borrow | a reference to a value that someone else owns: `&T` to read it, `&mut T` to change it | [16 · Rust for C++ programmers](16-rust-for-cpp-programmers/README.md) |
| breakpoint | a line where the debugger stops the program | [01 · First programs](01-first-programs/README.md) |
| build | compile and link: make a program from source files | [01 · First programs](01-first-programs/README.md) |
| build system | a tool that keeps the build commands in a file and compiles only what changed, such as Make or CMake | [Appendix](appendix/README.md) |
| capacity | how many elements fit in the block of memory that a vector has now | [15 · The standard library](15-standard-library/README.md) |
| capture | an outside variable that a lambda may use: `[x]` is a copy, `[&x]` is the variable itself | [15 · The standard library](15-standard-library/README.md) |
| Cargo | Rust's tool that creates, builds, runs and tests a project | [16 · Rust for C++ programmers](16-rust-for-cpp-programmers/README.md) |
| cast | a conversion you ask for, such as `static_cast<double>(x)` | [02 · Values and types](02-values-and-types/README.md) |
| chaining | using the result of one operator as the left operand of the next, as in `std::cout << a << b` | [08 · Operator overloading](08-operator-overloading/README.md) |
| class | a type you define that holds data together with the functions that work on it | [07 · Classes](07-classes/README.md) |
| class template | a pattern for classes with a type left open, such as `std::vector` | [14 · Templates](14-templates/README.md) |
| clone | your own copy of a repository, on your computer | [00 · Getting started](00-getting-started/README.md) |
| closure | a function without a name that can use the variables around it; Rust's lambda | [16 · Rust for C++ programmers](16-rust-for-cpp-programmers/README.md) |
| CMake | a tool that builds many programs with one command; the course uses it to check your exercises | [00 · Getting started](00-getting-started/README.md) |
| command | one line of input that tells a program what to do, such as `add Aziz 85` | [Projects](projects/README.md) |
| command-line argument | a word typed after the program's name when the program is started | [06 · Structs and files](06-structs-and-files/README.md) |
| commit | one saved version of your files, with a message | [00 · Getting started](00-getting-started/README.md) |
| compile error | the code breaks a rule of the language, so no program is made | [01 · First programs](01-first-programs/README.md) |
| compiler | the tool that checks source code and translates it to machine code (`g++`) | [01 · First programs](01-first-programs/README.md) |
| composition | building a class from members of other classes: a car has an engine | [11 · Inheritance](11-inheritance/README.md) |
| condition | a value that is `true` or `false`; `if` and loops test it to decide what to do | [03 · Control flow](03-control-flow/README.md) |
| const member function | a member function that promises not to change the object; the only kind a const object can call | [07 · Classes](07-classes/README.md) |
| constant | a variable whose value cannot change after it is set (`const` or `constexpr`) | [02 · Values and types](02-values-and-types/README.md) |
| constructor | the member function that runs automatically when an object is created and gives the members their first values | [07 · Classes](07-classes/README.md) |
| container | an object that holds many elements, such as `std::vector` or `std::map` | [15 · The standard library](15-standard-library/README.md) |
| conversion | making a value of one type from a value of another type | [02 · Values and types](02-values-and-types/README.md) |
| copy assignment operator | the `operator=` that gives an existing object the value of another one | [10 · Resource management](10-resource-management/README.md) |
| copy constructor | the constructor that builds a new object from an existing one: `T(const T& other)` | [10 · Resource management](10-resource-management/README.md) |
| copyleft | a licence condition: what you build with the code may only be shared under the same licence | [Appendix](appendix/README.md) |
| copyright | the author's right to decide who may copy, change and share a work | [Appendix](appendix/README.md) |
| current folder | the folder a terminal is in; commands work on it | [00 · Getting started](00-getting-started/README.md) |
| dangling pointer | a pointer that holds the address of an object that no longer exists | [09 · Pointers and memory](09-pointers-and-memory/README.md) |
| decay | an array name turning into a pointer to its first element | [09 · Pointers and memory](09-pointers-and-memory/README.md) |
| declaration | the first line of a function followed by `;`; it says that the function exists | [04 · Functions](04-functions/README.md) |
| deduction | the compiler works out a template parameter from the arguments of a call | [14 · Templates](14-templates/README.md) |
| default constructor | a constructor that can be called without arguments | [07 · Classes](07-classes/README.md) |
| defaulted | written by the compiler because the declaration ends with `= default` | [08 · Operator overloading](08-operator-overloading/README.md) |
| definition | the function with its body; it says what the function does | [04 · Functions](04-functions/README.md) |
| dereference | follow a pointer to the variable it points to: `*p` | [09 · Pointers and memory](09-pointers-and-memory/README.md) |
| derived class | the class that inherits, such as `Student` | [11 · Inheritance](11-inheritance/README.md) |
| destructor | the member function `~Name()` that runs automatically when an object's life ends | [07 · Classes](07-classes/README.md) |
| diamond problem | two base classes share a base class, so the object contains that class twice | [11 · Inheritance](11-inheritance/README.md) |
| drop | the clean-up that runs when the owner of a value goes out of scope; Rust's destructor | [16 · Rust for C++ programmers](16-rust-for-cpp-programmers/README.md) |
| dynamic binding | choosing the function while the program runs, from the real type of the object | [12 · Polymorphism](12-polymorphism/README.md) |
| `dynamic_cast` | a conversion that checks the real type of an object while the program runs | [12 · Polymorphism](12-polymorphism/README.md) |
| element | one of the values in a vector, an array or a string | [05 · Vectors and strings](05-vectors-and-strings/README.md) |
| endless loop | a loop whose condition never becomes false, so it never stops | [03 · Control flow](03-control-flow/README.md) |
| enum | a type whose only values are the names you list, such as `Level::beginner` | [06 · Structs and files](06-structs-and-files/README.md) |
| exception | an object that describes a problem; a function throws it when it cannot do its job | [13 · Exceptions](13-exceptions/README.md) |
| exit code | the number `main` returns to the system; 0 means success | [06 · Structs and files](06-structs-and-files/README.md) |
| failed state | the state of `std::cin` after a read that did not work; every later read fails until `clear()` is called | [03 · Control flow](03-control-flow/README.md) |
| fall-through | in a `switch`, running on into the next case because a `break` is missing | [03 · Control flow](03-control-flow/README.md) |
| file stream | a variable connected to a file; you read from it with `>>` and write to it with `<<` | [06 · Structs and files](06-structs-and-files/README.md) |
| `final` | a word that forbids another override of a function, or deriving from a class | [12 · Polymorphism](12-polymorphism/README.md) |
| flag | a `bool` variable that remembers whether something has happened | [03 · Control flow](03-control-flow/README.md) |
| fork | your own copy of someone else's repository, on GitHub | [00 · Getting started](00-getting-started/README.md) |
| friend | a function or class that a class allows to use its private members | [07 · Classes](07-classes/README.md) |
| function | a named block of code that does one job | [04 · Functions](04-functions/README.md) |
| function pointer | a pointer that holds the address of a function | [09 · Pointers and memory](09-pointers-and-memory/README.md) |
| function template | a pattern for functions: the body is written once and the type is left open | [14 · Templates](14-templates/README.md) |
| Git | a program that records versions of the files in a folder | [00 · Getting started](00-getting-started/README.md) |
| GitHub | a website that stores repositories, so that people can share them | [00 · Getting started](00-getting-started/README.md) |
| grid | a table of values with rows and columns, stored as a vector of vectors | [05 · Vectors and strings](05-vectors-and-strings/README.md) |
| handler | a `catch` block: the code that runs when an exception of its type arrives | [13 · Exceptions](13-exceptions/README.md) |
| header file | a file such as `account.h` with the declarations that other files bring in with `#include` | [07 · Classes](07-classes/README.md) |
| heap | the memory for objects created with `new`; they live until `delete` | [09 · Pointers and memory](09-pointers-and-memory/README.md) |
| hexadecimal | the number system with sixteen digits, `0` to `9` and `A` to `F`; one digit stands for four bits | [Appendix](appendix/README.md) |
| hide | a function in a derived class hides every function of the base class that has the same name | [11 · Inheritance](11-inheritance/README.md) |
| index | the position of an element; the first element has index 0 | [05 · Vectors and strings](05-vectors-and-strings/README.md) |
| inheritance | building a class on top of another one: the new class gets the members of the old class and adds its own | [11 · Inheritance](11-inheritance/README.md) |
| initialise | give a variable its first value in the line that creates it | [02 · Values and types](02-values-and-types/README.md) |
| instantiation | the compiler writes a real function or class from a template, for one type | [14 · Templates](14-templates/README.md) |
| integer division | dividing two whole numbers: the fraction is cut off | [02 · Values and types](02-values-and-types/README.md) |
| interface | a class with only pure virtual functions and a virtual destructor | [12 · Polymorphism](12-polymorphism/README.md) |
| interpreter | a program that reads source code and carries it out step by step, as Python does | [Appendix](appendix/README.md) |
| invariant | a condition that is always true for a valid object, such as "the balance is never negative" | [07 · Classes](07-classes/README.md) |
| iteration | one run of the block of a loop; one round | [03 · Control flow](03-control-flow/README.md) |
| iterator | a value that marks a position in a container | [15 · The standard library](15-standard-library/README.md) |
| key | the value by which a map finds an entry, for example a name | [15 · The standard library](15-standard-library/README.md) |
| lambda | a small function without a name, written where it is used | [15 · The standard library](15-standard-library/README.md) |
| licence | a text in which the author says what everyone may do with a work, and under which conditions | [Appendix](appendix/README.md) |
| lifetime | the time during which a variable exists | [04 · Functions](04-functions/README.md) |
| lifetime annotation | a name such as `'a` in a signature; it tells the compiler how long a returned reference stays valid | [16 · Rust for C++ programmers](16-rust-for-cpp-programmers/README.md) |
| linker | the tool that joins compiled pieces into one program | [01 · First programs](01-first-programs/README.md) |
| linker error | a promised piece of code cannot be found, so no program is made | [01 · First programs](01-first-programs/README.md) |
| logic error | the program runs but gives the wrong result | [01 · First programs](01-first-programs/README.md) |
| loop | a statement that repeats a block of code | [03 · Control flow](03-control-flow/README.md) |
| magic number | a number in the code whose meaning the reader has to guess | [02 · Values and types](02-values-and-types/README.md) |
| manipulator | something you send to `std::cout` or a file stream to change how the next values are printed, such as `std::setw(10)` | [06 · Structs and files](06-structs-and-files/README.md) |
| map | a container that stores a value for each key (`std::map`) | [15 · The standard library](15-standard-library/README.md) |
| member | one of the values inside a struct; you reach it with a dot, as in `student.age` | [06 · Structs and files](06-structs-and-files/README.md) |
| member function | a function that belongs to a class and is called on an object: `account.deposit(500)` | [07 · Classes](07-classes/README.md) |
| memberwise copy | a copy that gives each member the value of the same member of the other object | [10 · Resource management](10-resource-management/README.md) |
| memory leak | heap memory that is never given back | [09 · Pointers and memory](09-pointers-and-memory/README.md) |
| move | take over the resource of another object and leave that object empty, instead of copying | [10 · Resource management](10-resource-management/README.md) |
| move (in Rust) | giving a value to a new owner; the old variable cannot be used any more | [16 · Rust for C++ programmers](16-rust-for-cpp-programmers/README.md) |
| multiple inheritance | a class with more than one base class | [11 · Inheritance](11-inheritance/README.md) |
| namespace | a named group of names; `std` is the namespace of the standard library | [Appendix](appendix/README.md) |
| narrowing | a conversion that can lose information, such as `double` to `int` | [02 · Values and types](02-values-and-types/README.md) |
| nested | placed inside a statement of the same kind: an `if` inside an `if`, a loop inside a loop | [03 · Control flow](03-control-flow/README.md) |
| `noexcept` | a promise that no exception leaves a function; breaking it ends the program | [13 · Exceptions](13-exceptions/README.md) |
| non-member function | an ordinary function that is not part of a class | [08 · Operator overloading](08-operator-overloading/README.md) |
| null pointer | a pointer that points to nothing; its value is `nullptr` | [09 · Pointers and memory](09-pointers-and-memory/README.md) |
| object | a variable whose type is a class | [07 · Classes](07-classes/README.md) |
| off-by-one error | a loop that runs one round too many or one too few | [03 · Control flow](03-control-flow/README.md) |
| open source | source code with a licence that lets everyone use, change and share it | [Appendix](appendix/README.md) |
| operand | a value that an operator works on: `a` and `b` in `a + b` | [08 · Operator overloading](08-operator-overloading/README.md) |
| operator overloading | writing a function that says what an operator does for your own type | [08 · Operator overloading](08-operator-overloading/README.md) |
| optimise | make a program faster without changing its result; `-O2` asks the compiler to do it | [Appendix](appendix/README.md) |
| `Option` | a value that may be missing: `Some(value)` or `None`; Rust has no null | [16 · Rust for C++ programmers](16-rust-for-cpp-programmers/README.md) |
| overflow | a result that does not fit in its type; undefined behaviour for an `int` | [02 · Values and types](02-values-and-types/README.md) |
| overloading | giving several functions the same name; their parameter lists must differ | [04 · Functions](04-functions/README.md) |
| override | to replace a virtual function in a derived class; the word `override` makes the compiler check it | [12 · Polymorphism](12-polymorphism/README.md) |
| owner | the part of the program that must delete a heap object, exactly once | [09 · Pointers and memory](09-pointers-and-memory/README.md) |
| ownership | the rule that every Rust value has exactly one owner and is destroyed when that owner goes out of scope | [16 · Rust for C++ programmers](16-rust-for-cpp-programmers/README.md) |
| panic | the program stops with a message, because of a bug | [16 · Rust for C++ programmers](16-rust-for-cpp-programmers/README.md) |
| parameter | a variable in the first line of a function; it gets its value from the call | [04 · Functions](04-functions/README.md) |
| parse | split text into its parts and convert each part to the right type | [06 · Structs and files](06-structs-and-files/README.md) |
| pass by value | the parameter is a copy of the argument, so the function cannot change the caller's variable | [04 · Functions](04-functions/README.md) |
| `PATH` | the list of folders where the system looks for a program when you type its name | [00 · Getting started](00-getting-started/README.md) |
| path | the name of a file together with the folders that lead to it | [00 · Getting started](00-getting-started/README.md) |
| pointer | a variable that holds an address | [09 · Pointers and memory](09-pointers-and-memory/README.md) |
| pointer to const | a pointer that cannot be used to change its target: `const int* p` | [09 · Pointers and memory](09-pointers-and-memory/README.md) |
| polymorphism | one call runs different code for different kinds of object | [12 · Polymorphism](12-polymorphism/README.md) |
| predicate | a function that answers `true` or `false` about an element | [15 · The standard library](15-standard-library/README.md) |
| prefix, postfix | the two forms of `++` and `--`: before the operand (`++x`) or after it (`x++`) | [08 · Operator overloading](08-operator-overloading/README.md) |
| private | usable only inside the class's own functions; `public` members are usable by all code | [07 · Classes](07-classes/README.md) |
| `protected` | an access level: for the class itself and for its derived classes, not for code outside | [11 · Inheritance](11-inheritance/README.md) |
| pull request | a request to the owner of a repository to take your change | [00 · Getting started](00-getting-started/README.md) |
| pure virtual function | a virtual function marked `= 0`; derived classes must override it | [12 · Polymorphism](12-polymorphism/README.md) |
| RAII | the pattern in which the constructor takes a resource and the destructor gives it back | [10 · Resource management](10-resource-management/README.md) |
| range | the elements from one iterator up to, but not including, another | [15 · The standard library](15-standard-library/README.md) |
| range-based `for` | a loop that gives you the elements one by one: `for (int x : v)` | [05 · Vectors and strings](05-vectors-and-strings/README.md) |
| real type | the type an object was created with, whatever the type of the pointer or reference to it | [12 · Polymorphism](12-polymorphism/README.md) |
| recursion | solving a problem with a function that calls itself | [04 · Functions](04-functions/README.md) |
| reference | another name for an existing variable; a parameter written with `&` is one | [04 · Functions](04-functions/README.md) |
| reference count | the number of `shared_ptr`s that own the same object | [10 · Resource management](10-resource-management/README.md) |
| repository | a folder whose versions Git records | [00 · Getting started](00-getting-started/README.md) |
| resource | anything a program must give back after use, such as heap memory or an open file | [10 · Resource management](10-resource-management/README.md) |
| `Result` | what a function that can fail returns: `Ok(value)` or `Err(error)` | [16 · Rust for C++ programmers](16-rust-for-cpp-programmers/README.md) |
| rethrow | pass the exception that a handler caught on to the next handler, with `throw;` | [13 · Exceptions](13-exceptions/README.md) |
| rule of five | the rule of three plus the move constructor and the move assignment operator | [10 · Resource management](10-resource-management/README.md) |
| rule of three | a class that needs a destructor, a copy constructor or a copy assignment operator needs all three | [10 · Resource management](10-resource-management/README.md) |
| rule of zero | let the members own the resources, and write none of the five functions | [10 · Resource management](10-resource-management/README.md) |
| scope | the part of the code where a name can be used | [04 · Functions](04-functions/README.md) |
| sentinel | a special input value that marks the end of the data, such as `0` | [03 · Control flow](03-control-flow/README.md) |
| set | a container that stores each value once (`std::set`) | [15 · The standard library](15-standard-library/README.md) |
| short-circuit evaluation | the right side of `&&` (and of the or operator) does not run when the left side already decides the result | [03 · Control flow](03-control-flow/README.md) |
| slicing | copying a derived object into a base variable copies only the base part | [11 · Inheritance](11-inheritance/README.md) |
| smart pointer | an object that owns a heap object and deletes it automatically | [10 · Resource management](10-resource-management/README.md) |
| SOLID | five design principles for classes that stay easy to change | [Appendix](appendix/README.md) |
| source file | a text file with C++ code, such as `hello.cpp` | [01 · First programs](01-first-programs/README.md) |
| stack | the memory for local variables; cleaned up automatically at the closing `}` | [09 · Pointers and memory](09-pointers-and-memory/README.md) |
| stack unwinding | destroying the local objects of every function that an exception leaves | [13 · Exceptions](13-exceptions/README.md) |
| starter | the files you get at the beginning of a step | [Projects](projects/README.md) |
| statement | one instruction; most end with `;` | [01 · First programs](01-first-programs/README.md) |
| static binding | the compiler chooses the function while it builds the program, from the type of the variable, reference or pointer | [11 · Inheritance](11-inheritance/README.md) |
| static member | a member that exists once for the whole class, not once for each object | [07 · Classes](07-classes/README.md) |
| `std::optional` | a type that holds either one value or nothing | [13 · Exceptions](13-exceptions/README.md) |
| `std::size_t` | the type of a size or an index: a whole number that is never negative | [05 · Vectors and strings](05-vectors-and-strings/README.md) |
| `std::string::npos` | the value that `find` returns when it does not find the text | [05 · Vectors and strings](05-vectors-and-strings/README.md) |
| string | a piece of text; its type is `std::string` | [02 · Values and types](02-values-and-types/README.md) |
| string stream | like a file stream, but it reads from a string instead of a file | [06 · Structs and files](06-structs-and-files/README.md) |
| struct | a type you define that groups several values under one name | [06 · Structs and files](06-structs-and-files/README.md) |
| template | a pattern from which the compiler writes real functions or classes, one for each type you use | [14 · Templates](14-templates/README.md) |
| template argument | the type that takes the place of a template parameter: the `int` in `Box<int>` | [14 · Templates](14-templates/README.md) |
| template parameter | a name in a template, usually `T`, that stands for a type | [14 · Templates](14-templates/README.md) |
| temporary | an object without a name that disappears at the end of the statement, such as a returned value | [10 · Resource management](10-resource-management/README.md) |
| terminal | a window where you type a command and press Enter | [00 · Getting started](00-getting-started/README.md) |
| test case | an input file together with the exact output that a correct program prints for it | [Projects](projects/README.md) |
| `*this` | inside a member function: the object the function was called on | [08 · Operator overloading](08-operator-overloading/README.md) |
| three-way comparison | the operator `<=>`: it tells whether the left operand is less than, equal to or greater than the right one | [08 · Operator overloading](08-operator-overloading/README.md) |
| `throw` | the statement that leaves a function at once and sends an exception to a handler | [13 · Exceptions](13-exceptions/README.md) |
| trace table | a table that follows the values of the variables round by round | [03 · Control flow](03-control-flow/README.md) |
| trait | a list of functions that a type must provide, like an abstract class with only pure virtual functions | [16 · Rust for C++ programmers](16-rust-for-cpp-programmers/README.md) |
| trait bound | what a generic function needs from its type, for example `T: PartialOrd` | [16 · Rust for C++ programmers](16-rust-for-cpp-programmers/README.md) |
| `try` block | the code that a handler watches | [13 · Exceptions](13-exceptions/README.md) |
| two's complement | the way negative whole numbers are stored; to change the sign of a number, flip every bit and add 1 | [Appendix](appendix/README.md) |
| type | the kind of value a variable holds, such as `int`, `double` or `std::string` | [02 · Values and types](02-values-and-types/README.md) |
| unary operator | an operator with one operand, such as `-a`; a binary operator has two | [08 · Operator overloading](08-operator-overloading/README.md) |
| uncaught exception | an exception that finds no handler; it ends the program | [13 · Exceptions](13-exceptions/README.md) |
| undefined behaviour | something C++ does not check; anything may happen | [01 · First programs](01-first-programs/README.md) |
| usage | the correct form of a command, such as `add <name> <score>`; a program prints it when a command is typed wrongly | [Projects](projects/README.md) |
| variable | a named place in memory that holds one value | [02 · Values and types](02-values-and-types/README.md) |
| vector | a list of values of one type that can grow and shrink (`std::vector`) | [05 · Vectors and strings](05-vectors-and-strings/README.md) |
| virtual destructor | a destructor marked `virtual`, so that a delete through a base pointer destroys the whole object | [12 · Polymorphism](12-polymorphism/README.md) |
| virtual function | a member function that derived classes may replace; the real type of the object decides which version runs | [12 · Polymorphism](12-polymorphism/README.md) |
| virtual inheritance | `class Student : virtual public Person`: all base classes that say this share one `Person` part | [11 · Inheritance](11-inheritance/README.md) |
| vtable | the hidden table of a class's virtual functions; each object of the class holds a pointer to it | [12 · Polymorphism](12-polymorphism/README.md) |
| warning | a compiler message about code that is legal but probably wrong | [01 · First programs](01-first-programs/README.md) |
| `what()` | the member function that returns the message of a standard exception | [13 · Exceptions](13-exceptions/README.md) |
| whitespace | spaces, tabs and line ends | [05 · Vectors and strings](05-vectors-and-strings/README.md) |
