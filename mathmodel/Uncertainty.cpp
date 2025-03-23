#include "Uncertainty.h"

#include <utility>

Uncertainty::Uncertainty(std::string name) : name(std::move(name)) {}

std::string Uncertainty::getName() {
    return name;
}
