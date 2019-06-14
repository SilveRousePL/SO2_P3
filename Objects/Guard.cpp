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
    catchPassenger();
    if(isFinishing() == true)
        status = FINISHED;
}

void Guard::catchPassenger() {
    //for(auto it : passenger_vector) {
    for (auto i = random()%passenger_vector.size(); i < passenger_vector.size(); ++i) {
        caught_passenger = passenger_vector[i]->id;
        std::lock_guard<std::mutex> l(passenger_vector[i]->status_m);
        status = CATCH;
        if ((passenger_vector[i]->status == Passenger::Status::TO_GATE || passenger_vector[i]->status == Passenger::Status::TO_EXIT) &&
                passenger_vector[i]->paused == false) {
            passenger_vector[i]->pause();
            wait(2500, 3500);
            passenger_vector[i]->resume();
            break;
        }
    }
    //}
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
    result += "Iteration: " + std::to_string(iteration) + "  ";
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
    while (space-- > 0) {
        bar += " ";
    }
    bar += "]";
    return bar;
}