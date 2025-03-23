#ifndef NATURAL_UNCERTAINTY_CRITERION_H
#define NATURAL_UNCERTAINTY_CRITERION_H

#include "../mathmodel/MathModel.h"
#include "SolveStatus.h"
#include "tasklog/TaskStep.h"

class Criterion {
protected:
    MathModel mathModel;

    bool withProcessLog;
    std::vector<TaskStep *> process;

    void logText(std::string);
    std::string join(std::vector<std::string> strings, std::string separator);

public:
    void withLoggingProcess();
    std::vector<TaskStep *> getProcess();

    virtual SolveStatus solve() = 0;
};


#endif
