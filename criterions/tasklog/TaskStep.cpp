#include "TaskStep.h"

TaskStep::TaskStep(std::string type, std::string step) {
    this->step = step;
    this->type = type;
}

TaskStep::TaskStep(std::string type, std::vector<std::string> row) {
    this->type = type;
    if (row.empty()) {
        return;
    }

    this->step = row[0];

    for (int i = 1; i < row.size(); ++i) {
        this->step += "|" + row[i];
    }
}

std::string TaskStep::AsString() {
    return this->step;
}

std::string TaskStep::StepType() {
    return this->type;
}

TaskStep *TaskStep::TextType(std::string step) {
    return new TaskStep("text", step);
}

TaskStep *TaskStep::TablePartType(std::string type, std::vector<std::string> row) {
    return new TaskStep(type, row);
}

TaskStep *TaskStep::EndTableType() {
    return new TaskStep("end_table", "");
}

