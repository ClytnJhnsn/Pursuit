#ifndef PURSUIT_STRATEGY_H_
#define PURSUIT_STRATEGY_H_

#include "entity.h"

class PursuitStrategy {
public:
    // virtual ~PursuitStrategy() {};

    virtual void SanityCheck() = 0;
    virtual void Apply(Entity* predator) = 0;
};

#endif