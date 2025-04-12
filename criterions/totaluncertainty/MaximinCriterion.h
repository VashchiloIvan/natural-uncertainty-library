#ifndef NATURAL_UNCERTAINTY_MAXIMINCRITERION_H
#define NATURAL_UNCERTAINTY_MAXIMINCRITERION_H


#include "Criterion.h"

class MaximinCriterion : public Criterion {
private:
    void logMarks(const std::vector<double>& minimalMarks);

public:
    MaximinCriterion(MathModel mathModel);

    SolveStatus solve();
};


#endif //NATURAL_UNCERTAINTY_MAXIMINCRITERION_H
