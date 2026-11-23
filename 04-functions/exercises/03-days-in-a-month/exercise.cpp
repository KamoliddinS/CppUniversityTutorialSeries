// Exercise 3: Days in a month
// Complete the two functions at the TODO marks.
// Do not change check and main: they test your functions.
#include <iostream>
#include <string>

// Returns true when year is a leap year. A leap year can be divided by 4
// without a remainder. A year that can be divided by 100 is not a leap year,
// unless it can also be divided by 400.
bool isLeapYear(int year) {
    // TODO: this is only the first part of the rule. Add the rest.
    return year % 4 == 0;
}

// Returns the number of days in a month: 1 is January, 12 is December.
// Months 4, 6, 9 and 11 have 30 days. Month 2 has 28 days, or 29 in a leap year.
// The other months have 31 days. Returns 0 when month is not a number from 1 to 12.
int daysInMonth(int month, int year) {
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    // TODO: return the right number for every other case.
    return 31;
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

    failed += check(isLeapYear(2024), "2024 is a leap year");
    failed += check(!isLeapYear(2026), "2026 is not a leap year");
    failed += check(!isLeapYear(1900), "1900 is not a leap year");
    failed += check(isLeapYear(2000), "2000 is a leap year");

    failed += check(daysInMonth(1, 2026) == 31, "January has 31 days");
    failed += check(daysInMonth(4, 2026) == 30, "April has 30 days");
    failed += check(daysInMonth(11, 2026) == 30, "November has 30 days");
    failed += check(daysInMonth(2, 2026) == 28, "February 2026 has 28 days");
    failed += check(daysInMonth(2, 2024) == 29, "February 2024 has 29 days");
    failed += check(daysInMonth(2, 1900) == 28, "February 1900 has 28 days");
    failed += check(daysInMonth(0, 2026) == 0, "there is no month 0");
    failed += check(daysInMonth(13, 2026) == 0, "there is no month 13");

    if (failed > 0) {
        return 1;
    }
    std::cout << "All checks passed.\n";
}
