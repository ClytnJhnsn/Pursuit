#ifndef SIM_H_
#define SIM_H_

// #include "include/predator.h"
// #include "include/prey.h"
#include <vector>

class Predator;
class Prey;

class Sim {
public:
    Sim();

    ~Sim();

    std::vector<double> GetPredatorPos();
    std::vector<double> GetPreyPos();

    double GetDist();

    bool Caught(double range);

    void Update();

    void Print();

    std::vector<double> RandomPos();

private:
    double time;
    double step;
    double range;

    Predator* predator;
    Prey* prey;
};

#endif