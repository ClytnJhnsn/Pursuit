#ifndef SENSORY_STOCHASTIC_EVASION_H_
#define SENSORY_STOCHASTIC_EVASION_H_

#include "entity.h"
#include "evasion_strategy.h"

class SensoryStochasticEvasion : public EvasionStrategy {
public:
    SensoryStochasticEvasion();

    void Apply(Entity* prey, double dt);

    int GetStratID();

    double GetDist(std::vector<double> preyPos, std::vector<double> predPos);

private:
    int isWithinEvasionRangeFlag; // So the prey only evades once at the range threshold.
                                  // if the distance is increased to be past that threshold 
                                  // the flag is reset for another evasion
};

#endif