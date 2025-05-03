#ifndef NATURAL_UNCERTAINTY_PROBABILITYCRITERION_H
#define NATURAL_UNCERTAINTY_PROBABILITYCRITERION_H

#include "../../mathmodel/ProbabilisticModel.h"
#include "../Criterion.h"

class ProbabilityCriterion : public Criterion {
protected:
    ProbabilisticModel mathModel;
};


#endif
