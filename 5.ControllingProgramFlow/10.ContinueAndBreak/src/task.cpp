#include "task.h"

Task::Task(const std::string& desc) : description(desc), completed(false) {}

std::string Task::getDescription() const {
    return description;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::markCompleted() {
    completed = true;
}
