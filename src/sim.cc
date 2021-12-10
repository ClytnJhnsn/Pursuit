#include "sim.h"
// #include "entities/predator.h"
// #include "entities/prey.h"
#include <vector>
#include <cmath>

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
    std::vector<double> preyPos, predPos, diff;
    preyPos = prey->GetPos();
    predPos = pred->GetPos();

    for (int i = 0; i < 3; i++) {
        diff[i] = preyPos[i] - predPos[i];
    }

    double dist = sqrt(diff[0]*diff[0] + diff[1]*diff[1] + diff[2]*diff[2]);    
    return (dist <= range);
}