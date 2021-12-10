#ifndef PURSUIT_STRATEGY_H_
#define PURSUIT_STRATEGY_H_

#include "predator.h"

class PursuitStrategy {
public:
    virtual ~PursuitStrategy() {};

    virtual void Apply(Predator* predator);
};

#endif