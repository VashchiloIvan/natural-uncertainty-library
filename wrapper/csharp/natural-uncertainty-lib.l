%module natural_uncertainty_lib

%{
#include "../../mathmodel/Alternative.h"
#include "../../mathmodel/Uncertainty.h"
#include "../../mathmodel/MathModel.h"
#include "../../criterions/Criterion.h"
#include "../../criterions/MaximinCriterion.h"
#include "../../criterions/SolveStatus.h"
#include "../../criterions/tasklog/TaskStep.h"
#include "../../criterions/OptimismPessimismCriterion.h"
#include "../../criterions/PrincipleOfInsufficientReason.h"
%}

%include "std_string.i"
%include "std_vector.i"
%include "std_pair.i"
%include "std_map.i"
%include "std_list.i"
%include "std_set.i"

%include "../../mathmodel/Alternative.h"
%include "../../mathmodel/Uncertainty.h"
%include "../../mathmodel/MathModel.h"
%include "../../criterions/Criterion.h"
%include "../../criterions/MaximinCriterion.h"
%include "../../criterions/SolveStatus.h"
%include "../../criterions/tasklog/TaskStep.h"
%include "../../criterions/OptimismPessimismCriterion.h"
%include "../../criterions/PrincipleOfInsufficientReason.h"

%template(DoubleList) std::vector<double>;
%template(StringList) std::vector<std::string>;
%template(IntList) std::vector<int>;

%template(TaskProcess) std::vector<TaskStep*>;

%template(AlternativeList) std::vector<Alternative>;
%template(UncertaintyList) std::vector<Uncertainty>;