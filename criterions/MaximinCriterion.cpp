#include "MaximinCriterion.h"

MaximinCriterion::MaximinCriterion(MathModel mathModel) {
    this->mathModel = MathModel(mathModel);
}

SolveStatus MaximinCriterion::solve() {
    if (!mathModel.isValid()) {
        logText("Математическая модель невалидна. "
                "Количество альтернатив и неопределенностей должно быть ненулевым. "
                "Наименования альтернатив и неопределенностей должны быть уникальными. "
                "Число оценок по каждой альтернативе должно совпадать с числом неопределенностей. ");

        return SolveStatus::InvalidModelResult();
    }

    logText("Для поиска решения вычисляется минимальные значения по каждой альтернативе. "
            "Альтернатива с наибольшим значением является наилучшей");

    std::vector<double> minimalMarks;
    double minMark = INT_MAX;
    for (auto alternative: mathModel.getAlternatives()) {
        auto altMinMark = alternative.minMark();

        minimalMarks.push_back(altMinMark);

        if (altMinMark < minMark) {
            minMark = altMinMark;
        }
    }

    logMarks(minimalMarks);

    std::vector<int> bestAlternatives;
    std::vector<std::string> alternativeNames;

    for (int i = 0; i < minimalMarks.size(); ++i) {
        if (minimalMarks[i] == minMark) {
            bestAlternatives.push_back(i);
            alternativeNames.push_back(mathModel.getAlternatives()[i].getName());
        }
    }

    logText("В результате с максимальной среди минимальных оценок " + std::to_string(minMark) + " " +
            (bestAlternatives.size() > 1 ? "наилучшими альтернативами являются" : "наилучшей альтернативой является") +
            join(alternativeNames, ", "));

    return SolveStatus::OptimalDecisionResult(bestAlternatives);
}

void MaximinCriterion::logMarks(const std::vector<double>& minimalMarks) {
    if (!withProcessLog) {
        return;
    }

    std::vector<std::string> sidebar;
    for (const auto &alternative: mathModel.getAlternatives()) {
        sidebar.push_back(alternative.getName());
    }

    process.push_back(TaskStep::TablePartType("sidebar", sidebar));

    std::vector<std::string> header = {"минимальное значение"};
    process.push_back(TaskStep::TablePartType("header", header));

    for (auto mark: minimalMarks) {
        std::vector<std::string> estimateVector = {std::to_string(mark)};

        process.push_back(TaskStep::TablePartType("row", estimateVector));
    }

    process.push_back(TaskStep::EndTableType());
}
