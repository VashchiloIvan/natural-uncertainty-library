#ifndef NATURAL_UNCERTAINTY_MATHMODEL_H
#define NATURAL_UNCERTAINTY_MATHMODEL_H

#include <iostream>
#include "Alternative.h"
#include "Uncertainty.h"


class MathModel {
private:
    std::vector<Alternative> alternatives;
    std::vector<Uncertainty> uncertainties;
public:
    MathModel();
    MathModel(std::vector<Alternative> alternatives, std::vector<Uncertainty> uncertainties);
    MathModel(const MathModel &mathModel);

    void setAlternatives(std::vector<Alternative> alternatives);
    void setUncertainties(std::vector<Uncertainty> uncertainties);

    std::vector<Alternative> getAlternatives();
    std::vector<Uncertainty> getUncertainties();

    bool isValid();
};


#endif