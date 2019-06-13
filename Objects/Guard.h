//
// Created by darek on 30.05.19.
//

#ifndef SO2_P3_GUARD_H
#define SO2_P3_GUARD_H


#include "Base/Thread.h"
#include "Base/Resource.h"
#include "Passenger.h"
#include <vector>

class Guard : public Thread, public Resource {
public:
    enum Status {
        CATCH,
        RELAX,
        FINISHED
    } status;

    int id;
    std::vector<Passenger*> passenger_vector;

    int caught_passenger;

    Guard(std::vector<Passenger*> passenger_vector);
    Guard(const Guard&) = delete;
    virtual ~Guard();

    void live() override;

    void catchPassenger();

    std::string print();
    std::string printProgress();

    static int counter;
};


#endif //SO2_P3_GUARD_H
