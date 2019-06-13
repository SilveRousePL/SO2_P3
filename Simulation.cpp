//
// Created by darek on 30.05.19.
//

#include "Simulation.h"
#include <exception>
#include <iostream>

Simulation::Simulation(std::vector<size_t> number_of_objects) {
    if(number_of_objects.size() != 5)
        throw std::invalid_argument("Wrong vector size");

    stop_operation = false;

    for(auto i{0}; i < number_of_objects[0]; ++i)
        airplane.push_back(new Airplane());
    for(auto i{0}; i < number_of_objects[1]; ++i)
        car.push_back(new Car());
    for(auto i{0}; i < number_of_objects[2]; ++i)
        gate.push_back(new Gate());
    for(auto i{0}; i < number_of_objects[3]; ++i)
        guard.push_back(new Guard(passenger));
    for(auto i{0}; i < number_of_objects[4]; ++i)
        passenger.push_back(new Passenger(gate, airplane, car));
}

Simulation::~Simulation() {
    for(auto it : airplane)
        delete it;
    for(auto it : car)
        delete it;
    for(auto it : gate)
        delete it;
    for(auto it : guard)
        delete it;
    for(auto it : passenger)
        delete it;

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
        it->stop();
    }
    for(auto& it : car) {
        it->stop();
    }
    for(auto& it : guard) {
        it->stop();
    }
    for(auto& it : passenger) {
        it->stop();
    }
}

bool Simulation::isAllFinished() {
    for(auto& it : airplane) {
        if(!it->isFinished())
            return false;
    }
    for(auto& it : car) {
        if(!it->isFinished())
            return false;
    }
    for(auto& it : guard) {
        if(!it->isFinished())
            return false;
    }
    for(auto& it : passenger) {
        if(!it->isFinished())
            return false;
    }
    return true;
}