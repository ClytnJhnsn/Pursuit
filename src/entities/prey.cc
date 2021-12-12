#include "../include/prey.h"
#include "../include/predator.h"
#include "../include/evasion_strategy.h"
#include "../include/pure_evasion.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <iomanip>


Prey::Prey() {
    for (int i = 0; i < 3; i++) {
        pos.push_back(0.0);
    }
    std::vector<double> newDir = {0.0, 1.0, 0.0};
    SetDir(newDir);
    speed = 0;

    EvasionStrategy* pure = new PureEvasion;
    SetEvasionStrat(pure);
}

Prey::~Prey() {
    delete evasion_strat;
    delete predator;
}

std::vector<double> Prey::GetPos() { 
    return pos; 
}

void Prey::SetPos(std::vector<double> newPos) { 
    pos = newPos;
}

std::vector<double> Prey::GetOtherPos() {
    return predator->GetPos();
}

Entity* Prey::GetOther() {
    return predator;
}

void Prey::SetOther(Entity* other) {
    predator = other;
}

std::vector<double> Prey::GetDir() { 
    return dir; 
}

void Prey::SetDir(std::vector<double> newDir) { 
    // Normalize first 
    double norm = sqrt(newDir[0]*newDir[0] + newDir[1]*newDir[1] + newDir[2]*newDir[2]);
    if (norm != 0) {
        for (int i = 0; i < 3; i++) {
            newDir[i] = newDir[i] / norm;
        }
    }
    dir = newDir; 
}

double Prey::GetSpeed() { 
    return speed; 
}

void Prey::SetSpeed(double newSpeed) { 
    speed = newSpeed; 
}

EvasionStrategy* Prey::GetEvasionStrat() {
    return evasion_strat;
}

void Prey::SetEvasionStrat(EvasionStrategy* newStrat) {
    evasion_strat = newStrat;
}

void Prey::Update(double dt) {
    evasion_strat->Apply(this);

    for (int i = 0; i < 3; i++) {
        pos[i] += speed*dir[i]*dt;
    }
}

void Prey::Print() {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    
    std::cout << "Prey:\n--> Pos: [";
    for (auto i = pos.begin(); i != pos.end(); ++i) {
        std::cout << *i ;
        if (std::next(i) == (pos.end())) {
            std::cout << "]" << std::endl;
        } else {
            std::cout << ", ";
        }
    }

    std::cout << "--> Dir: [";
    for (auto i = dir.begin(); i != dir.end(); ++i) {
        std::cout << *i ;
        if (std::next(i) == (dir.end())) {
            std::cout << "]" << std::endl;
        } else {
            std::cout << ", ";
        }
    }
}