// Exercise 6: Wallet
// Read commands until the command 0, or until the input ends:
//     1 AMOUNT    add AMOUNT to the balance
//     2 AMOUNT    take AMOUNT from the balance; if there is not enough money,
//                 print "Not enough money" and change nothing
//     3           print "Balance: " and the balance
//     0           stop
// Any other number: print "Unknown command".
// A line that does not start with a number: print "Wrong input" and skip that line.
// At the end, print "Final balance: " and the balance.
#include <iostream>
#include <limits>

int main() {
    int balance = 0;

    // TODO: write the loop that reads and handles the commands.

    std::cout << "Final balance: " << balance << '\n';
}
