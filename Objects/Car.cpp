//
// Created by darek on 30.05.19.
//

#include <iostream>
#include "Car.h"

int Car::counter = 0;

Car::Car() : id(counter) {
    Car::counter++;
    exit_mutex.lock();
}

Car::~Car() {
    Car::counter--;
}

void Car::live() {
    status = READY;
    waitForPassenger();
    status = DEPARTURE;
    wait(1500, 2500);
    status = ARRIVAL;
    wait(3500, 4500);
    letPassengerOut();
    if(isFinishing() == true)
        status = FINISHED;
}

void Car::waitForPassenger() {
    busy.unlock();
    wait(3000, 3500);
    busy.try_lock();
}

void Car::letPassengerOut() {
    exit_mutex.unlock();
    wait(1000, 1500);
    exit_mutex.lock();
}

std::string Car::print() {
    std::string result = "Car:" + std::to_string(id) + "           ";
    result += printProgress();
    result += '\t';
    switch(status) {
        case Status::READY:
            result += "Ready             ";
            break;
        case Status::DEPARTURE:
            result += "Departure         ";
            break;
        case Status::ARRIVAL:
            result += "Arrival           ";
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

std::string Car::printProgress() {
    int current = progress / 4;
    int space = 25 - current - 1;
    std::string bar = "[";

    while (current--) {
        switch (status) {
            case Status::READY:
                bar += ".";
                break;
            case Status::DEPARTURE:
                bar += "<";
                break;
            case Status::ARRIVAL:
                bar += ">";
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