#ifndef PREY_H_
#define PREY_H_

#include "entity.h"
// #include "predator.h"
#include "evasion_strategy.h"
#include <vector>

class Predator;

class Prey : public Entity {
public:
    Prey();
    ~Prey();

    std::vector<double> GetPos();
    void SetPos(std::vector<double> newPos);
    
    std::vector<double> GetOtherPos();

    Entity* GetOther();
    void SetOther(Entity* other);

    std::vector<double> GetDir();
    void SetDir(std::vector<double> newDir);

    double GetSpeed();
    void SetSpeed(double newSpeed);
    
    EvasionStrategy* GetEvasionStrat();
    void SetEvasionStrat(EvasionStrategy* evasion_strat);

    void Update(double dt); 

    void Print();

    void RandomizeDir();

private:
    std::vector<double> pos; 
    std::vector<double> dir;
    double speed;
    EvasionStrategy* evasion_strat;

    Entity* predator;
    std::vector<double> predPos;

};

#endif