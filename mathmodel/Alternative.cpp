#include "Alternative.h"

#include <utility>

Alternative::Alternative(std::string name, std::vector<double> marks) :
        name(std::move(name)), marks(std::move(marks)) {}

std::string Alternative::getName() {
    return name;
}

std::vector<double> Alternative::getMarks() {
    return marks;
}

void Alternative::setMarks(std::vector<double> marks) {
    this->marks = std::move(marks);
}

double Alternative::minMark() {
    if (marks.empty()) {
        return 0;
    }

    double minMark = marks[0];

    for (int i = 1; i < marks.size(); ++i) {
        if (minMark > marks[i]) {
            minMark = marks[i];
        }
    }

    return minMark;
}

double Alternative::maxMark() {
    if (marks.empty()) {
        return 0;
    }

    double maxMark = marks[0];

    for (int i = 1; i < marks.size(); ++i) {
        if (maxMark < marks[i]) {
            maxMark = marks[i];
        }
    }

    return maxMark;
}

double Alternative::sumOfMarks() {
    double sum = 0;
    for (auto mark: marks) {
        sum += mark;
    }

    return sum;
}

double Alternative::avgOfMarks() {
    if (marks.empty()) {
        return 0;
    }

    return sumOfMarks() / marks.size()
}
