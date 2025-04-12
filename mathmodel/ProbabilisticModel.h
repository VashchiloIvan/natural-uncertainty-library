#ifndef NATURAL_UNCERTAINTY_PROBABILISTICMODEL_H
#define NATURAL_UNCERTAINTY_PROBABILISTICMODEL_H

#include "ProbabilisticAlternative.h"
#include "Uncertainty.h"

class ProbabilisticModel {
private:
    std::vector<ProbabilisticAlternative> alternatives;
    std::vector<Uncertainty> uncertainties;
public:
    ProbabilisticModel();
    ProbabilisticModel(std::vector<ProbabilisticAlternative> alternatives, std::vector<Uncertainty> uncertainties);
    ProbabilisticModel(const ProbabilisticModel &mathModel);

    void setAlternatives(std::vector<ProbabilisticAlternative> alternatives);
    void setUncertainties(std::vector<Uncertainty> uncertainties);

    std::vector<ProbabilisticAlternative> getAlternatives();
    std::vector<Uncertainty> getUncertainties();

    bool isValid();
};


#endif
