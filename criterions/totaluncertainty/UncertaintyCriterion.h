#ifndef NATURAL_UNCERTAINTY_UNCERTAINTYCRITERION_H
#define NATURAL_UNCERTAINTY_UNCERTAINTYCRITERION_H

#include "../../mathmodel/MathModel.h"
#include "../Criterion.h"

class UncertaintyCriterion : public Criterion {
protected:
    MathModel mathModel;
};


#endif
