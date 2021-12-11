#include "include/sim.h"

int main() {
    Sim* sim = new Sim();
    for (int i = 0; i < 1000; i++) {
        sim->Update();
        if (sim->Caught(2.0)) { 
            i = 1000; 
        }
    }
}