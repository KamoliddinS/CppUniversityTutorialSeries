#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "player.h"

std::unique_ptr<Player> makePlayer(const std::string& name) {
    auto player = std::make_unique<Player>(name);
    return player;                      // plain return: the caller becomes the owner
}

void sendHome(std::unique_ptr<Player> player) {     // by value: sendHome becomes the owner
    std::cout << player->name() << " goes home\n";
}                                                   // player is destroyed and deletes its Player

int main() {
    auto aziz = makePlayer("Aziz");
    auto malika = makePlayer("Malika");

    std::vector<std::unique_ptr<Player>> team;
    team.push_back(std::move(aziz));    // the vector owns Aziz now
    if (aziz == nullptr) {
        std::cout << "aziz is empty\n";
    }

    sendHome(std::move(malika));        // malika hands its Player over
    std::cout << "Team size: " << team.size() << '\n';
}                                       // team is destroyed and deletes Aziz
