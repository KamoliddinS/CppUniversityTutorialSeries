// A thermostat remembers the temperature that a room should have.
// This file is correct. The four mistakes are in thermostat.cpp and main.cpp.
#ifndef THERMOSTAT_H
#define THERMOSTAT_H

class Thermostat {
public:
    explicit Thermostat(int degrees);

    void warmer();      // one degree up, but never above 30
    void cooler();      // one degree down, but never below 16
    int degrees() const;

private:
    int degrees_ = 20;  // always between 16 and 30
};

#endif
