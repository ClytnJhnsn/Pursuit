#include "sim.h"
#include "include/pure_pursuit.h"
#include "include/predator.h"
#include "include/sensory_pure_evasion.h"
#include "include/prey.h"
#include <iostream>
#define NUM_RUNS 15

int main() {

    int num_iters[NUM_RUNS];
    double starting_distances[NUM_RUNS];

    for (int i = 0; i < NUM_RUNS; i++) {
        Sim* sim = new Sim();

        num_iters[i] = 0;
        starting_distances[i] = sim->GetDist();

        
        while(!sim->Caught(2.0)) {
            num_iters[i] += 1;
            sim->Update();
        }

        std::cout << "Run " << i 
        << "\t iters " << num_iters[i] 
        << "\tdist at start " << starting_distances[i] 
        << "\tdist/iters " << (starting_distances[i]/num_iters[i]) 
        << std::endl;
    }

    // Now with SensoryPureEvasion
    SensoryPureEvasion* evasion_strat = new SensoryPureEvasion();
    std::cout << "**** Sensory Pure Evasion ****" << std::endl;

    for (int i = 0; i < NUM_RUNS; i++) {
        Sim* sim = new Sim();
        sim->SetEvasionStrat(evasion_strat);

        num_iters[i] = 0;
        starting_distances[i] = sim->GetDist();

        
        while(!sim->Caught(2.0)) {
            num_iters[i] += 1;
            sim->Update();
        }

        std::cout << "Run " << i 
        << "\t iters " << num_iters[i] 
        << "\tdist at start " << starting_distances[i] 
        << "\tdist/iters " << (starting_distances[i]/num_iters[i]) 
        << std::endl;
    }

    Sim* sim2 = new Sim();
    std::cout << "****" << std::endl;
    std::cout << "Sim2" << std::endl;
    std::cout << "****" << std::endl;
    std::cout << sim2->GetDist() << std::endl;
    for (int i = 0; i < 100; i++) {
        sim2->Update();
        std::cout << sim2->GetDist() << std::endl;
        if (sim2->Caught(2.0)) { 
            i = 100; 
            std::cout << "Caught!" << std::endl;
        }
    }

}