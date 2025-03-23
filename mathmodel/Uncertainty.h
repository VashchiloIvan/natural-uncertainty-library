#ifndef NATURAL_UNCERTAINTY_UNCERTAINTY_H
#define NATURAL_UNCERTAINTY_UNCERTAINTY_H

#include <iostream>

class Uncertainty {
private:
    std::string name;
public:
    Uncertainty(std::string name);

    std::string getName() const;
};


#endif
