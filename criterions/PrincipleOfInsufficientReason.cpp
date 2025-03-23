#include "PrincipleOfInsufficientReason.h"

PrincipleOfInsufficientReason::PrincipleOfInsufficientReason(MathModel mathModel) {
    this->mathModel = MathModel(mathModel);
}

SolveStatus PrincipleOfInsufficientReason::solve() {
    if (!mathModel.isValid()) {
        logText("Математическая модель невалидна. "
                "Количество альтернатив и неопределенностей должно быть ненулевым. "
                "Наименования альтернатив и неопределенностей должны быть уникальными. "
                "Число оценок по каждой альтернативе должно совпадать с числом неопределенностей. ");

        return SolveStatus::InvalidModelResult();
    }

    logText("Предполагается, что все заданные неопределенности равновероятны. "
            "Исходя из этого предположения оценка альтернативы является средним значением "
            "оценок по каждой альтернативе. ");

    std::vector<double> averageMarks;
    double maxAvgMark = INT_MAX;
    for (auto alternative: mathModel.getAlternatives()) {
        auto altAvgMark = alternative.avgOfMarks();

        averageMarks.push_back(altAvgMark);

        if (altAvgMark > maxAvgMark) {
            maxAvgMark = altAvgMark;
        }
    }

    logMarks(averageMarks);

    std::vector<int> bestAlternatives;
    std::vector<std::string> alternativeNames;

    for (int i = 0; i < averageMarks.size(); ++i) {
        if (averageMarks[i] == maxAvgMark) {
            bestAlternatives.push_back(i);
            alternativeNames.push_back(mathModel.getAlternatives()[i].getName());
        }
    }

    logText("В результате с максимальной среди усредненных оценок является значение " + std::to_string(maxAvgMark) +
            ". Таким образом, " +
            (bestAlternatives.size() > 1 ? "наилучшими альтернативами являются" : "наилучшей альтернативой является") +
            join(alternativeNames, ", "));

    return SolveStatus::OptimalDecisionResult(bestAlternatives);
}

void PrincipleOfInsufficientReason::logMarks(const std::vector<double>& avgMarks) {
    if (!withProcessLog) {
        return;
    }

    std::vector<std::string> sidebar;
    for (const auto &alternative: mathModel.getAlternatives()) {
        sidebar.push_back(alternative.getName());
    }

    process.push_back(TaskStep::TablePartType("sidebar", sidebar));

    std::vector<std::string> header = {"среднее значение"};
    process.push_back(TaskStep::TablePartType("header", header));

    for (auto mark: avgMarks) {
        std::vector<std::string> estimateVector = {std::to_string(mark)};

        process.push_back(TaskStep::TablePartType("row", estimateVector));
    }

    process.push_back(TaskStep::EndTableType());
}
