#ifndef PURE_EVASION_STRATEGY_H_
#define PURE_EVASION_STRATEGY_H_

#include "evasion_strategy.h"

class PureEvasionStrategy : public EvasionStrategy {
public:
    PureEvasionStrategy() {};
    ~PureEvasionStrategy() {};

    void Apply(Prey* prey);
};

#endif