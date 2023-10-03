#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes don't wory about this 
string decimalToBinary(int n);
string onesComplement(string binary);
string twosComplement(string binary);
string binaryAddition(string a, string b);
string binarySubtraction(string a, string b);

int main() {
    int choice;
    cout << "Binary Converter & Calculator\n";
    cout << "1. Convert Decimal to Binary\n";
    cout << "2. Find 1's and 2's Complement\n";
    cout << "3. Add two binary numbers\n";
    cout << "4. Subtract two binary numbers\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int n;
            cout << "Enter a decimal number: ";
            cin >> n;
            // cout << "Binary representation: " << decimalToBinary(n) << endl;
            // Convert decimal to binary
            if (n == 0) {
                cout << "Binary representation: 0" << endl;
            } else {
                string binary = "";
                while (n > 0) {
                    binary = to_string(n % 2) + binary;
                    n /= 2;
                }
                cout << "Binary representation: " << binary << endl;
            }
            break;
        }
        case 2: {
            string binary;
            cout << "Enter a binary number: ";
            cin >> binary;
            // cout << "1's Complement: " << onesComplement(binary) << endl;
            // cout << "2's Complement: " << twosComplement(binary) << endl;
            // Find 1's complement
            string complement = "";
            for (char bit : binary) {
                complement += (bit == '0') ? '1' : '0';
            }
            cout << "1's Complement: " << complement << endl;

            // Find 2's complement
            bool carry = true;
            for (int i = complement.size() - 1; i >= 0; i--) {
                if (complement[i] == '1' && carry) {
                    complement[i] = '0';
                } else if (complement[i] == '0' && carry) {
                    complement[i] = '1';
                    carry = false;
                }
            }
            cout << "2's Complement: " << complement << endl;
            break;
        }
        case 3: {
            string a, b;
            cout << "Enter first binary number: ";
            cin >> a;
            cout << "Enter second binary number: ";
            cin >> b;
            // cout << "Result: " << binaryAddition(a, b) << endl;
            // Binary addition
            int length = max(a.size(), b.size());
            while (a.size() < length) a = "0" + a;
            while (b.size() < length) b = "0" + b;

            string result = "";
            bool carry = false;
            for (int i = length - 1; i >= 0; i--) {
                int bitSum = (a[i] - '0') + (b[i] - '0') + carry;
                result = to_string(bitSum % 2) + result;
                carry = bitSum > 1;
            }
            if (carry) result = "1" + result; // handle overflow
            cout << "Result: " << result << endl;
            break;
        }
        case 4: {
            string a, b;
            cout << "Enter first binary number: ";
            cin >> a;
            cout << "Enter second binary number: ";
            cin >> b;
            // cout << "Result: " << binarySubtraction(a, b) << endl;
            // break;
            // Binary subtraction using 2's complement
            string twosCompB = "";
            for (char bit : b) {
                twosCompB += (bit == '0') ? '1' : '0';
            }
            bool carry = true;
            for (int i = twosCompB.size() - 1; i >= 0; i--) {
                if (twosCompB[i] == '1' && carry) {
                    twosCompB[i] = '0';
                } else if (twosCompB[i] == '0' && carry) {
                    twosCompB[i] = '1';
                    carry = false;
                }
            }

            int length = max(a.size(), twosCompB.size());
            while (a.size() < length) a = "0" + a;
            while (twosCompB.size() < length) twosCompB = "0" + twosCompB;

            string result = "";
            carry = false;
            for (int i = length - 1; i >= 0; i--) {
                int bitSum = (a[i] - '0') + (twosCompB[i] - '0') + carry;
                result = to_string(bitSum % 2) + result;
                carry = bitSum > 1;
            }
            if (result.size() > a.size()) result.erase(0, 1); // Remove overflow bit

            cout << "Result: " << result << endl;
            break;
        }
        default:
            cout << "Invalid choice!";
    }
    return 0;
}

// Implement the functions below

// Function to convert decimal to binary
string decimalToBinary(int n) {
    if (n == 0) return "0";

    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary;
}

// Function to find the 1's complement of a binary number
string onesComplement(string binary) {
    string complement = "";
    for (char bit : binary) {
        complement += (bit == '0') ? '1' : '0';
    }
    return complement;
}

// Function to find the 2's complement of a binary number
string twosComplement(string binary) {
    string ones = onesComplement(binary);

    // Add 1 to the 1's complement
    bool carry = true;
    for (int i = ones.size() - 1; i >= 0; i--) {
        if (ones[i] == '1' && carry) {
            ones[i] = '0';
        } else if (ones[i] == '0' && carry) {
            ones[i] = '1';
            carry = false;
        }
    }
    return ones;
}

// Function to perform binary addition
string binaryAddition(string a, string b) {
    int length = max(a.size(), b.size());
    while (a.size() < length) a = "0" + a;
    while (b.size() < length) b = "0" + b;

    string result = "";
    bool carry = false;
    for (int i = length - 1; i >= 0; i--) {
        int bitSum = (a[i] - '0') + (b[i] - '0') + carry;
        result = to_string(bitSum % 2) + result;
        carry = bitSum > 1;
    }
    if (carry) result = "1" + result; // handle overflow
    return result;
}

// Function to perform binary subtraction using 2's complement
string binarySubtraction(string a, string b) {
    string twosCompB = twosComplement(b);
    string result = binaryAddition(a, twosCompB);

    // Remove possible overflow bit
    if (result.size() > a.size()) result.erase(0, 1);

    return result;
}
