#include "predator.h"
// #include "../include/pursuit_strategy.h"
#include <vector>
#include <math.h>

Predator::Predator() {
    for (int i = 0; i <  pos.size(); i++) {
        pos.push_back(0.0);
    }
    dir = pos;
    speed = 0;
}

Predator::~Predator() {
    delete pursuit_strat;
}

std::vector<double> Predator::GetPos() { 
    return pos; 
}

void Predator::SetPos(std::vector<double> newPos) { 
    pos = newPos;
}

std::vector<double> Predator::GetDir() { 
    return dir; 
}

void Predator::SetDir(std::vector<double> newDir) { 
    // Normalize first 
    double norm = sqrt(newDir[0]*newDir[0] + newDir[1]*newDir[1] + newDir[2]*newDir[2]);
    if (norm != 0) {
        for (int i = 0; i < 3; i++) {
            newDir[i] = newDir[i] / norm;
        }
    }
    dir = newDir; 
}

double Predator::GetSpeed() { 
    return speed; 
}

void Predator::SetSpeed(double newSpeed) { 
    speed = newSpeed; 
}

std::vector<double> Predator::GetPreyPos() {
    return preyPos;
}

PursuitStrategy* Predator::GetPursuitStrat() {
    return pursuit_strat;
}

void Predator::SetPursuitStrat(PursuitStrategy* newStrat) {
    pursuit_strat = newStrat;
}

void Predator::Update(double dt) {
    if(pursuit_strat) {
        pursuit_strat->Apply(this);
    }

    for (int i = 0; i < 3; i++) {
        pos[i] += speed*dir[i];
    }
}