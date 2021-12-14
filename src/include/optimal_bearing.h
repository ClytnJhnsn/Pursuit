#ifndef OPTIMAL_BEARING_H_
#define OPTIMAL_BEARING_H_

#include "entity.h"
#include "pursuit_strategy.h"
#include "deviated_pursuit.h"

class OptimalBearing : public PursuitStrategy {
public:
    OptimalBearing();

    double GetAngle(std::vector<double> a, std::vector<double> b);

    void Apply(Entity* predator);

    int GetStratID();

private:
    DeviatedPursuit* dev;
};

#endif