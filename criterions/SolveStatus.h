#ifndef NATURAL_UNCERTAINTY_SOLVESTATUS_H
#define NATURAL_UNCERTAINTY_SOLVESTATUS_H

#include <iostream>

enum Status {
    Failed, // Ошибка в процессе поиска решения
    InvalidModel, // Ошибка модели
    InvalidParameter, // Ошибка входных данных
    OneDecision, // Найдена оптимальная альтернатива
    SomeDecisions // Найдено несколько оптимальных альтернатив
};

class SolveStatus {
private:
    std::vector<int> bestAlternatives;
    Status status;

public:
    static SolveStatus OptimalDecisionResult(std::vector<int> bestAlternativeNum);
    static SolveStatus FailedResult();
    static SolveStatus InvalidModelResult();
    static SolveStatus InvalidParameterResult();

    Status getStatus();
    std::vector<int> getBestAlternatives();
};


#endif
