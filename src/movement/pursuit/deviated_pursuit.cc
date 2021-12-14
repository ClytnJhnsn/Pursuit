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
    std::vector<double> predPos, preyPos, base, newDir, preyDir;
    predPos = predator->GetPos();
    preyPos = predator->GetOtherPos();
    base = {0.0, 0.0};
    for (int i = 0; i < 2; i++) {
        base[i] = preyPos[i] - predPos[i];
    }

    // Identify the correct direction of rotation
    preyDir = predator->GetOther()->GetDir();
    int rotSign = 1;
    // This represents the z component of (base) X (preyDir) if we map them to xy-plane in 3d space
    double z = base[0]*preyDir[1] - base[1]*preyDir[0];
    if (z < 0) { rotSign = -1; }

    newDir = Rotate(base, a);
    predator->SetDir(newDir);
}

int DeviatedPursuit::GetStratID() {
    return 1;
}