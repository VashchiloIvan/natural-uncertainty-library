#include "ProbabilisticAlternative.h"

#include <utility>

ProbabilisticAlternative::ProbabilisticAlternative(std::string name, std::vector<double> marks,
                                                   std::vector<double> probabilities) {
    this->name = std::move(name);
    this->marks = std::move(marks);
    this->probabilities = std::move(probabilities);
}

bool ProbabilisticAlternative::isValid() const {
    if (marks.size() != probabilities.size()) {
        return false;
    }

    double probabilitiesSum = 0;
    for (auto probability: probabilities) {
        probabilitiesSum += probability;
    }

    if (std::fabs(1 - probabilitiesSum) >= std::numeric_limits<double>::epsilon()) {
        return false;
    }

    return true;
}

std::string ProbabilisticAlternative::getName() const {
    return name;
}

std::vector<double> ProbabilisticAlternative::getMarks() {
    return marks;
}

std::vector<double> ProbabilisticAlternative::getProbabilities() {
    return probabilities;
}

void ProbabilisticAlternative::setMarks(std::vector<double> marks) {
    this->marks = std::move(marks);
}

void ProbabilisticAlternative::setProbabilities(std::vector<double> probabilities) {
    this->probabilities = std::move(probabilities);
}

double ProbabilisticAlternative::getMathematicalExpectation() {
    double sum = 0;
    auto len = marks.size() > probabilities.size() ? probabilities.size() : marks.size();

    for (int i = 0; i < len; ++i) {
        sum += marks[i] * probabilities[i];
    }

    return sum;
}