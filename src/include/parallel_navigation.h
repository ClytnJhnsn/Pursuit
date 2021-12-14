#ifndef PARALLEL_NAVIGATION_H_
#define PARALLEL_NAVIGATION_H_

#include "entity.h"
#include "pursuit_strategy.h"

class ParallelNavigation : public PursuitStrategy {
public:
    ParallelNavigation();

    void Apply(Entity* predator);

    int GetStratID();
};

#endif