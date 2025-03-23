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
        criterions/MaximinCriterion.cpp
        criterions/MaximinCriterion.h
        criterions/Criterion.cpp
        criterions/Criterion.h
        criterions/SolveStatus.cpp
        criterions/SolveStatus.h
        criterions/tasklog/TaskStep.h
        criterions/tasklog/TaskStep.cpp
        criterions/OptimismPessimismCriterion.cpp
        criterions/OptimismPessimismCriterion.h
        criterions/PrincipleOfInsufficientReason.cpp
        criterions/PrincipleOfInsufficientReason.h)
