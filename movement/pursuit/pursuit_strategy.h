#ifndef PURSUIT_STRATEGY_H_
#define PURSUIT_STRATEGY_H_

#include "../../entities/predator.h"

class PursuitStrategy {
    virtual ~PursuitStrategy() {};

    virtual void Apply(Predator* predator);
};

#endif