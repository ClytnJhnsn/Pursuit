#ifndef SENSORY_PURE_EVASION_H_
#define SENSORY_PURE_EVASION_H_

#include "entity.h"
#include "evasion_strategy.h"

class SensoryPureEvasion : public EvasionStrategy {
public:
    SensoryPureEvasion() {};

    void Apply(Entity* prey, double dt);

    int GetStratID();

    double GetDist(std::vector<double> preyPos, std::vector<double> predPos);
};

#endif