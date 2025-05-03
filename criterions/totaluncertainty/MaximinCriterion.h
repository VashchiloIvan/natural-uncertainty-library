#ifndef NATURAL_UNCERTAINTY_MAXIMINCRITERION_H
#define NATURAL_UNCERTAINTY_MAXIMINCRITERION_H


#include "UncertaintyCriterion.h"

class MaximinCriterion : public UncertaintyCriterion {
private:
    void logMarks(const std::vector<double>& minimalMarks);

public:
    MaximinCriterion(MathModel mathModel);

    SolveStatus solve();
};


#endif //NATURAL_UNCERTAINTY_MAXIMINCRITERION_H
