#ifndef DEVIATED_PURSUIT_H_
#define DEVIATED_PURSUIT_H_

#include "entity.h"
#include "pursuit_strategy.h"

class DeviatedPursuit : public PursuitStrategy {
public:
    DeviatedPursuit(double initA);

    std::vector<double> Rotate(std::vector<double> vec, double a);

    void Apply(Entity* predator);

    int GetStratID();

private:
    double a;
};

#endif