#ifndef PURE_EVASION_H_
#define PURE_EVASION_H_

#include "entity.h"
#include "evasion_strategy.h"

class PureEvasion : public EvasionStrategy {
public:
    PureEvasion() {};
    // ~PureEvasion();

    void Apply(Entity* prey);
};

#endif