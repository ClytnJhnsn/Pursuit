#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

class Entity {

    virtual ~Entity() {};

    std::vector<double> Entity::GetPos();

    std::vector<double> Entity::GetDir();

    double Entity::GetSpeed();

    void Entity::SetPos(std::vector<double> newPos);

    void Entity::SetDir(std::vector<double> newDir);

    void Entity::SetSpeed(double newSpeed);

    virtual void Update(double dt); 

protected:
// Entities should contain the following private memebers:
    std::vector<double> pos; 
    std::vector<double> dir;
    double speed;

};

#endif