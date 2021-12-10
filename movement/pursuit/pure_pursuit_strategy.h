#ifndef PURE_PURSUIT_STRATEGY_H_
#define PURE_PURSUIT_STRATEGY_H_

#include "pursuit_strategy.h"

class PurePursuitStrategy : public PursuitStrategy {
public:
    PurePursuitStrategy() {};
    ~PurePursuitStrategy() {};

    void Apply(Predator* predator);
};

#endif