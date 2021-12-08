#ifndef PREDATOR_H_
#define PREDATOR_H_

#include "entity.h"
#include "prey.h"
#include "pursuit_strategy.h"
#include <vector>

class Predator : public Entity {

    Predator();

    ~Predator();

    // Predator(const Predator& otherPredator);

    std::vector<double> GetPreyPos();

    PursuitStrategy* GetPursuitStrat();

    void SetPursuitStrat(PursuitStrategy*);

    void Update(double dt); 

private:
    std::vector<double> pos; 
    std::vector<double> dir;
    double speed;
    PursuitStrategy* pursuit_strat;

    Prey* prey;

};

#endif