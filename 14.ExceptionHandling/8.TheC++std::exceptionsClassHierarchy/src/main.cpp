#include <iostream>
#include <stdexcept>
#include <vector>

// Custom exception class that extends std::runtime_error
class DatabaseConnectException : public std::runtime_error {
public:
    DatabaseConnectException(const std::string& msg) : std::runtime_error(msg) {}
};

// Custom exception class that extends std::logic_error
class DataFormatException : public std::logic_error {
public:
    DataFormatException(const std::string& msg) : std::logic_error(msg) {}
};

// A mock function that simulates database connection
void connectToDatabase(const std::string& connectionString) {
    if (connectionString.empty()) {
        throw DatabaseConnectException("Connection string is empty.");
    }
    // Assume the connection is successful.
    std::cout << "Successfully connected to the database." << std::endl;
}

// A mock function that simulates data processing
void processData(const std::vector<int>& data) {
    if (data.empty()) {
        throw DataFormatException("Data format is invalid - dataset cannot be empty.");
    }
    // Process the data
    std::cout << "Data processed successfully." << std::endl;
}

int main() {
    try {
        connectToDatabase(""); // This will throw a DatabaseConnectException
        std::vector<int> data; // Empty data will throw a DataFormatException
        processData(data);
    } catch (const DatabaseConnectException& e) {
        std::cerr << "Database error: " << e.what() << std::endl;
    } catch (const DataFormatException& e) {
        std::cerr << "Data processing error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // Catch all other exceptions derived from std::exception
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
        // Catch all other types of exceptions
        std::cerr << "An unknown error has occurred." << std::endl;
    }

    return 0;
}
