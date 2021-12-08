#include "prey.h"
#include "evasion_strategy.h"
#include <vector>

Prey::Prey() {
    pos = std::vector<double>(0.0, 0.0, 0.0);
    dir = pos;
    speed = 0;
    evasion_strat = new EvasionStrategy();
}

Prey::~Prey() {
    delete evasion_strat;
}

// Probably won't need
// Prey::Prey(const Prey& otherPrey) {
//
// }
}

EvasionStrategy* Prey::GetEvasionStrat() {
    return evasion_strat;
}

void Prey::SetEvasionStrat(EvasionStrategy* newStrat) {
    evasion_strat = newStrat;
}

// Probably won't need
// Prey::Prey operator=(const Prey& otherPrey) {
//     pos = otherPrey->GetPos();
//     dir = otherPrey->GetDir();
//     speed = otherPrey->GetSpeed();
//     evasion_strat = otherPrey->GetMovementStrat();
// }

void Prey::Update(double dt) {
    if(pursuit_strat) {
        pursuit_strat->Apply(this);
    }

    for (int i = 0; i < 3; i++) {
        pos[i] += speed*dir[i];
    }
}