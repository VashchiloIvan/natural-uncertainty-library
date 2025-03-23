#include "SolveStatus.h"

SolveStatus SolveStatus::OptimalDecisionResult(std::vector<int> bestAlternativeNum) {
    SolveStatus status;

    status.status = SomeDecisions;
    if (bestAlternativeNum.size() == 1) {
        status.status = OneDecision;
    }

    status.bestAlternatives = std::move(bestAlternativeNum);

    return status;
}

SolveStatus SolveStatus::FailedResult() {
    SolveStatus status;

    status.status = Failed;

    return status;
}

SolveStatus SolveStatus::InvalidModelResult() {
    SolveStatus status;

    status.status = InvalidModel;

    return status;
}

SolveStatus SolveStatus::InvalidParameterResult() {
    SolveStatus status;

    status.status = InvalidParameter;

    return status;
}

Status SolveStatus::getStatus() {
    return status;
}

std::vector<int> SolveStatus::getBestAlternatives() {
    return bestAlternatives;
}
