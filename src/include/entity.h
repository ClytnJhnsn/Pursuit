#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

class Entity {
public:
    // virtual ~Entity();

    virtual std::vector<double> GetPos() = 0;
    virtual void SetPos(std::vector<double> newPos) = 0;

    virtual std::vector<double> GetOtherPos() = 0;

    virtual Entity* GetOther() = 0;
    virtual void SetOther(Entity* other) = 0;

    virtual std::vector<double> GetDir() = 0;
    virtual void SetDir(std::vector<double> newDir) = 0;

    virtual double GetSpeed() = 0;
    virtual void SetSpeed(double newSpeed) = 0;

    double GetDistanceTraveled();

    virtual void Update(double dt) = 0; 

    virtual void Print() = 0;

// Entities should contain the following private memebers:
    // std::vector<double> pos; 
    // std::vector<double> dir;
    // double speed;

};

#endif