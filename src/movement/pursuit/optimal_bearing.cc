#include "../../include/optimal_bearing.h"
#include "../../include/deviated_pursuit.h"
#include "../../include/entity.h"
#include <vector>
#include <cmath>
#include <iostream>

OptimalBearing::OptimalBearing() {}

OptimalBearing::~OptimalBearing() {
    delete dev;
}

double OptimalBearing::GetAngle(std::vector<double> a, std::vector<double> b) {
    double dotProd = a[0]*b[0] + a[1]*b[1];
    double aNorm = sqrt(a[0]*a[0] + a[1]*a[1]);
    double bNorm = sqrt(b[0]*b[0] + b[1]*b[1]);
    int crossSign = 1;
    if (a[0]*b[1] - a[1]*b[0] < 0) { crossSign = -1; }
    return crossSign * acos(dotProd / (aNorm * bNorm));
}

void OptimalBearing::Apply(Entity* predator) {
    // This chunk was gonna be in the constructor but that fucked things up
    std::vector<double> predPos = predator->GetPos();
    std::vector<double> preyPos = predator->GetOtherPos();
    std::vector<double> baselineVec = {0.0, 0.0};
    for (int i = 0; i < 2; i++) {
        baselineVec[i] = preyPos[i] - predPos[i];
    }
    
    std::vector<double> preyDir = predator->GetOther()->GetDir();
    double predSpeed = predator->GetSpeed();
    double preySpeed = predator->GetOther()->GetSpeed();
    double b = GetAngle(preyDir, baselineVec);
    double util = (preySpeed * sin(b))/predSpeed;
    if (util > 1) { util = 1.0; }
    double a = asin(util);
    DeviatedPursuit* dev = new DeviatedPursuit(a);
    
    dev->Apply(predator);
}

int OptimalBearing::GetStratID() {
    return 2;
}