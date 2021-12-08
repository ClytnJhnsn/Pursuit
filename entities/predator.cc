#include "predator.h"
#include "pursuit_strategy.h"
#include <vector>

Predator::Predator() {
    pos = std::vector<double>(0.0, 0.0, 0.0);
    dir = pos;
    speed = 0;
    pursuit_strat = new PursuitStrategy();
}

Predator::~Predator() {
    delete pursuit_strat;
}

// Probably won't need
// Predator::Predator(const Predator& otherPredator) {
//
// }

PursuitStrategy* Predator::GetPursuitStrat() {
    return pursuit_strat;
}

void Predator::SetPursuitStrat(PursuitStrategy* newStrat) {
    pursuit_strat = newStrat;
}

// Probably won't need
// Predator::Predator operator=(const Predator& otherPredator) {
//     pos = otherPredator->GetPos();
//     dir = otherPredator->GetDir();
//     speed = otherPredator->GetSpeed();
//     pursuit_strat = otherPredator->GetMovementStrat();
// }

void Predator::Update(double dt) {
    if(pursuit_strat) {
        pursuit_strat->Apply(this);
    }

    for (int i = 0; i < 3; i++) {
        pos[i] += speed*dir[i];
    }

}