//
// Created by darek on 30.05.19.
//

#include "Gate.h"

int Gate::counter = 0;

Gate::Gate() : id(counter) {
    Gate::counter++;
}

Gate::~Gate() {
    Gate::counter--;
}
