//
// Created by darek on 30.05.19.
//

#include "Airplane.h"
#include <iostream>

int Airplane::counter = 0;

Airplane::Airplane() : id(counter) {
    Airplane::counter++;
}

Airplane::~Airplane() {
    Airplane::counter--;
}

void Airplane::live() {
    status = PENDING;
    letPassengersIn();
    status = FLIGHT;
    wait(4000, 5000);
    status = EXIT;
    letPassengersOut();
    status = PREPARING;
    wait(2500, 3500);
}

void Airplane::letPassengersIn() {
    front_door_in.unlock();
    wait(10000, 12000);
    front_door_in.lock();
}

void Airplane::letPassengersOut() {
    front_door_out.unlock();
    wait(1000, 1500);
    front_door_out.lock();
}