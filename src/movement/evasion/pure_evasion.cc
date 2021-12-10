#include "pure_evasion.h"
// #include "../../../include/prey.h"
#include <vector>
#include <cmath>

void PureEvasion::Apply(Prey* prey) {
    // Set direction vector in direction of prey
    std::vector<double> preyPos = prey->GetPos();
    std::vector<double> predPos = prey->GetPredatorPos();

    std::vector<double> newDir = {0.0, 0.0, 0.0};
    for (int i = 0; i < 3; i++) {
        newDir[i] = preyPos[i] - predPos[i];
    }

    prey->SetDir(newDir);
}
