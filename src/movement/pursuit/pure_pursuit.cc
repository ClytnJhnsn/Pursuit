#include "../../../include/pure_pursuit.h"
// #include "../../../include/predator.h"
#include <vector>
#include <cmath>

void PurePursuit::Apply(Predator* predator) {
    // Set direction vector in direction of prey
    std::vector<double> predPos = predator->GetPos();
    std::vector<double> preyPos = predator->GetPreyPos();

    std::vector<double> newDir = {0.0, 0.0, 0.0};
    for (int i = 0; i < 3; i++) {
        newDir[i] = preyPos[i] - predPos[i];
    }

    predator->SetDir(newDir);
}