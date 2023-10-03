#include <iostream>
#include <vector>
#include "Task.h"

int main() {
    std::vector<Task> tasks;

    while (true) {
        // Display task list
        std::cout << "Task List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            std::cout << i + 1 << ". " << tasks[i].getDescription();
            if (tasks[i].isCompleted()) {
                std::cout << " (Completed)";
            }
            std::cout << std::endl;
        }

        // Menu options
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Mark Task as Completed" << std::endl;
        std::cout << "3. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Clear newline character from the buffer
                std::getline(std::cin, description);
                Task task(description);
                tasks.push_back(task);
                break;
            }
            case 2: {
                int taskIndex;
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskIndex;

                if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
                    tasks[taskIndex - 1].markCompleted();
                } else {
                    std::cout << "Invalid task number." << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "Exiting the program." << std::endl;
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
