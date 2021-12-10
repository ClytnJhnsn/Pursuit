#ifndef PREY_H_
#define PREY_H_

#include "predator.h"
#include "evasion_strategy.h"
#include <vector>

class Prey {
public:
    Prey();
    ~Prey();

    std::vector<double> GetPos();
    void SetPos(std::vector<double> newPos);

    std::vector<double> GetDir();
    void SetDir(std::vector<double> newDir);

    double GetSpeed();
    void SetSpeed(double newSpeed);

    std::vector<double> GetPredatorPos();

    EvasionStrategy* GetEvasionStrat();
    void SetEvasionStrat(EvasionStrategy* evasion_strat);

    void Update(double dt); 

private:
    std::vector<double> pos; 
    std::vector<double> dir;
    double speed;
    EvasionStrategy* evasion_strat;

    Prey* predator;
    std::vector<double> predPos;

};

#endif