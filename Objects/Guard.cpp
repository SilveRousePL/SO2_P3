//
// Created by darek on 30.05.19.
//

#include "Guard.h"

int Guard::counter = 0;

Guard::Guard(std::vector<Passenger*> passenger_vector)
    : id(counter), passenger_vector(passenger_vector) {
    Guard::counter++;
}

Guard::~Guard() {
    Guard::counter--;
}

void Guard::live() {
    status = CATCH;
    catchPassenger();
    status = RELAX;
    wait(2500, 3500);
}

void Guard::catchPassenger() {
    for(auto it : passenger_vector) {
        if((it->status == Passenger::Status::TO_GATE || it->status == Passenger::Status::TO_EXIT) && it->paused == false) {
            it->pause();
            wait(2500, 3500);
            it->resume();
            break;
        }
    }
}