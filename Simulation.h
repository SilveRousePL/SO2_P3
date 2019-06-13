//
// Created by darek on 30.05.19.
//

#ifndef SO2_P3_SIMULATION_H
#define SO2_P3_SIMULATION_H

#include <vector>
#include "Objects.h"
#include "Visualisation.h"

class Simulation {
public:
    Objects* objects;
    Visualisation* visualisation;

    // airplanes, cars, gates, passengers, guards
    Simulation(std::vector<size_t> number_of_objects);
    Simulation(const Simulation&) = delete;
    virtual ~Simulation();
};


#endif //SO2_P3_SIMULATION_H
