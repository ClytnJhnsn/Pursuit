#include "sim.h"
#include <iostream>

int main() {
    Sim* sim1 = new Sim();
    std::cout << "****" << std::endl;
    std::cout << "Sim1" << std::endl;
    std::cout << "****" << std::endl;
    std::cout << sim1->GetDist() << std::endl;
    for (int i = 0; i < 100; i++) {
        sim1->Update();
        std::cout << sim1->GetDist() << std::endl;
        if (sim1->Caught(2.0)) { 
            i = 100; 
            std::cout << "Caught!" << std::endl;
        }
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