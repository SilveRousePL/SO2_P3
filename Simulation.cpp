//
// Created by darek on 30.05.19.
//

#include "Simulation.h"
#include <exception>

Simulation::Simulation(std::vector<size_t> number_of_objects) {
    if(number_of_objects.size() != 5)
        throw std::invalid_argument("Wrong vector size");
    objects = new Objects(number_of_objects);

    //std::this_thread::sleep_for(std::chrono::milliseconds(100));

    visualisation = new Visualisation(objects);
    visualisation->start();
}

Simulation::~Simulation() {
    delete objects;
    delete visualisation;
}

