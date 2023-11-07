#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    // File opening
    std::fstream file("example.txt", std::ios::in | std::ios::out | std::ios::trunc);

    // Check if the file stream successfully opened
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }

    // Writing to a file
    file << "Hello, World!" << std::endl;
    file << "This is an example of writing to a file in C++." << std::endl;

    // Reset the position to the beginning of the file to read from it
    file.seekg(0);

    // Reading from a file
    std::string line;
    std::cout << "Reading from the file:" << std::endl;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    // Check for file read error
    if (file.bad()) {
        std::cerr << "I/O error while reading" << std::endl;
    } else if (!file.eof()) {
        std::cerr << "Unknown error occurred while reading" << std::endl;
    }

    // Closing the file
    file.close();

    // Demonstrating file modes and random access
    std::fstream randomAccessFile("example.txt", std::ios::in | std::ios::out | std::ios::binary);
    
    // Check if the file opened successfully
    if (!randomAccessFile) {
        std::cerr << "Error opening file for random access!" << std::endl;
        return -1;
    }

    // Seek to 5th byte and write
    randomAccessFile.seekp(5);
    randomAccessFile << "Random Access Write";

    // Seek to 10th byte and read
    randomAccessFile.seekg(10);
    std::getline(randomAccessFile, line);
    std::cout << "Read from random access: " << line << std::endl;

    // Demonstrating error handling
    if (randomAccessFile.fail()) {
        std::cerr << "Error occurred at reading or writing with random access." << std::endl;
    }

    // File is automatically closed when fstream goes out of scope

    return 0;
}
