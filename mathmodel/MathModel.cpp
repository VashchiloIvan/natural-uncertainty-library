#include "MathModel.h"
#include <utility>
#include <unordered_set>

MathModel::MathModel() = default;

MathModel::MathModel(std::vector<Alternative> alternatives, std::vector<Uncertainty> uncertainties) {
    this->alternatives = std::move(alternatives);
    this->uncertainties = std::move(uncertainties);
}

MathModel::MathModel(const MathModel &mathModel) {
    this->alternatives = mathModel.alternatives;
    this->uncertainties = mathModel.uncertainties;
}

void MathModel::setAlternatives(std::vector<Alternative> alternatives) {
    this->alternatives = std::move(alternatives);
}

void MathModel::setUncertainties(std::vector<Uncertainty> uncertainties) {
    this->uncertainties = std::move(uncertainties);
}

bool MathModel::isValid() {
    auto uncertaintiesCount = uncertainties.size();

    for (auto alternative: alternatives) {
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

std::vector<Alternative> MathModel::getAlternatives() {
    return alternatives;
}

std::vector<Uncertainty> MathModel::getUncertainties() {
    return uncertainties;
}
