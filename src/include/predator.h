#ifndef PREDATOR_H_
#define PREDATOR_H_

// #include "prey.h"
#include "entity.h"
#include "pursuit_strategy.h"
#include <vector>

class Entity;

class Predator : public Entity {
public:
    Predator();
    ~Predator();

    std::vector<double> GetPos();
    void SetPos(std::vector<double> newPos);

    std::vector<double> GetOtherPos();

    // Entity* GetOther();
    void SetOther(Entity* other);

    std::vector<double> GetDir();
    void SetDir(std::vector<double> newDir);

    double GetSpeed();
    void SetSpeed(double newSpeed);

    PursuitStrategy* GetPursuitStrat();
    void SetPursuitStrat(PursuitStrategy* newStrat);

    void Update(double dt); 

private:
    std::vector<double> pos; 
    std::vector<double> dir;
    double speed;
    PursuitStrategy* pursuit_strat;

    Entity* prey;
    std::vector<double> preyPos;

};

#endif