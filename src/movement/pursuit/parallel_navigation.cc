#include "../../include/parallel_navigation.h"
#include "../../include/entity.h"
#include <vector>
#include <cmath>
#include <iostream>
#define PREDICTED_ITERS 2
#define PURE_PURSUIT_RANGE 75

ParallelNavigation::ParallelNavigation() {
}

void ParallelNavigation::Apply(Entity* predator, double dt) {
    // Set direction vector in direction of prey
    std::vector<double> predPos = predator->GetPos();
    std::vector<double> preyPos = predator->GetOtherPos();


    if (GetDist(predPos, preyPos) > PURE_PURSUIT_RANGE) {
        // still far away, predict the position of the prey
        preyPos = PredictPreyPos(predator->GetOther(), dt);
    } else {
        // close enough, use pure pursuit
    }

    std::vector<double> newDir = {0.0, 0.0};
    for (int i = 0; i < 2; i++) {
        newDir[i] = preyPos[i] - predPos[i];
    }

    predator->SetDir(newDir);
}

int ParallelNavigation::GetStratID() {
    return 1;
}

std::vector<double> ParallelNavigation::PredictPreyPos(Entity* prey, double dt) {
    std::vector<double> newPos = prey->GetPos();
    std::vector<double> dir = prey->GetDir();
    double speed = prey->GetSpeed();
    
    for (int i = 0; i < 2; i++) {
        newPos[i] += speed * dir[i] * dt * PREDICTED_ITERS;
    }

    return newPos;
}

double ParallelNavigation::GetDist(std::vector<double> preyPos, std::vector<double> predPos) {
    std::vector<double> diff = {0.0, 0.0};

    for (int i = 0; i < 2; i++) {
        diff[i] = preyPos[i] - predPos[i];
    }

    return sqrt(diff[0]*diff[0] + diff[1]*diff[1]); 
}