#include "Criterion.h"

void Criterion::withLoggingProcess() {
    withProcessLog = true;
}

std::vector<TaskStep *> Criterion::getProcess() {
    auto copy = std::move(process);
    process.clear();

    return copy;
}

void Criterion::logText(std::string text) {
    if (!withProcessLog) {
        return;
    }

    process.push_back(TaskStep::TextType(text));
}

std::string Criterion::join(std::vector<std::string> strings, std::string separator) {
    if (strings.empty()) {
        return "";
    }

    std::string startString = strings[0];

    for (int i = 1; i < strings.size(); ++i) {
        startString += separator + strings[i];
    }

    return startString
}
