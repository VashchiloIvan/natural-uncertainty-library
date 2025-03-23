#ifndef NATURAL_UNCERTAINTY_PRINCIPLEOFINSUFFICIENTREASON_H
#define NATURAL_UNCERTAINTY_PRINCIPLEOFINSUFFICIENTREASON_H


#include "Criterion.h"

class PrincipleOfInsufficientReason : public Criterion {
private:
    void logMarks(const std::vector<double>& avgMarks);

public:
    PrincipleOfInsufficientReason(MathModel mathModel);

    SolveStatus solve() override;
};


#endif
