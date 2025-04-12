#include "ProbabilityCriterion.h"

void ProbabilityCriterion::withLoggingProcess() {
    withProcessLog = true;
}

std::vector<TaskStep *> ProbabilityCriterion::getProcess() {
    auto copy = std::move(process);
    process.clear();

    return copy;
}

void ProbabilityCriterion::logText(std::string text) {
    if (!withProcessLog) {
        return;
    }

    process.push_back(TaskStep::TextType(text));
}

std::string ProbabilityCriterion::join(std::vector<std::string> strings, std::string separator) {
    if (strings.empty()) {
        return "";
    }

    std::string startString = strings[0];

    for (int i = 1; i < strings.size(); ++i) {
        startString += separator + strings[i];
    }

    return startString;
}
