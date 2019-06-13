//
// Created by darek on 30.05.19.
//

#ifndef SO2_P3_PASSENGER_H
#define SO2_P3_PASSENGER_H


#include <vector>
#include "Base/Thread.h"
#include "Base/Resource.h"
#include "Gate.h"
#include "Airplane.h"
#include "Car.h"

class Passenger : public Thread, public Resource {
public:
    enum Status {
        TO_GATE,        // Guard check
        GATE_QUEUE,
        IN_GATE,
        TO_AIRPLANE,
        AIRPLANE_QUEUE,
        IN_AIRPLANE,
        TO_EXIT,        // Guard check
        CAR_QUEUE,
        IN_CAR
    } status;

    int id;
    std::vector<Gate*> gate_vector;
    std::vector<Airplane*> airplane_vector;
    std::vector<Car*> car_vector;

    Passenger(std::vector<Gate*> gate_vector, std::vector<Airplane*> airplane_vector, std::vector<Car*> car_vector);
    Passenger(const Passenger&) = delete;
    virtual ~Passenger();

    void live() override;

    void entryToAirplane();
    void flyByAirplane();
    void entryToCar();
    void goByCar();

    std::string printObject();
    std::string printStatus();
    std::string printProgress();

    static int counter;
};


#endif //SO2_P3_PASSENGER_H
