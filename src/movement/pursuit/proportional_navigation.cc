#include "../../include/proportional_navigation.h"
#include "../../include/entity.h"
#include <vector>
#include <cmath>
#include <iostream>

ProportionalNavigation::ProportionalNavigation(double initN) {
    N = initN;
    lastAng = 0.0;
}

std::vector<double> ProportionalNavigation::Rotate(std::vector<double> vec, double a) {
    // We need to rotate negative instead of positive sometimes
    std::vector<double> newVec = {vec[0]*cos(a) - vec[1]*sin(a), vec[0]*sin(a) + vec[1]*cos(a)};
    return newVec;
}

double ProportionalNavigation::GetAngle(std::vector<double> a, std::vector<double> b) {
    double dotProd, aNorm, bNorm;
    dotProd = a[0]*b[0] + a[1]*b[1];
    aNorm = sqrt(a[0]*a[0] + a[1]*a[1]);
    bNorm = sqrt(b[0]*b[0] + b[1]*b[1]);
    int crossSign = 1;
    if (a[0]*b[1] - a[1]*b[0] < 0) { crossSign = -1; }
    return acos(dotProd / (aNorm * bNorm));
}

void ProportionalNavigation::Apply(Entity* predator) {
    // Turn by an amount proportional to prey's rotation in pred's visual field
    std::vector<double> predPos, preyPos, base, predDir, preyDir, newDir;
    predPos = predator->GetPos();
    preyPos = predator->GetOtherPos();
    base = {0.0, 0.0};
    for (int i = 0; i < 2; i++) {
        base[i] = preyPos[i] - predPos[i];
    }
    predDir = predator->GetDir();
    double thisAng = GetAngle(base, predDir);

    // Correct the direction of rotation
    preyDir = predator->GetOther()->GetDir();
    int rotSign = 1;
    double z = base[0]*preyDir[1] - base[1]*preyDir[0];
    if (z < 0) { rotSign = -1; }

    newDir = Rotate(predDir, abs(thisAng - lastAng) * N * rotSign);
    lastAng = thisAng;
    predator->SetDir(newDir);
}

int ProportionalNavigation::GetStratID() {
    return 3;
}