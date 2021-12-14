#include "../../include/sensory_stochastic_evasion.h"
#include "../../include/entity.h"
#include "../../include/prey.h"
#include <iostream>

#include <vector>
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define SENSORY_RANGE 100
#define EVASION_RANGE 20

SensoryStochasticEvasion::SensoryStochasticEvasion() {
    isWithinEvasionRangeFlag = 0;
}

void SensoryStochasticEvasion::Apply(Entity* prey, double dt) {
    // Set direction vector in direction of prey
    std::vector<double> preyPos = prey->GetPos();
    std::vector<double> predPos = prey->GetOtherPos();

    if (prey->GetDistanceTraveled() == 0) {
        // reset from run to run
        isWithinEvasionRangeFlag = 0;
    }

    double distance = GetDist(preyPos, predPos);

    if (distance < SENSORY_RANGE) {
        // prey can sense predator
        if (isWithinEvasionRangeFlag == 0) {
            // predator has not come within evasive maneuver range yet

            std::vector<double> newDir = {0.0, 0.0};
            for (int i = 0; i < 2; i++) {
                newDir[i] = preyPos[i] - predPos[i];
            }
    
            if (distance < EVASION_RANGE) {
                // predator is close enough to make an evasive maneuver
                isWithinEvasionRangeFlag = 1;
                srand(time(NULL));  
                bool fiftyfifty = (rand() % 2) == 0;
                
                // make a ninenty degree turn in a random direction
                if (fiftyfifty) {
                    newDir = {-newDir[1], newDir[0]};
                } else {
                    newDir = {newDir[1], -newDir[0]};
                }
            } else {
                // predator is now outside of evasive maneuver range again
                isWithinEvasionRangeFlag = 0;
            }
            prey->SetDir(newDir);
        } else {
            // prey is continuing in a straight line after its evasive maneuver
        }
    } else {
        // the predator is out of sensory range
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