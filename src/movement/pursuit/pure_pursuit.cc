#include "../../include/pure_pursuit.h"
#include "../../include/entity.h"
#include <vector>
#include <cmath>
#include <iostream>

void PurePursuit::SanityCheck() {
    std::cout << "you're fucking crazy" << std::endl;
}

void PurePursuit::Apply(Entity* predator) {
    // Set direction vector in direction of prey
    std::vector<double> predPos = predator->GetPos();
    std::vector<double> preyPos = predator->GetOtherPos();

    std::vector<double> newDir = {0.0, 0.0, 0.0};
    for (int i = 0; i < 3; i++) {
        newDir[i] = preyPos[i] - predPos[i];
    }

    predator->SetDir(newDir);
}