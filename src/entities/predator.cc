#include "../include/predator.h"
#include "../include/prey.h"
#include "../include/pursuit_strategy.h"
#include "../include/pure_pursuit.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <iomanip>


Predator::Predator() {
    for (int i = 0; i < 2; i++) {
        pos.push_back(0.0);
    }
    std::vector<double> newDir = {0.0, 1.0};
    SetDir(newDir);
    speed = 0;
    distance_traveled = 0;

    PursuitStrategy* pure = new PurePursuit();
    SetPursuitStrat(pure);
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
    return prey->GetPos();
}

Entity* Predator::GetOther() {
    return prey;
}

void Predator::SetOther(Entity* other) {
    prey = other;
}

std::vector<double> Predator::GetDir() { 
    return dir; 
}

void Predator::SetDir(std::vector<double> newDir) { 
    double norm = sqrt(newDir[0]*newDir[0] + newDir[1]*newDir[1]);
    if (norm != 0) {
        for (int i = 0; i < 2; i++) {
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

double Predator::GetDistanceTraveled() {
    return distance_traveled;
}

void Predator::Update(double dt) {
    pursuit_strat->Apply(this, dt);

    for (int i = 0; i < 2; i++) {
        pos[i] += speed*dir[i]*dt;;
    }

    distance_traveled += speed*dt; 
}

void Predator::Print() {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    
    std::cout << "Predator:\n--> Pos: [";
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