#include <iostream>
#include <memory>

#include "player.h"

void greet(const Player& player) {          // only uses the player: a reference is enough
    std::cout << "Hello, " << player.name() << "!\n";
}

int main() {
    auto aziz = std::make_unique<Player>("Aziz");       // a Player on the heap; aziz owns it
    greet(*aziz);                                       // *aziz is the Player itself
    std::cout << aziz->name() << " is ready\n";

    auto malika = std::make_unique<Player>("Malika");
    malika.reset();                                     // deletes Malika now; malika is empty
    std::cout << "end of main\n";
}                                                       // aziz is destroyed and deletes Aziz
