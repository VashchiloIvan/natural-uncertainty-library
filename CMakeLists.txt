cmake_minimum_required(VERSION 3.26)
project(natural_uncertainty)

set(CMAKE_CXX_STANDARD 17)

add_library(natural_uncertainty SHARED
        mathmodel/Alternative.cpp
        mathmodel/Alternative.h
        mathmodel/Uncertainty.cpp
        mathmodel/Uncertainty.h
        mathmodel/MathModel.cpp
        mathmodel/MathModel.h
        mathmodel/ProbabilisticModel.cpp
        mathmodel/ProbabilisticModel.h
        mathmodel/ProbabilisticAlternative.cpp
        mathmodel/ProbabilisticAlternative.h

        criterions/SolveStatus.cpp
        criterions/SolveStatus.h
        criterions/tasklog/TaskStep.h
        criterions/tasklog/TaskStep.cpp
        criterions/Criterion.h
        criterions/Criterion.cpp

        criterions/totaluncertainty/UncertaintyCriterion.h
        criterions/totaluncertainty/MaximinCriterion.cpp
        criterions/totaluncertainty/MaximinCriterion.h
        criterions/totaluncertainty/OptimismPessimismCriterion.cpp
        criterions/totaluncertainty/OptimismPessimismCriterion.h
        criterions/totaluncertainty/PrincipleOfInsufficientReason.cpp
        criterions/totaluncertainty/PrincipleOfInsufficientReason.h

        criterions/probabilityuncertainty/ProbabilityCriterion.h
        criterions/probabilityuncertainty/AverageResultCriterion.cpp
        criterions/probabilityuncertainty/AverageResultCriterion.h

        wrapper/csharp/natural-uncertainty-lib_wrap.cxx
)
