#include <iostream>
#include <vector>
#include <string>

// Define a struct to represent a task
struct Task {
    std::string title;
    bool completed;
};

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "Task Manager Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. List Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                {
                    Task task;
                    std::cout << "Enter task title: ";
                    std::cin.ignore(); // Consume the newline character left in the input buffer
                    std::getline(std::cin, task.title);
                    task.completed = false;
                    tasks.push_back(task);
                    std::cout << "Task added successfully!\n";
                }
                break;

            case 2:
                if (tasks.empty()) {
                    std::cout << "No tasks to display.\n";
                    continue; // Continue to the menu without executing the rest of the loop
                }

                std::cout << "Task List:\n";
                for (size_t i = 0; i < tasks.size(); ++i) {
                    std::cout << i + 1 << ". ";
                    if (tasks[i].completed) {
                        std::cout << "[X] ";
                    } else {
                        std::cout << "[ ] ";
                    }
                    std::cout << tasks[i].title << "\n";
                }
                break;

            case 3:
                if (tasks.empty()) {
                    std::cout << "No tasks to mark as completed.\n";
                    continue; // Continue to the menu without executing the rest of the loop
                }

                std::cout << "Enter the task number to mark as completed: ";
                int taskNumber;
                std::cin >> taskNumber;

                if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
                    tasks[taskNumber - 1].completed = true;
                    std::cout << "Task marked as completed!\n";
                } else {
                    std::cout << "Invalid task number.\n";
                }
                break;

            case 4:
                std::cout << "Exiting the Task Manager.\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

        if (choice == 4) {
            break; // Exit the loop if choice is 4
        }
    }

    return 0;
}
