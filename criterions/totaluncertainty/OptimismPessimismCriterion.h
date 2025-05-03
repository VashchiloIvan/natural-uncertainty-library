#ifndef NATURAL_UNCERTAINTY_OPTIMISMPESSIMISMCRITERION_H
#define NATURAL_UNCERTAINTY_OPTIMISMPESSIMISMCRITERION_H


#include "UncertaintyCriterion.h"

class OptimismPessimismCriterion : public UncertaintyCriterion {
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
