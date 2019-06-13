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
    /*
        TO_GATE,        // Guard check
        GATE_QUEUE,
        IN_GATE,
        TO_AIRPLANE,
        AIRPLANE_QUEUE,
        IN_AIRPLANE,
        TO_EXIT,        // Guard check
        CAR_QUEUE,
        IN_CAR,
    */
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
    int airplane_id = random() % airplane_vector.size();
    entryToAirplane(); // AIRPLANE_QUEUE
    flyByAirplane(); // IN_AIRPLANE
    status = TO_EXIT;
    wait(3500, 4500); // Może zostać zablokowany przez ochronę
    int car_id = random() % airplane_vector.size();

    // TODO: Pasażerowie mogą wyszukiwać wolny samochód i go rezerwować
    entryToCar();
    goByCar();
    // TODO: Wymyślić metodę na blokadę pasażerów przez samochód
    wait(3500, 4500);
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
    for(auto i{0}; i < car_vector.size(); ++i) { //szukanie samochodu
        if (car_vector[i]->busy.try_lock()) {
            break;
        }
        if(i == car_vector.size() - 1) {
            i = 0;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
}

void Passenger::goByCar() {
    status = IN_CAR;

}