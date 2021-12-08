#ifndef PREY_H_
#define PREY_H_

#include "entity.h"
#include "predator.h"
#include "evasion_strategy.h"
#include <vector>

class Prey : public Entity {

    Prey();

    ~Prey();

    // Prey(const Prey& otherPrey);

    std::vector<double> GetPredatorPos();

    EvasionStrategy* GetEvasionStrat();

    void SetEvasionStrat(const EvasionStrat* newStrat);

    void Update(double dt); 

private:
    std::vector<double> pos; 
    std::vector<double> dir;
    double speed;
    EvasionStrategy* evasion_strat;

    Predator* predator;

};

#endif