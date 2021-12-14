#include "../../include/deviated_pursuit.h"
#include "../../include/entity.h"
#include <vector>
#include <cmath>
#include <iostream>

DeviatedPursuit::DeviatedPursuit(double initA) {
    a = initA;
}

std::vector<double> DeviatedPursuit::Rotate(std::vector<double> vec, double a) {
    std::vector<double> newVec = {vec[0]*cos(a) - vec[1]*sin(a), vec[0]*sin(a) + vec[1]*cos(a)};
    return newVec;
}


void DeviatedPursuit::Apply(Entity* predator) {
    // Offset direction vector to prey by a
    std::vector<double> predPos = predator->GetPos();
    std::vector<double> preyPos = predator->GetOtherPos();
    std::vector<double> newDir = {0.0, 0.0};
    for (int i = 0; i < 2; i++) {
        newDir[i] = preyPos[i] - predPos[i];
    }
    newDir = Rotate(newDir, a);
    predator->SetDir(newDir);
}

int DeviatedPursuit::GetStratID() {
    return 1;
}