#ifndef NATURAL_UNCERTAINTY_AVERAGERESULTCRITERION_H
#define NATURAL_UNCERTAINTY_AVERAGERESULTCRITERION_H

#include "ProbabilityCriterion.h"

class AverageResultCriterion : public ProbabilityCriterion {
    void logMarks(const std::vector<double>& marks);

public:
    AverageResultCriterion(const ProbabilisticModel& mathModel);

    SolveStatus solve() override;
};

#endif //NATURAL_UNCERTAINTY_AVERAGERESULTCRITERION_H
