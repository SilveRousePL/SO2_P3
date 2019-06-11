//
// Created by darek on 30.05.19.
//

#ifndef SO2_P3_PASSENGER_H
#define SO2_P3_PASSENGER_H


#include "Base/Thread.h"
#include "Base/Resource.h"

class Passenger : public Thread, public Resource {
public:
    int id;

    Passenger();
    Passenger(const Passenger&) = delete;
    virtual ~Passenger();

    void live() override;

    static int counter;
};


#endif //SO2_P3_PASSENGER_H
