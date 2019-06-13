//
// Created by darek on 30.05.19.
//

#include "Simulation.h"
#include <exception>

Simulation::Simulation(std::vector<size_t> number_of_objects) {
    if(number_of_objects.size() != 5)
        throw std::invalid_argument("Wrong vector size");
    objects = new Objects(number_of_objects);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    // Visualisation initialization
    /*std::vector <std::string> id, row_object, progress;
    std::vector<bool> isFinished;*/

    /*for (auto airplane_it : objects->airplane) {
        id.push_back(std::to_string(airplane_it->global_counter));
        row_object.push_back(airplane_it->print());
        isFinished.push_back(airplane_it->isFinished());
    }

    for (auto car_it : objects->car) {
        id.push_back(std::to_string(car_it->global_counter));
        row_object.push_back(car_it->print());
        isFinished.push_back(car_it->isFinished());
    }

    for (auto guard_it : objects->guard) {
        id.push_back(std::to_string(guard_it->global_counter));
        row_object.push_back(guard_it->print());
        isFinished.push_back(guard_it->isFinished());
    }

    for(auto passenger_it : objects->passenger) {
        id.push_back(std::to_string(passenger_it->global_counter));
        row_object.push_back(passenger_it->print());
        isFinished.push_back(passenger_it->isFinished());
    }*/

    visualisation = new Visualisation(objects);
    visualisation->start();
}

Simulation::~Simulation() {
    delete objects;
    delete visualisation;
}

