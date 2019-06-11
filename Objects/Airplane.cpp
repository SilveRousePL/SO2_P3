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
    std::cout << "Airplane: " << id << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}