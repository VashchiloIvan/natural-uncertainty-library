#include "OptimismPessimismCriterion.h"

OptimismPessimismCriterion::OptimismPessimismCriterion(MathModel mathModel, double optimismKoef) {
    this->mathModel = MathModel(mathModel);
    this->optimismKoef = optimismKoef;
}

SolveStatus OptimismPessimismCriterion::solve() {
    if (!mathModel.isValid()) {
        logText("Математическая модель невалидна. "
                "Количество альтернатив и неопределенностей должно быть ненулевым. "
                "Наименования альтернатив и неопределенностей должны быть уникальными. "
                "Число оценок по каждой альтернативе должно совпадать с числом неопределенностей. ");

        return SolveStatus::InvalidModelResult();
    }

    if (optimismKoef < 0 || optimismKoef > 1) {
        logText("Коэффициент оптимизма должен находиться в диапазоне от 0 до 1. "
                "Его значение отражает склонность к оптимизму.");

        return SolveStatus::InvalidParameterResult();
    }

    logText("Для поиска решения для каждой альтернативы вычисляется взвешенная сумма по формуле");
    logText("H=α⋅максимальное значение + (1−α)⋅минимальное значение.");
    logText("Альтернатива с наибольшим значением взвешенной суммы является наилучшей");

    std::vector<double> minMarks;
    std::vector<double> maxMarks;
    std::vector<double> weightedSums;

    double maxWeightedSum = INT_MIN;

    for (auto alternative: mathModel.getAlternatives()) {
        double min = alternative.minMark();
        double max = alternative.maxMark();
        double weightedSum = optimismKoef * max + (1 - optimismKoef) * min;

        if (weightedSum > maxWeightedSum) {
            maxWeightedSum = weightedSum;
        }

        minMarks.push_back(min);
        maxMarks.push_back(max);
        weightedSums.push_back(weightedSum);
    }

    logMinMaxWeightedSum(minMarks, maxMarks, weightedSums);

    std::vector<int> bestAlternatives;
    std::vector<std::string> alternativeNames;

    for (int i = 0; i < weightedSums.size(); ++i) {
        if (weightedSums[i] == maxWeightedSum) {
            bestAlternatives.push_back(i);
            alternativeNames.push_back(mathModel.getAlternatives()[i].getName());
        }
    }

    logText("В результате с максимальной взвешенной суммой " + std::to_string(maxWeightedSum) + " " +
            (bestAlternatives.size() > 1 ? "наилучшими альтернативами являются " : "наилучшей альтернативой является ") +
            join(alternativeNames, ", "));

    return SolveStatus::OptimalDecisionResult(bestAlternatives);
}

void OptimismPessimismCriterion::logMinMaxWeightedSum(std::vector<double> minMarks,
                                                      std::vector<double> maxMarks,
                                                      std::vector<double> weightedSums) {
    if (!withProcessLog) {
        return;
    }

    std::vector<std::string> sidebar;
    for (const auto &alternative: mathModel.getAlternatives()) {
        sidebar.push_back(alternative.getName());
    }

    process.push_back(TaskStep::TablePartType("sidebar", sidebar));

    std::vector<std::string> header = {"минимум", "максимум", "взвешенная сумма"};
    process.push_back(TaskStep::TablePartType("header", header));

    auto size = minMarks.size();
    size = size > maxMarks.size() ? maxMarks.size() : size;
    size = size > weightedSums.size() ? weightedSums.size() : size;

    for (int i = 0; i < size; ++i) {
        std::vector<std::string> row = {
                std::to_string(minMarks[i]),
                std::to_string(maxMarks[i]),
                std::to_string(weightedSums[i])};

        process.push_back(TaskStep::TablePartType("row", row));
    }

    process.push_back(TaskStep::EndTableType());
}
