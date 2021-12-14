#ifndef SIM_H_
#define SIM_H_

// #include "include/predator.h"
// #include "include/prey.h"
#include <vector>
#include "include/evasion_strategy.h"


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

    double GetPredDistanceTraveled();
    double GetPreyDistanceTraveled();

    void Print();

    std::vector<double> RandomPos();

    void SetEvasionStrat(EvasionStrategy* evasion_strat);

private:
    double time;
    double step;
    double range;

    Predator* predator;
    Prey* prey;
};

#endif