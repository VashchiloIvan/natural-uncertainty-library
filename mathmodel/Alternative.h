#ifndef NATURAL_UNCERTAINTY_ALTERNATIVE_H
#define NATURAL_UNCERTAINTY_ALTERNATIVE_H

#include <iostream>

class Alternative {
private:
    std::string name;
    std::vector<double> marks;
public:
    Alternative(std::string name, std::vector<double> marks);

    std::string getName() const;
    std::vector<double> getMarks();
    void setMarks(std::vector<double> marks);

    double minMark();
    double maxMark();
    double sumOfMarks();
    double avgOfMarks();
};


#endif
