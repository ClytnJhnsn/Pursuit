#include "../../include/sensory_pure_evasion.h"
#include "../../include/entity.h"
#include <vector>
#include <cmath>
#define SENSORY_RANGE 100

void SensoryPureEvasion::Apply(Entity* prey) {
    // Set direction vector in direction of prey
    std::vector<double> preyPos = prey->GetPos();
    std::vector<double> predPos = prey->GetOtherPos();

    if (GetDist(preyPos, predPos) < SENSORY_RANGE) {
        std::vector<double> newDir = {0.0, 0.0};
        for (int i = 0; i < 2; i++) {
            newDir[i] = preyPos[i] - predPos[i];
        }
        prey->SetDir(newDir);
    }
}

double SensoryPureEvasion::GetDist(std::vector<double> preyPos, std::vector<double> predPos) {
    std::vector<double> diff = {0.0, 0.0};

    for (int i = 0; i < 2; i++) {
        diff[i] = preyPos[i] - predPos[i];
    }

    return sqrt(diff[0]*diff[0] + diff[1]*diff[1]); 
}

int SensoryPureEvasion::GetStratID() {
    return 1;
}