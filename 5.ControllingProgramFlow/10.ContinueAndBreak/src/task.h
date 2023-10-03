#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    Task(const std::string& description);

    std::string getDescription() const;
    bool isCompleted() const;
    void markCompleted();

private:
    std::string description;
    bool completed;
};

#endif
