//
// Created by darek on 30.05.19.
//

#include <iostream>
#include "Car.h"

int Car::counter = 0;

Car::Car() : id(counter) {
    Car::counter++;
}

Car::~Car() {
    Car::counter--;
}

void Car::live() {
    status = READY;
    //TODO: Oczekiwanie na pasażera
    status = DEPARTURE;
    wait(2500, 3500);
    status = ARRIVAL;
    wait(2500, 3500);
    //TODO: Wypuść pasażera
}
