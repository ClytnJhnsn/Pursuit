#ifndef PURE_PURSUIT_H_
#define PURE_PURSUIT_H_

#include "entity.h"
#include "pursuit_strategy.h"

class PurePursuit : public PursuitStrategy {
public:
    PurePursuit() {};
    // ~PurePursuit();

    void SanityCheck();

    void Apply(Entity* predator);
};

#endif