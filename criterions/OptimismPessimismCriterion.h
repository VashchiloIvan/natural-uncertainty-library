#ifndef NATURAL_UNCERTAINTY_OPTIMISMPESSIMISMCRITERION_H
#define NATURAL_UNCERTAINTY_OPTIMISMPESSIMISMCRITERION_H


#include "Criterion.h"

class OptimismPessimismCriterion : public Criterion {
private:
    double optimismKoef;

    void logMinMaxWeightedSum(std::vector<double> minMarks,
                              std::vector<double> maxMarks,
                              std::vector<double> weightedSums);

public:
    OptimismPessimismCriterion(MathModel mathModel, double optimismKoef);

    SolveStatus solve() override;
};


#endif
