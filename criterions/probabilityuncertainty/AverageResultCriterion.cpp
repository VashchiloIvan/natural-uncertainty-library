#include "AverageResultCriterion.h"

AverageResultCriterion::AverageResultCriterion(const ProbabilisticModel& mathModel) {
    this->mathModel = ProbabilisticModel(mathModel);
}

SolveStatus AverageResultCriterion::solve() {
    if (!mathModel.isValid()) {
        logText("Математическая модель невалидна. "
                "Количество альтернатив и неопределенностей должно быть ненулевым. "
                "Наименования альтернатив и неопределенностей должны быть уникальными. "
                "Число оценок по каждой альтернативе должно совпадать с числом неопределенностей. "
                "Альтернативы должны иметь одинаковое количество заданных вероятносей и оценок");

        return SolveStatus::InvalidModelResult();
    }

    logText("Для поиска решения вычисляется средний ожидаемый результат каждой альтернативы "
            "в виде суммы произведений оценок альтернативы на их вероятности. "
            "Лучшей считается та альтернатива, для которой этот результат наибольший");

    std::vector<double> alternativeMathExps;
    double maxMark = INT_MIN;
    for (auto alternative: mathModel.getAlternatives()) {
        auto altMinMark = alternative.getMathematicalExpectation();

        alternativeMathExps.push_back(altMinMark);

        if (altMinMark > maxMark) {
            maxMark = altMinMark;
        }
    }

    logMarks(alternativeMathExps);

    std::vector<int> bestAlternatives;
    std::vector<std::string> alternativeNames;

    for (int i = 0; i < alternativeMathExps.size(); ++i) {
        if (alternativeMathExps[i] == maxMark) {
            bestAlternatives.push_back(i);
            alternativeNames.push_back(mathModel.getAlternatives()[i].getName());
        }
    }

    logText("В результате с максимальным математическим ожиданием, равным " + std::to_string(maxMark) + ", " +
            (bestAlternatives.size() > 1 ? "наилучшими альтернативами являются " : "наилучшей альтернативой является ") +
            join(alternativeNames, ", "));

    return SolveStatus::OptimalDecisionResult(bestAlternatives);
}

void AverageResultCriterion::logMarks(const std::vector<double>& marks) {
    if (!withProcessLog) {
        return;
    }

    std::vector<std::string> sidebar;
    for (const auto &alternative: mathModel.getAlternatives()) {
        sidebar.push_back(alternative.getName());
    }

    process.push_back(TaskStep::TablePartType("sidebar", sidebar));

    std::vector<std::string> header = {"мат. ожидание"};
    process.push_back(TaskStep::TablePartType("header", header));

    for (auto mark: marks) {
        std::vector<std::string> estimateVector = {std::to_string(mark)};

        process.push_back(TaskStep::TablePartType("row", estimateVector));
    }

    process.push_back(TaskStep::EndTableType());
}