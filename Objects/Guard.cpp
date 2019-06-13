//
// Created by darek on 30.05.19.
//

#include "Guard.h"

int Guard::counter = 0;

Guard::Guard(std::vector<Passenger*> passenger_vector)
    : id(counter), passenger_vector(passenger_vector), caught_passenger(-1) {
    Guard::counter++;
}

Guard::~Guard() {
    Guard::counter--;
}

void Guard::live() {
    status = RELAX;
    wait(2500, 3500);
    status = CATCH;
    catchPassenger();
    if(isFinishing() == true)
        status = FINISHED;
}

void Guard::catchPassenger() {
    for(auto it : passenger_vector) {
        if((it->status == Passenger::Status::TO_GATE || it->status == Passenger::Status::TO_EXIT) && it->paused == false) {
            caught_passenger = it->id;
            it->pause();
            wait(2500, 3500);
            it->resume();
            break;
        }
    }
    caught_passenger = -1;
}

std::string Guard::print() {
    std::string result = "Guard:" + std::to_string(id) + "         ";
    result += printProgress();
    result += '\t';
    switch(status) {
        case Status::CATCH:
            result += "Catch P:" + std::to_string(caught_passenger) + "         ";
            break;
        case Status::RELAX:
            result += "Relax             ";
            break;
        case Status::FINISHED:
            result += "Finished          ";
            break;
        default:
            result += "                  ";
    }
    result += "Iteration: " + std::to_string(iteration);
    return result;
}

std::string Guard::printProgress() {
    int current = progress / 4;
    int space = 25 - current - 1;
    std::string bar = "[";

    while (current--) {
        switch (status) {
            case Status::CATCH:
                bar += "!";
                break;
            case Status::RELAX:
                bar += ".";
                break;
            default:
                bar += "#";
        }
    }
    while (space--) {
        bar += " ";
    }
    bar += "]";
    return bar;
}