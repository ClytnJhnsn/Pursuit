#ifndef SIM_H_
#define SIM_H_

#include "entities/predator.h"
#include "entities/prey.h"
#include <vector>

class Sim {
    // Have yet to figure out how we're gonna create Simulations 
    // (What parameters do we take, what do we set to default>)
    Sim();

    ~Sim()

    bool Caught(double range);

    void Update();

private:
    double time;
    double step;
    double range;
    // For extension, these could be turned into an array of entities
    Predator* predator;
    Prey* prey;
};

#endif