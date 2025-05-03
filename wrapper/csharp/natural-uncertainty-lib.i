%module libnatural_uncertainty

%{
#include "../../mathmodel/Alternative.h"
#include "../../mathmodel/Uncertainty.h"
#include "../../mathmodel/ProbabilisticAlternative.h"
#include "../../mathmodel/MathModel.h"
#include "../../mathmodel/ProbabilisticModel.h"
#include "../../criterions/Criterion.h"
#include "../../criterions/SolveStatus.h"
#include "../../criterions/tasklog/TaskStep.h"
#include "../../criterions/totaluncertainty/UncertaintyCriterion.h"
#include "../../criterions/totaluncertainty/MaximinCriterion.h"
#include "../../criterions/totaluncertainty/OptimismPessimismCriterion.h"
#include "../../criterions/totaluncertainty/PrincipleOfInsufficientReason.h"
#include "../../criterions/probabilityuncertainty/ProbabilityCriterion.h"
#include "../../criterions/probabilityuncertainty/AverageResultCriterion.h"

%}

%include <std_string.i>
%include <std_vector.i>
%include <std_pair.i>
%include <std_map.i>
%include <std_list.i>
%include <std_set.i>

%include "exception.i"
%exception {
    try {
        $action
    } catch (const std::exception& e) {
        SWIG_exception(SWIG_RuntimeError, e.what());
    }
}

%template(DoubleList) std::vector<double>;
%template(StringList) std::vector<std::string>;
%template(IntList) std::vector<int>;

%template(TaskProcess) std::vector<TaskStep*>;

%template(AlternativeList) std::vector<Alternative>;
%template(ProbabilisticAlternativeList) std::vector<ProbabilisticAlternative>;
%template(UncertaintyList) std::vector<Uncertainty>;

%include "../../mathmodel/Alternative.h"
%include "../../mathmodel/Uncertainty.h"
%include "../../mathmodel/ProbabilisticAlternative.h"
%include "../../mathmodel/MathModel.h"
%include "../../mathmodel/ProbabilisticModel.h"

%include "../../criterions/Criterion.h"
%include "../../criterions/SolveStatus.h"
%include "../../criterions/tasklog/TaskStep.h"

%include "../../criterions/totaluncertainty/UncertaintyCriterion.h"
%include "../../criterions/totaluncertainty/MaximinCriterion.h"
%include "../../criterions/totaluncertainty/OptimismPessimismCriterion.h"
%include "../../criterions/totaluncertainty/PrincipleOfInsufficientReason.h"

%include "../../criterions/probabilityuncertainty/ProbabilityCriterion.h"
%include "../../criterions/probabilityuncertainty/AverageResultCriterion.h"