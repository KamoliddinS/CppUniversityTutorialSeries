#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {
public:
    explicit Player(const std::string& name) : name_(name) { std::cout << name_ << " joins\n"; }
    ~Player() { std::cout << name_ << " leaves\n"; }
    std::string name() const { return name_; }

private:
    std::string name_;
};

#endif
