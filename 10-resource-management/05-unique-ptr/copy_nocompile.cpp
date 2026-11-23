#include <memory>

#include "player.h"

int main() {
    auto p = std::make_unique<Player>("Aziz");
    auto q = p;         // a copy would be a second owner
}
