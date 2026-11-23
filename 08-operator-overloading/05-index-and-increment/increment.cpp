#include <iostream>

class Clock {
public:
    Clock(int hour, int minute) : hour_(hour), minute_(minute) {}

    Clock& operator++() {           // prefix: ++clock
        ++minute_;
        if (minute_ == 60) {
            minute_ = 0;
            hour_ = (hour_ + 1) % 24;
        }
        return *this;               // the changed object itself
    }

    Clock operator++(int) {         // postfix: clock++
        Clock old = *this;          // remember the value before the change
        ++*this;                    // the prefix version does the work
        return old;                 // a copy of the old value
    }

    void print() const { std::cout << hour_ << " h " << minute_ << " min\n"; }

private:
    int hour_ = 0;
    int minute_ = 0;
};

int main() {
    Clock now(9, 58);

    Clock a = ++now;        // now changes first: a and now are both 9 h 59 min
    a.print();

    Clock b = now++;        // b gets the old value; now moves on to 10 h 0 min
    b.print();
    now.print();
}
