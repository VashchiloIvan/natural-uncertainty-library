#ifndef NATURAL_UNCERTAINTY_PROBABILISTICALTERNATIVE_H
#define NATURAL_UNCERTAINTY_PROBABILISTICALTERNATIVE_H

#include <iostream>

class ProbabilisticAlternative {
private:
    std::string name;
    std::vector<double> marks;
    std::vector<double> probabilities;
public:
    ProbabilisticAlternative(std::string name, std::vector<double> marks, std::vector<double> probabilities);

    bool isValid() const;

    std::string getName() const;
    std::vector<double> getMarks();
    std::vector<double> getProbabilities();
    void setMarks(std::vector<double> marks);
    void setProbabilities(std::vector<double> probabilities);

    double getMathematicalExpectation();
};


#endif
