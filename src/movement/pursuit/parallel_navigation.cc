#include "../../include/parallel_navigation.h"
#include "../../include/entity.h"
#include <vector>
#include <cmath>
#include <iostream>

ParallelNavigation::ParallelNavigation() {
}

void ParallelNavigation::Apply(Entity* predator) {
    // Set direction vector in direction of prey
    std::vector<double> predPos = predator->GetPos();
    std::vector<double> preyPos = predator->GetOtherPos();
    std::vector<double> newDir = {0.0, 0.0};

    predator->SetDir(newDir);
}