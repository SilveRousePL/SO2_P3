//
// Created by darek on 30.05.19.
//

#include "Passenger.h"

int Passenger::counter = 0;

Passenger::Passenger(std::vector<Gate*> gate_vector, std::vector<Airplane*> airplane_vector, std::vector<Car*> car_vector)
    : id(counter), gate_vector(gate_vector), airplane_vector(airplane_vector), car_vector(car_vector) {
    Passenger::counter++;
}

Passenger::~Passenger() {
    Passenger::counter--;
}

void Passenger::live() {
    status = TO_GATE;
    wait(3500, 4500); // Może zostać zablokowany przez ochronę
    int gate_id = random() % gate_vector.size();
    status = GATE_QUEUE;
    gate_vector[gate_id]->request(id);
    status = IN_GATE;
    wait(2500, 3500);
    gate_vector[gate_id]->free();
    status = TO_AIRPLANE;
    wait(3500, 4500);
    entryToAirplane(); // AIRPLANE_QUEUE
    flyByAirplane(); // IN_AIRPLANE
    status = TO_EXIT;
    wait(3500, 4500); // Może zostać zablokowany przez ochronę
    entryToCar(); // CAR_QUEUE
    goByCar(); // IN_CAR
    if(isFinished() == true)
        status = FINISHED;
}

void Passenger::entryToAirplane() {
    status = AIRPLANE_QUEUE;
    airplane_vector[id % airplane_vector.size()]->front_door_in.lock();
    airplane_vector[id % airplane_vector.size()]->front_door_in.unlock();
}

void Passenger::flyByAirplane() {
    status = IN_AIRPLANE;
    airplane_vector[id % airplane_vector.size()]->front_door_out.lock();
    airplane_vector[id % airplane_vector.size()]->front_door_out.unlock();
}

void Passenger::entryToCar() {
    status = CAR_QUEUE;
    car_vector[id]->busy.lock();
    car_vector[id]->busy.unlock();

    /*int car_id = -1;
    for(auto i{0}; i < car_vector.size(); ++i) { //szukanie samochodu
        if (car_vector[i]->busy.try_lock()) {
            car_id = i;
            break;
        }
        if(i == car_vector.size() - 1) {
            i = 0;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
    return car_id;*/
}

void Passenger::goByCar() {
    status = IN_CAR;
    car_vector[id]->exit_mutex.lock();
    car_vector[id]->exit_mutex.unlock();
}

std::string Passenger::print() {
    std::string result = "Passenger:" + std::to_string(id) + "     ";
    result += printProgress();
    result += '\t';
    switch(status) {
        case Status::TO_GATE:
            result += "To gate                  ";
            break;
        case Status::GATE_QUEUE:
            result += "Gate queue               ";
            break;
        case Status::IN_GATE:
            result += "In gate                  ";
            break;
        case Status::TO_AIRPLANE:
            result += "To airplane              ";
            break;
        case Status::AIRPLANE_QUEUE:
            result += "Airplane queue           ";
            break;
        case Status::IN_AIRPLANE:
            result += "In airplane              ";
            break;
        case Status::TO_EXIT:
            result += "To exit                  ";
            break;
        case Status::CAR_QUEUE:
            result += "Car queue                ";
            break;
        case Status::IN_CAR:
            result += "In car                   ";
            break;
        case Status::FINISHED:
            result += "Finished                 ";
            break;
        default:
            result += "                         ";
    }
    return result;
}

std::string Passenger::printProgress() {
    int current = progress / 4;
    int space = 25 - current - 1;
    std::string bar = "[";
    switch(status) {
        case Status::GATE_QUEUE:
            bar += "       Gate queue       ";
            break;
        case Status::AIRPLANE_QUEUE:
            bar += "     Airplane queue     ";
            break;
        case Status::IN_AIRPLANE:
            bar += "      In airplane       ";
            break;
        case Status::CAR_QUEUE:
            bar += "       Car queue        ";
            break;
        case Status::IN_CAR:
            bar += "         In car         ";
            break;
        case Status::FINISHED:
            bar += "        Finished        ";
            break;
        default:
            while (current--) {
                switch (status) {
                    case Status::TO_GATE:
                        bar += "#";
                        break;
                    case Status::IN_GATE:
                        bar += "#";
                        break;
                    case Status::TO_AIRPLANE:
                        bar += "#";
                        break;
                    case Status::TO_EXIT:
                        bar += "#";
                        break;
                    default:
                        bar += "#";
                }
            }
            while (space--) {
                bar += " ";
            }
    }
    bar += "]";
    return bar;
}
