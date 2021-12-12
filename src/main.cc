#include "sim.h"
#include "include/pure_pursuit.h"
#include "include/predator.h"
#include "include/prey.h"
#include <iostream>

int main() {
    Sim* sim = new Sim();
    sim->Print();

    std::cout << sim->GetDist() << std::endl;
    for (int i = 0; i < 100; i++) {
        sim->Update();
        std::cout << sim->GetDist() << std::endl;
        if (sim->Caught(2.0)) { 
            i = 100; 
            std::cout << "********" << std::endl;
            std::cout << "Caught!" << std::endl;
            std::cout << "********" << std::endl;
        }
        // if (i==50) {
        //     std::vector<int> poop;
        //     int stopper = poop[10];
        // }
    }
}