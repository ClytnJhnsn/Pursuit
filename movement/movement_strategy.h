#ifndef MOVEMENT_STRATEGY_H_
#define MOVEMENT_STRATEGY_H_

class MovementStrategy {
    virtual void Apply(Entity* entity) = 0;

    virtual ~MovementStrategy() {};

    // virtual void operator=(const MovementStrategy& otherStrat) {};

}

#endif