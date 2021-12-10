#ifndef PURE_PURSUIT_H_
#define PURE_PURSUIT_H_

#include "pursuit_strategy.h"

class PurePursuit : public PursuitStrategy {
public:
    PurePursuit() {};
    ~PurePursuit() {};

    void Apply(Predator* predator);
};

#endif