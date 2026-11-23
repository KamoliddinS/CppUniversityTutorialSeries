// Gradebook, step 4: Kinds of assessment
#ifndef ASSESSMENT_H
#define ASSESSMENT_H

#include <memory>
#include <string>

// One score of a student. The derived classes say what kind of work the score is for
// and how much it counts.
class Assessment {
public:
    explicit Assessment(int score);
    virtual ~Assessment() = default;

    int score() const;
    virtual std::string kind() const = 0;   // the word used in commands and files
    virtual int weight() const = 0;         // how many times the score counts in the final grade

private:
    int score_ = 0;
};

// TODO: the classes Homework, Project and Exam. Each one is derived from Assessment.

// Creates an assessment of the kind with this name. Returns nullptr for any other word.
std::unique_ptr<Assessment> makeAssessment(const std::string& kind, int score);

#endif
