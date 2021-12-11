#include "../include/prey.h"
#include "../include/predator.h"
#include "../include/evasion_strategy.h"
#include "../include/pure_evasion.h"
#include <vector>
#include <math.h>
#include <iostream>

Prey::Prey() {
    for (int i = 0; i < 3; i++) {
        pos.push_back(0.0);
    }
    std::vector<double> newDir = {0.0, 1.0, 0.0};
    SetDir(newDir);
    dir = pos;
    speed = 0;

    EvasionStrategy* pure = new PureEvasion;
    SetEvasionStrat(pure);
    delete pure;
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
    return predPos;
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

// Probably won't need
// Prey::Prey operator=(const Prey& otherPrey) {
//     pos = otherPrey->GetPos();
//     dir = otherPrey->GetDir();
//     speed = otherPrey->GetSpeed();
//     evasion_strat = otherPrey->GetMovementStrat();
// }

void Prey::Update(double dt) {
    if(evasion_strat) {
        evasion_strat->Apply(this);
    }

    for (int i = 0; i < 3; i++) {
        pos[i] += speed*dir[i];
    }
    // std::cout << "preydate" << std::endl;
    // std::vector<int> poop;
    // int stopper = poop[10];

}