//
// Created by darek on 13.06.19.
//

#ifndef SO2_P3_OBJECTS_H
#define SO2_P3_OBJECTS_H
#include "Objects/Airplane.h"
#include "Objects/Car.h"
#include "Objects/Gate.h"
#include "Objects/Guard.h"
#include "Objects/Passenger.h"
#include <vector>
#include <iostream>

class Objects {
public:
    std::vector<Airplane*> airplane;
    std::vector<Car*> car;
    std::vector<Gate*> gate;
    std::vector<Guard*> guard;
    std::vector<Passenger*> passenger;

    std::thread stoping_thread;
    bool stop_operation;

    Objects(std::vector<size_t> number_of_objects) {
        stop_operation = false;

        for(auto i{0}; i < number_of_objects[0]; ++i)
            airplane.push_back(new Airplane());
        for(auto i{0}; i < number_of_objects[1]; ++i)
            car.push_back(new Car());
        for(auto i{0}; i < number_of_objects[2]; ++i)
            gate.push_back(new Gate());
        for(auto i{0}; i < number_of_objects[3]; ++i)
            passenger.push_back(new Passenger(gate, airplane, car));
        for(auto i{0}; i < number_of_objects[4]; ++i)
            guard.push_back(new Guard(passenger));
    }
    virtual ~Objects() {
        for(auto it : airplane)
            delete it;
        for(auto it : car)
            delete it;
        for(auto it : gate)
            delete it;
        for(auto it : guard)
            delete it;
        for(auto it : passenger)
            delete it;
    }

    void stopAll() {
        if(stop_operation == true)
            return;
        stop_operation = true;

        stoping_thread = std::thread([&](){
            // Zatrzymaj pasażerów
            for(auto it : passenger) {
                it->stop();
            }

            // Dopóki pasażerowie się nie zakończą, nie kończ pozostałych wątków
            for(auto it : passenger) {
                while(!it->isFinished())
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }

            // Zakończ pozostałe wątki
            for(auto it : airplane) {
                it->stop();
            }
            for(auto it : car) {
                it->stop();
            }
            for(auto it : guard) {
                it->stop();
            }
        });
    }

    bool isAllFinished() {
        for(auto it : airplane) {
            if(!it->isFinished())
                return false;
        }
        for(auto it : car) {
            if(!it->isFinished())
                return false;
        }
        for(auto it : guard) {
            if(!it->isFinished())
                return false;
        }
        for(auto it : passenger) {
            if(!it->isFinished())
                return false;
        }
        return true;
    }

    int sizeThr() {
        return airplane.size() + car.size() + guard.size() + passenger.size();
    }

    std::string print(int object) {
        if(object >= sizeThr() && object < 0)
            return "";
        for(auto it : airplane) {
            if(it->global_id == object)
                return it->print();
        }
        for(auto it : car) {
            if(it->global_id == object)
                return it->print();
        }
        for(auto it : guard) {
            if(it->global_id == object)
                return it->print();
        }
        for(auto it : passenger) {
            if(it->global_id == object)
                return it->print();
        }
        return "";
    }
};

#endif //SO2_P3_OBJECTS_H
