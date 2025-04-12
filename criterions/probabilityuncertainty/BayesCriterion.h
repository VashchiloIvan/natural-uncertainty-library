#ifndef NATURAL_UNCERTAINTY_BAYESCRITERION_H
#define NATURAL_UNCERTAINTY_BAYESCRITERION_H

#include "ProbabilityCriterion.h"

class BayesCriterion : public ProbabilityCriterion {
    void logMarks(const std::vector<double>& marks);

public:
    BayesCriterion(const ProbabilisticModel& mathModel);

    SolveStatus solve() override;
};

#endif //NATURAL_UNCERTAINTY_BAYESCRITERION_H
