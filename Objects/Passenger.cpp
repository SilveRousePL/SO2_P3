//
// Created by darek on 30.05.19.
//

#include "Passenger.h"

int Passenger::counter = 0;

Passenger::Passenger() : id(counter) {
    Passenger::counter++;
}

Passenger::~Passenger() {
    Passenger::counter--;
}

void Passenger::live() {

}
