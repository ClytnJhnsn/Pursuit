#ifndef PARALLEL_NAVIGATION_H_
#define PARALLEL_NAVIGATION_H_

#include "entity.h"
#include "pursuit_strategy.h"

class ParallelNavigation : public PursuitStrategy {
public:
    ParallelNavigation();

    void Apply(Entity* predator, double dt);

    int GetStratID();

    std::vector<double> PredictPreyPos(Entity* prey, double dt);
    
    double GetDist(std::vector<double> preyPos, std::vector<double> predPos);
};

#endif