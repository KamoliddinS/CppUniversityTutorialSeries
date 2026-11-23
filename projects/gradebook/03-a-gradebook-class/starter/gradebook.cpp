// Gradebook, step 3: A gradebook class
// The bodies of everything that gradebook.h declares belong in this file.
// Only size() is written. If you call a function that has no body yet, the linker says
// "undefined reference": write the body here.
#include "gradebook.h"

std::size_t Gradebook::size() const {
    return students_.size();
}

// TODO: average, operator<< and the other member functions of Gradebook.
