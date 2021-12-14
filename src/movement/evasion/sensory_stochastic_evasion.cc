#include "../../include/sensory_stochastic_evasion.h"
#include "../../include/entity.h"
#include <vector>
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define SENSORY_RANGE 50
#define EVASION_RANGE 20

SensoryStochasticEvasion::SensoryStochasticEvasion() {
    isWithinEvasionRangeFlag = 0;
}

void SensoryStochasticEvasion::Apply(Entity* prey) {
    // Set direction vector in direction of prey
    std::vector<double> preyPos = prey->GetPos();
    std::vector<double> predPos = prey->GetOtherPos();

    double distance = GetDist(preyPos, predPos);

    if (distance < SENSORY_RANGE) {
        std::vector<double> newDir = {0.0, 0.0};
        for (int i = 0; i < 2; i++) {
            newDir[i] = preyPos[i] - predPos[i];
        }

        if (distance < EVASION_RANGE && isWithinEvasionRangeFlag == 0) {
            isWithinEvasionRangeFlag = 1;
            srand(time(NULL));  
            bool fiftyfifty = (rand() % 2) == 0;
            
            if (fiftyfifty) {
                newDir = {-newDir[1], newDir[0]};
            } else {
                newDir = {newDir[1], -newDir[0]};
            }

        } else {
            isWithinEvasionRangeFlag = 0;
        }

        prey->SetDir(newDir);
    }
}

double SensoryStochasticEvasion::GetDist(std::vector<double> preyPos, std::vector<double> predPos) {
    std::vector<double> diff = {0.0, 0.0};

    for (int i = 0; i < 2; i++) {
        diff[i] = preyPos[i] - predPos[i];
    }

    return sqrt(diff[0]*diff[0] + diff[1]*diff[1]); 
}

int SensoryStochasticEvasion::GetStratID() {
    return 2;
}