#include "sim.h"
#include "include/pure_pursuit.h"
#include "include/predator.h"
#include "include/sensory_pure_evasion.h"
#include "include/prey.h"
#include <iostream>
#include <fstream>
#define NUM_RUNS 15

void writeRunDataToFile(std::ofstream&, int, int, double, double, double);

void writePathsToFile(std::ofstream&, int, int, int, int, std::vector<double>, std::vector<double>); 

/**
 * FLAGS FOR EVASION STATEGIES
 * - 0 : pure
 * - 1 : sensory_pure
 *
 * FLAGS FOR PURSUIT STRATEGIES
 * - 0 : pure
 */

int main() {
    int sim_number = 0;


    std::ofstream runsFile, pathsFile;

    pathsFile.open("paths.csv");
    runsFile.open("runs.csv");

    int num_iters[NUM_RUNS];
    double starting_distances[NUM_RUNS];

    for (int i = 0; i < NUM_RUNS; i++) {
        sim_number++;
        Sim* sim = new Sim();

        num_iters[i] = 0;
        starting_distances[i] = sim->GetDist();

        while(!sim->Caught(2.0)) {
            num_iters[i] += 1;
            sim->Update();
            writePathsToFile(pathsFile, sim_number, num_iters[i], 0, 1, sim->GetPredatorPos(), sim->GetPreyPos());
        }

        writeRunDataToFile(runsFile, sim_number, num_iters[i], starting_distances[i],
             sim->GetPreyDistanceTraveled(), sim->GetPredDistanceTraveled());
    }

    // Now with SensoryPureEvasion
    SensoryPureEvasion* evasion_strat = new SensoryPureEvasion();

    for (int i = 0; i < NUM_RUNS; i++) {
        sim_number++;
        Sim* sim = new Sim();
        sim->SetEvasionStrat(evasion_strat);

        num_iters[i] = 0;
        starting_distances[i] = sim->GetDist();

        
        while(!sim->Caught(2.0)) {
            num_iters[i] += 1;
            sim->Update();
            writePathsToFile(pathsFile, sim_number, num_iters[i], 0, 0, sim->GetPredatorPos(), sim->GetPreyPos());
        }

        writeRunDataToFile(runsFile, sim_number, num_iters[i], starting_distances[i],
             sim->GetPreyDistanceTraveled(), sim->GetPredDistanceTraveled());
    }

}


void writeRunDataToFile( 
    std::ofstream& file, 
    int sim_number, 
    int num_iters, 
    double starting_distance, 
    double prey_distance_traveled,
    double pred_distance_traveled
) {
    file << sim_number << "," << num_iters << "," << starting_distance 
    << "," << prey_distance_traveled << "," << pred_distance_traveled << std::endl;
}

void writePathsToFile(
    std::ofstream& file,
    int sim_number,
    int iteration,
    int pursuit_strat,
    int evasion_strat,
    std::vector<double> prey_pos,
    std::vector<double> pred_pos
) {
    file << sim_number << "," << iteration << "," << pursuit_strat << ",";

    for (int i = 0; i < pred_pos.size(); i++) {
        if (i == pred_pos.size()-1) {
           file << pred_pos[i] << std::endl;
        } else {
            file << pred_pos[i] << ",";
        }
    }
    
    file << iteration << "," << evasion_strat << ",";

    for (int i = 0; i < prey_pos.size(); i++) {
        if (i == prey_pos.size()-1) {
           file << prey_pos[i] << std::endl;
        } else {
            file << prey_pos[i] << ",";
        }
    }
}