//
// Created by darek on 30.05.19.
//

#include "Simulation.h"
#include <exception>
#include <iostream>

Simulation::Simulation(std::vector<size_t> number_of_objects) :
    airplane(number_of_objects[0]),
    car(number_of_objects[1]),
    gate(number_of_objects[2]),
    guard(number_of_objects[3]),
    passenger(number_of_objects[4]) {
    if(number_of_objects.size() != 5)
        throw std::invalid_argument("Wrong vector size");
    stop_operation = false;
}

Simulation::~Simulation() {
    /*std::lock_guard<std::mutex> lock(stop_mutex);
    if(!stop_operation) {
        stopAll();
        while (!isAllFinished()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
    }*/
}

void Simulation::stopAll() {
    if(stop_operation == true)
        return;
    stop_operation = true;
    for(auto& it : airplane) {
        it.stop();
    }
    for(auto& it : car) {
        it.stop();
    }
    for(auto& it : guard) {
        it.stop();
    }
    for(auto& it : passenger) {
        it.stop();
    }
}

bool Simulation::isAllFinished() {
    for(auto& it : airplane) {
        if(!it.isFinished())
            return false;
    }
    for(auto& it : car) {
        if(!it.isFinished())
            return false;
    }
    for(auto& it : guard) {
        if(!it.isFinished())
            return false;
    }
    for(auto& it : passenger) {
        if(!it.isFinished())
            return false;
    }
    return true;
}