#include "../../include/pure_evasion.h"
#include "../../include/entity.h"
#include <vector>
#include <cmath>

void PureEvasion::Apply(Entity* prey) {
    // Set direction vector in direction of prey
    std::vector<double> preyPos = prey->GetPos();
    std::vector<double> predPos = prey->GetOtherPos();

    std::vector<double> newDir = {0.0, 0.0, 0.0};
    for (int i = 0; i < 3; i++) {
        newDir[i] = preyPos[i] - predPos[i];
    }

    prey->SetDir(newDir);
}
