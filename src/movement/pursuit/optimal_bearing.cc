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

    double dot = dotProd / (aNorm * bNorm);
    double acosine;

    if (dot > 0.99) {
        acosine = 0;
    } else {
        acosine = acos(dot);
    }

    return crossSign * acosine;
}

std::vector<double> OptimalBearing::Rotate(std::vector<double> vec, double a) {
    std::vector<double> newVec = {vec[0]*cos(a) - vec[1]*sin(a), vec[0]*sin(a) + vec[1]*cos(a)};
    return newVec;
}

void OptimalBearing::Apply(Entity* predator) {
    // This chunk was gonna be in the constructor but that fucked things up
    std::vector<double> predPos, preyPos, base, preyDir, newDir;
    predPos = predator->GetPos();
    preyPos = predator->GetOtherPos();
    base = {0.0, 0.0};

    for (int i = 0; i < 2; i++) {
        base[i] = preyPos[i] - predPos[i];
    }
    
    double predSpeed, preySpeed, b, util, a;
    preyDir = predator->GetOther()->GetDir();
    predSpeed = predator->GetSpeed();
    preySpeed = predator->GetOther()->GetSpeed();

    b = GetAngle(base, preyDir);
    util = (preySpeed / predSpeed) * sin(b);

    if (util > 1) { util = 1.0; }
    a = asin(util);

    newDir = Rotate(base, a);
    predator->SetDir(newDir);
}

int OptimalBearing::GetStratID() {
    return 2;
}