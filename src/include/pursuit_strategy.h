#ifndef PURSUIT_STRATEGY_H_
#define PURSUIT_STRATEGY_H_

#include "entity.h"

class PursuitStrategy {
public:
    virtual void Apply(Entity* predator, double dt) = 0;

    virtual int GetStratID() = 0;
};

#endif