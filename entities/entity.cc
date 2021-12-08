#include "entity.h"
#include <vector>
#include <cmath>

std::vector<double> Entity::GetPos() { 
    return pos; 
}

std::vector<double> Entity::GetDir() { 
    return dir; 
}

double Entity::GetSpeed() { 
    return Speed; 
}

void Entity::SetPos(std::vector<double> newPos) { 
    pos = newPos;
}

void Entity::SetDir(std::vector<double> newDir) { 
    // Normalize first 
    double norm = sqrt(newDir[0]*newDir[0] + newDir[1]*newDir[1] + newDir[2]*newDir[2]);
    if (norm != 0) {
        for (int i = 0; i < 3; i++) {
            newDir[i] = newDir[i] / norm;
        }
    }
    dir = newDir; 
}

void Entity::SetSpeed(double newSpeed) { 
    speed = newSpeed; 
}