#include <cstddef>
#include <iostream>
#include <string>

int main() {
    std::string email = "malika";
    email += '@';                               // += adds one character at the end
    email += "cau.uz";                          // or a whole text

    for (char c : email) {                      // one character after the other
        std::cout << c << ' ';
    }
    std::cout << '\n';
    std::cout << email.size() << " characters, the first is " << email[0] << '\n';

    std::size_t atSign = email.find('@');       // the position of the first @
    if (atSign == std::string::npos) {          // npos means "not found"
        std::cout << "No @ in this address.\n";
    } else {
        // substr(position, length): 6 characters from position 0
        std::cout << "User: " << email.substr(0, atSign) << '\n';
        // substr(position): from position 7 to the end
        std::cout << "Site: " << email.substr(atSign + 1) << '\n';
    }
}
