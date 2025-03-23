#ifndef NATURAL_UNCERTAINTY_TASKSTEP_H
#define NATURAL_UNCERTAINTY_TASKSTEP_H

#include <string>
#include <vector>

class TaskStep {
    std::string type;
    std::string step;
public:
    TaskStep(std::string type, std::string step);
    TaskStep(std::string type, std::vector<std::string> row);

    static TaskStep* TextType(std::string step);
    static TaskStep* TablePartType(std::string type, std::vector<std::string> row);
    static TaskStep* EndTableType();

    std::string StepType();
    std::string AsString();
};

#endif //NATURAL_UNCERTAINTY_TASKSTEP_H
