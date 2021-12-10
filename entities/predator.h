#ifndef PREDATOR_H_
#define PREDATOR_H_

#include "prey.h"
#include "movement/pursuit/pursuit_strategy.h"
#include <vector>

class Predator {
public:
    Predator();
    ~Predator();

    std::vector<double> GetPos();
    void SetPos(std::vector<double> newPos);

    std::vector<double> GetDir();
    void SetDir(std::vector<double> newDir);

    double GetSpeed();
    void SetSpeed(double newSpeed);

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
    std::vector<double> preyPos;

};

#endif