#ifndef EVASION_STRATEGY_H_
#define EVASION_STRATEGY_H_

#include "prey.h"
// Probably end up deleting this file anyways, no need to inherit yet
#include "movement_strategy.h"

class EvasionStrategy : public MovementStrategy {
    virtual ~EvasionStrategy() {};

    virtual void Apply(Prey* prey);

    // Probably won't need
    // virtual void operator=(const EvasionStrategy& otherStrat) {};

};

#endif