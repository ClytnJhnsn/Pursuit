#ifndef PURE_EVASION_H_
#define PURE_EVASION_H_

#include "evasion_strategy.h"

class PureEvasion : public EvasionStrategy {
public:
    PureEvasion() {};
    ~PureEvasion() {};

    void Apply(Prey* prey);
};

#endif