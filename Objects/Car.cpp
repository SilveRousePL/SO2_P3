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
    std::cout << "Car: " << id << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
