#include "sim.h"
#include "include/pure_pursuit.h"
#include "include/predator.h"
#include "include/prey.h"
#include <iostream>
#define NUM_RUNS 15

int main() {


    int num_iters[NUM_RUNS];

    for (int i = 0; i < NUM_RUNS; i++) {
        num_iters[i] = 0;

        Sim* sim = new Sim();
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

        std::cout << "Run " << i << " caught in " << num_iters[i] << " iterations" << std::endl;
    }
}