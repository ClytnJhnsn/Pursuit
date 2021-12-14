#include "sim.h"
#include "include/pure_pursuit.h"
#include "include/predator.h"
#include "include/pure_evasion.h"
#include "include/sensory_pure_evasion.h"
#include "include/sensory_stochastic_evasion.h"
#include "include/parallel_navigation.h"
#include "include/prey.h"
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#define NUM_RUNS 5
#define CATCH_THRESHOLD 2.0
#define PRED_ID 1
#define PREY_ID 0

void writeRunDataToFile(std::ofstream&, int, int, int, int, double, double, double);

void writePathsToFile(std::ofstream&, int, int, int, int, std::vector<double>, std::vector<double>);

void runSimulation(std::ofstream&, std::ofstream&, PursuitStrategy*, EvasionStrategy*, int&);

void createOutputDir();

/**
 * FLAGS FOR EVASION STATEGIES
 * - 0 : pure_evasion
 * - 1 : sensory_pure_evasion
 * - 2 : stochastic_evasion
 *
 * FLAGS FOR PURSUIT STRATEGIES
 * - 0 : pure_pursuit
 * - 1 : parallel_naviation
 */

int main() {
    int unique_sim_number = 0;
    std::ofstream runsFile, pathsFile;

    createOutputDir();

    pathsFile.open("output/paths.csv");
    runsFile.open("output/runs.csv");


    /** Run with pure_pursuit and pure_evasion **/
    PurePursuit* pure_pursuit = new PurePursuit();
    // PureEvasion* pure_evasion = new PureEvasion();
    // runSimulation(pathsFile, runsFile, pure_pursuit, pure_evasion, unique_sim_number);


    /** Run with pure_pursuit and sensory_pure_evasion **/
    SensoryPureEvasion* sensory_pure_evasion = new SensoryPureEvasion();
    runSimulation(pathsFile, runsFile, pure_pursuit, sensory_pure_evasion, unique_sim_number);


    /** Run with pure_pursuit and sensory_stochastic_evasion **/
    SensoryStochasticEvasion* sensory_stochastic_evasion = new SensoryStochasticEvasion();
    runSimulation(pathsFile, runsFile, pure_pursuit, sensory_stochastic_evasion, unique_sim_number);
    
}



void runSimulation(
    std::ofstream& pathsFile,
    std::ofstream& runsFile,
    PursuitStrategy* pursuit_strategy,
    EvasionStrategy* evasion_strategy,
    int &sim_number
) {
    int num_iters[NUM_RUNS];
    double starting_distances[NUM_RUNS];

    for (int i = 0; i < NUM_RUNS; i++) {
        sim_number++;
        Sim* sim = new Sim();

        sim->SetPursuitStrat(pursuit_strategy);
        sim->SetEvasionStrat(evasion_strategy);

        num_iters[i] = 0;
        starting_distances[i] = sim->GetDist();

        while(!sim->Caught(CATCH_THRESHOLD)) {
            num_iters[i] += 1;
            sim->Update();

            writePathsToFile(pathsFile, sim_number, pursuit_strategy->GetStratID(),
                evasion_strategy->GetStratID(), num_iters[i], sim->GetPredatorPos(),
                sim->GetPreyPos());
        }

        writeRunDataToFile(runsFile, sim_number, pursuit_strategy->GetStratID(),
             evasion_strategy->GetStratID(), num_iters[i], starting_distances[i],
             sim->GetPreyDistanceTraveled(), sim->GetPredDistanceTraveled());
    }

}

void writeRunDataToFile( 
    std::ofstream& file, 
    int sim_number,
    int pursuit_strat,
    int evasion_strat,
    int num_iters, 
    double starting_distance, 
    double prey_distance_traveled,
    double pred_distance_traveled
) {
    file << sim_number << "," << pursuit_strat << "," << evasion_strat << "," 
        << num_iters << "," << starting_distance << "," << prey_distance_traveled 
        << "," << pred_distance_traveled << std::endl;
}

void writePathsToFile(
    std::ofstream& file,
    int sim_number,
    int pursuit_strat,
    int evasion_strat,
    int iteration,
    std::vector<double> pred_pos,
    std::vector<double> prey_pos
) {

    
    file << sim_number << "," << PRED_ID << "," << pursuit_strat << "," << iteration << ",";

    for (int i = 0; i < pred_pos.size(); i++) {
        if (i == pred_pos.size()-1) {
           file << pred_pos[i] << std::endl;
        } else {
            file << pred_pos[i] << ",";
        }
    }






    file << sim_number << "," << PREY_ID << "," << evasion_strat << "," << iteration << ",";

    for (int i = 0; i < prey_pos.size(); i++) {
        if (i == prey_pos.size()-1) {
           file << prey_pos[i] << std::endl;
        } else {
            file << prey_pos[i] << ",";
        }
    }
}

void createOutputDir() {
    mkdir("output", ACCESSPERMS);
}