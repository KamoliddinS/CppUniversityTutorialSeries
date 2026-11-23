// Exercise 3: Minus and times
// Complete the five operators at the TODO marks.
// Do not change check and main: they test your operators.
// Until you finish, the compiler warns about parameters that are not used yet.
#include <iostream>
#include <string>

class Money {
public:
    Money(long long soms, long long tiyin) : amount_(soms * 100 + tiyin) {}

    bool operator==(const Money&) const = default;

    Money& operator+=(const Money& other) {
        amount_ += other.amount_;
        return *this;
    }

    // TODO 1: subtract other from this object.
    Money& operator-=(const Money& other) {
        return *this;
    }

    // TODO 2: make this object count times as large.
    Money& operator*=(int count) {
        return *this;
    }

private:
    long long amount_ = 0;      // in tiyin: 1 so'm = 100 tiyin
};

Money operator+(const Money& a, const Money& b) {
    Money sum = a;
    sum += b;
    return sum;
}

// TODO 3: return a new Money: a minus b. Build it on -=, as + is built on +=.
Money operator-(const Money& a, const Money& b) {
    return a;
}

// TODO 4: return a new Money: m times count. Build it on *=.
Money operator*(const Money& m, int count) {
    return m;
}

// TODO 5: the same, with the number on the left.
Money operator*(int count, const Money& m) {
    return m;
}

// Prints a message when a check fails. Returns 1 for a failed check and 0 for a passed one.
int check(bool ok, const std::string& what) {
    if (ok) {
        return 0;
    }
    std::cout << "FAILED: " << what << '\n';
    return 1;
}

int main() {
    int failed = 0;
    const Money price(16001, 25);
    const Money paid(20000, 0);
    const Money notebook(12500, 50);

    Money rest = paid;
    rest -= price;
    failed += check(rest == Money(3998, 75), "rest -= price leaves 3998 so'm 75 tiyin");
    (rest -= Money(3000, 0)) -= Money(998, 75);
    failed += check(rest == Money(0, 0), "(rest -= a) -= b subtracts a and b from rest");

    failed += check(paid - price == Money(3998, 75), "paid - price is 3998 so'm 75 tiyin");
    failed += check(price - price == Money(0, 0), "price - price is 0 so'm");
    failed += check(paid - price + price == paid, "paid - price + price is paid again");

    Money three = notebook;
    three *= 3;
    failed += check(three == Money(37501, 50), "three *= 3 gives 37501 so'm 50 tiyin");
    failed += check(notebook * 2 == Money(25001, 0), "notebook * 2 is 25001 so'm");
    failed += check(2 * notebook == Money(25001, 0), "2 * notebook is 25001 so'm");
    failed += check(notebook * 0 == Money(0, 0), "notebook * 0 is 0 so'm");
    failed += check(paid - notebook * 1 == Money(7499, 50),
                    "paid - notebook * 1 is 7499 so'm 50 tiyin");

    if (failed > 0) {
        return 1;
    }
    std::cout << "All checks passed.\n";
}
