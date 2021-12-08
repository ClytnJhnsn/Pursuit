#ifndef PURSUIT_STRATEGY_H_
#define PURSUIT_STRATEGY_H_

#include "predator.h"
// Probably end up deleting this file anyways, no need to inherit yet
#include "movement_strategy.h"

class PursuitStrategy : public MovementStrategy {
    virtual ~EvasionStrategy() {};

    virtual void Apply(Predator* predator);

    // Probably won't need
    // virtual void operator=(const PursuitStrategy& otherStrat) {};

};

#endif