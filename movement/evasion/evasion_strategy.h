#ifndef EVASION_STRATEGY_H_
#define EVASION_STRATEGY_H_

#include "prey.h"

class EvasionStrategy {
    virtual ~EvasionStrategy() {};

    virtual void Apply(Prey* prey);
};

#endif