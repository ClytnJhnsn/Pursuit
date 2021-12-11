#include "sim.h"
#include "include/predator.h"
#include "include/prey.h"
#include <vector>
#include <cmath>
#include <iostream>

Sim::Sim() {
    // Initialize Simulation variables
    time = 0.0;
    step = 0.5;
    range = 2.0;

    // Initialize entities
    predator = new Predator();
    prey = new Prey();
    predator->SetSpeed(2.5);
    prey->SetSpeed(1.0);
    std::vector<double> util;
    util = {0.0, 10.0, 0.0};
    prey->SetPos(util);
}

Sim::~Sim() {
    delete predator;
    delete prey;
}

std::vector<double> Sim::GetPredatorPos() {
    return predator->GetPos(); 
}

std::vector<double> Sim::GetPreyPos() {
    return prey->GetPos(); 
}

double Sim::GetDist() {
    std::vector<double> preyPos, predPos, diff;
    diff = {0.0, 0.0, 0.0};
    preyPos = GetPreyPos();
    predPos = GetPredatorPos();

    for (int i = 0; i < 3; i++) {
        diff[i] = preyPos[i] - predPos[i];
    }

    return sqrt(diff[0]*diff[0] + diff[1]*diff[1] + diff[2]*diff[2]); 
}

void Sim::Update() {
    if (!Caught(range)) {
        // Does the sequence of these events matter? (Probably.) May have to store data 
        // regarding initial positions to make these updates "simultaneous" 
        predator->Update(0.5);
        prey->Update(0.5);
        // std::cout << "simdate" << std::endl;
        time += step;
    }
}

bool Sim::Caught(double range) {
    // std::vector<double> preyPos, predPos, diff;
    // diff = {0.0, 0.0, 0.0};
    // preyPos = prey->GetPos();
    // predPos = predator->GetPos();

    // for (int i = 0; i < 3; i++) {
    //     diff[i] = preyPos[i] - predPos[i];
    // }

    // return sqrt(diff[0]*diff[0] + diff[1]*diff[1] + diff[2]*diff[2]); 
    return (GetDist() <= range);
}