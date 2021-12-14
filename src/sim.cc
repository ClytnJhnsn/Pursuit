#include "sim.h"
#include "include/predator.h"
#include "include/prey.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <random>
#include <chrono> //For system_clock

Sim::Sim() {
    // Initialize Simulation variables
    time = 0.0;
    step = 0.5;
    range = 2.0;

    // Initialize entities
    predator = new Predator();
    prey = new Prey();

    predator->SetOther(prey);
    prey->SetOther(predator);

    predator->SetSpeed(2.5);
    prey->SetSpeed(1.0);

    prey->SetPos(RandomPos());
    predator->SetPos(RandomPos());
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
    diff = {0.0, 0.0};
    preyPos = GetPreyPos();
    predPos = GetPredatorPos();

    for (int i = 0; i < 3; i++) {
        diff[i] = preyPos[i] - predPos[i];
    }

    return sqrt(diff[0]*diff[0] + diff[1]*diff[1]); 
}

double Sim::GetPredDistanceTraveled() {
    return predator->GetDistanceTraveled();
}
double Sim::GetPreyDistanceTraveled() {
    return prey->GetDistanceTraveled();
}

void Sim::Update() {
    if (!Caught(range)) {
        // Does the sequence of these events matter? (Probably.) May have to store data 
        // regarding initial positions to make these updates "simultaneous" 
        predator->Update(0.5);
        prey->Update(0.5);
        time += step;
    }
}

bool Sim::Caught(double range) {
    return (GetDist() <= range);
}

void Sim::Print() {
    prey->Print();
    predator->Print();
}

std::vector<double> Sim::RandomPos() {
    std::vector<double> vec;
    double lower_bound = -500;
    double upper_bound = 500;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
    std::default_random_engine re(seed);


    for (int i = 0; i < 2; i++) {
        vec.push_back(unif(re));
    }

    return vec;
}

void Sim::SetEvasionStrat(EvasionStrategy* evasion_strat) {
    prey->SetEvasionStrat(evasion_strat);
}

void Sim::SetPursuitStrat(PursuitStrategy* pursuit_strategy) {
    predator->SetPursuitStrat(pursuit_strategy);
}

