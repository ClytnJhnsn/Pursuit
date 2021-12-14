#ifndef EVASION_STRATEGY_H_
#define EVASION_STRATEGY_H_

#include "entity.h"

class EvasionStrategy {
public:
    // virtual ~EvasionStrategy();

    virtual void Apply(Entity* prey) = 0;

    virtual int GetStratID() = 0;
};

#endif