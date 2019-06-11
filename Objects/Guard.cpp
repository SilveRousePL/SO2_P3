//
// Created by darek on 30.05.19.
//

#include "Guard.h"

int Guard::counter = 0;

Guard::Guard() : id(counter) {
    Guard::counter++;
}

Guard::~Guard() {
    Guard::counter--;
}

void Guard::live() {

}
