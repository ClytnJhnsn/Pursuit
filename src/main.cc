#include "sim.h"
#include "include/pure_pursuit.h"
#include "include/predator.h"
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
        // std::cout << sim->GetDist() << std::endl;
        // if (sim->Caught(2.0)) { 
        //     i = 100; 
            // std::cout << "********" << std::endl;
            // std::cout << "Caught!" << std::endl;
            // std::cout << "********" << std::endl;
        // }

        std::cout << "Run " << i << "\tcaught in " << num_iters[i] << "\titers " 
        <<  starting_distances[i] << "\tdist at start " << (starting_distances[i]/num_iters[i]) 
        << "\tdist/iters" <<std::endl;
    }
}