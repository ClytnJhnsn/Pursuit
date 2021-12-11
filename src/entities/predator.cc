#include "../include/predator.h"
#include "../include/prey.h"
#include "../include/pursuit_strategy.h"
#include "../include/pure_pursuit.h"
#include <vector>
#include <math.h>
#include <iostream>

Predator::Predator() {
    for (int i = 0; i < 3; i++) {
        pos.push_back(0.0);
    }
    std::vector<double> newDir = {0.0, 1.0, 0.0};
    SetDir(newDir);
    dir = pos;
    speed = 0;

    PursuitStrategy* pure = new PurePursuit;
    SetPursuitStrat(pure);
    delete pure;
}

Predator::~Predator() {
    delete pursuit_strat;
    delete prey;
}

std::vector<double> Predator::GetPos() { 
    return pos; 
}

void Predator::SetPos(std::vector<double> newPos) { 
    pos = newPos;
}

std::vector<double> Predator::GetOtherPos() {
    return preyPos;
}

std::vector<double> Predator::GetDir() { 
    return dir; 
}

void Predator::SetDir(std::vector<double> newDir) { 
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

PursuitStrategy* Predator::GetPursuitStrat() {
    return pursuit_strat;
}

void Predator::SetPursuitStrat(PursuitStrategy* newStrat) {
    pursuit_strat = newStrat;
}

void Predator::Update(double dt) {
    if(pursuit_strat) {
        std::vector<int> poop;
        int stopper = poop[10];
        pursuit_strat->Apply(this);
    }

    for (int i = 0; i < 3; i++) {
        pos[i] += speed*dir[i];
    }
    // std::cout << "preddate" << std::endl;
}