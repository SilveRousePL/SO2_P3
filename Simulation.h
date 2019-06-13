//
// Created by darek on 30.05.19.
//

#ifndef SO2_P3_SIMULATION_H
#define SO2_P3_SIMULATION_H


#include <vector>
#include <tuple>
#include "Objects/Airplane.h"
#include "Objects/Car.h"
#include "Objects/Gate.h"
#include "Objects/Guard.h"
#include "Objects/Passenger.h"

class Simulation {
public:
    std::vector<Airplane*> airplane;
    std::vector<Car*> car;
    std::vector<Gate*> gate;
    std::vector<Guard*> guard;
    std::vector<Passenger*> passenger;

    bool stop_operation;

    // vector<size_t>({airplanes, cars, gates, guards, passengers});
    Simulation(std::vector<size_t> number_of_objects);
    Simulation(const Simulation&) = delete;
    virtual ~Simulation();

    void stopAll();
    bool isAllFinished();
};


#endif //SO2_P3_SIMULATION_H
