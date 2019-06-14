//
// Created by darek on 30.05.19.
//

#include "Airplane.h"
#include <iostream>

int Airplane::counter = 0;

Airplane::Airplane() : id(counter) {
    Airplane::counter++;
    front_door_in.lock();
    front_door_out.lock();
}

Airplane::~Airplane() {
    Airplane::counter--;
}

void Airplane::live() {
    status = PREPARING;
    wait(2500, 3500);
    status = PENDING;
    letPassengersIn();
    status = FLIGHT;
    wait(4000, 5000);
    status = EXIT;
    letPassengersOut();
    if(isFinishing() == true)
        status = FINISHED;
}

void Airplane::letPassengersIn() {
    front_door_in.unlock();
    wait(7000, 14000);
    front_door_in.lock();
}

void Airplane::letPassengersOut() {
    front_door_out.unlock();
    wait(1000, 1500);
    front_door_out.lock();
}

std::string Airplane::print() {
    std::string result = "Airplane:" + std::to_string(id) + "      ";
    result += printProgress();
    result += '\t';
    switch(status) {
        case Status::PREPARING:
            result += "Preparing         ";
            break;
        case Status::PENDING:
            result += "Pending           ";
            break;
        case Status::FLIGHT:
            result += "Flight            ";
            break;
        case Status::EXIT:
            result += "Exit              ";
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

std::string Airplane::printProgress() {
    int current = progress / 4;
    int space = 25 - current - 1;
    std::string bar = "[";

    while (current--) {
        switch (status) {
            case Status::PENDING:
                bar += ".";
                break;
            case Status::FLIGHT:
                bar += ">";
                break;
            case Status::EXIT:
                bar += "#";
                break;
            case Status::PREPARING:
                bar += "#";
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