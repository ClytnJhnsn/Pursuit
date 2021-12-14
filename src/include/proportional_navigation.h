#ifndef PROPORTIONAL_NAVIGATION_H_
#define PROPORTIONAL_NAVIGATION_H_

#include "entity.h"
#include "pursuit_strategy.h"

class ProportionalNavigation : public PursuitStrategy {
public:
    ProportionalNavigation(double initA);

    std::vector<double> Rotate(std::vector<double> vec, double a);
    
    double GetAngle(std::vector<double> a, std::vector<double> b);

    void Apply(Entity* predator);

    int GetStratID();

private:
    double N;
    double lastAng;
};

#endif