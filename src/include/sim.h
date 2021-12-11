#ifndef SIM_H_
#define SIM_H_

#include "../include/predator.h"
#include "../include/prey.h"
#include <vector>

class Sim {
public:
    Sim();

    ~Sim();

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