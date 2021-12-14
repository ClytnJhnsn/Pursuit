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
    double dotProd = a[0]*b[0] + a[1]*b[1];
    double aNorm = sqrt(a[0]*a[0] + a[1]*a[1]);
    double bNorm = sqrt(b[0]*b[0] + b[1]*b[1]);
    return acos(dotProd / (aNorm * bNorm));
}


void ProportionalNavigation::Apply(Entity* predator) {
    
    // Turn by an amount proportional to prey's rotation in pred's visual field
    std::vector<double> predPos = predator->GetPos();
    std::vector<double> preyPos = predator->GetOtherPos();
    std::vector<double> base = {0.0, 0.0};
    for (int i = 0; i < 2; i++) {
        base[i] = preyPos[i] - predPos[i];
    }
    std::vector<double> predDir = predator->GetDir();
    double thisAng = GetAngle(base, predDir);

    // How do we guarantee a rotation in the direction of the prey's velocity
    predPos = Rotate(predDir, abs(thisAng - lastAng) * N);
    lastAng = thisAng;
    predator->SetDir(predPos);
}

int ProportionalNavigation::GetStratID() {
    return 1;
}