#include "ProbabilisticModel.h"
#include <utility>
#include <unordered_set>

ProbabilisticModel::ProbabilisticModel() = default;

ProbabilisticModel::ProbabilisticModel(std::vector<ProbabilisticAlternative> ProbabilisticAlternatives, std::vector<Uncertainty> uncertainties) {
    this->alternatives = std::move(ProbabilisticAlternatives);
    this->uncertainties = std::move(uncertainties);
}

ProbabilisticModel::ProbabilisticModel(const ProbabilisticModel &mathModel) {
    this->alternatives = mathModel.alternatives;
    this->uncertainties = mathModel.uncertainties;
}

void ProbabilisticModel::setAlternatives(std::vector<ProbabilisticAlternative> alternatives) {
    this->alternatives = std::move(alternatives);
}

void ProbabilisticModel::setUncertainties(std::vector<Uncertainty> uncertainties) {
    this->uncertainties = std::move(uncertainties);
}

bool ProbabilisticModel::isValid() {
    auto uncertaintiesCount = uncertainties.size();

    for (auto alternative: alternatives) {
        if (!alternative.isValid()) {
            return false;
        }

        if (alternative.getMarks().size() != uncertaintiesCount) {
            return false;
        }
    }

    if (alternatives.size() == 0 || uncertaintiesCount == 0) {
        return false;
    }

    std::unordered_set<std::string> names;
    for (const auto &alternative: alternatives) {
        if (names.find(alternative.getName()) != names.end()) {
            return false;
        }

        names.insert(alternative.getName());
    }

    names.clear();

    for (const auto &uncertainty: uncertainties) {
        if (names.find(uncertainty.getName()) != names.end()) {
            return false;
        }

        names.insert(uncertainty.getName());
    }

    return true;
}

std::vector<ProbabilisticAlternative> ProbabilisticModel::getAlternatives() {
    return alternatives;
}

std::vector<Uncertainty> ProbabilisticModel::getUncertainties() {
    return uncertainties;
}
