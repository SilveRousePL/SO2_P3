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
        RELAX
    } status;

    int id;

    std::vector<Passenger*> passenger_vector;

    Guard(std::vector<Passenger*> passenger_vector);
    Guard(const Guard&) = delete;
    virtual ~Guard();

    void live() override;

    void catchPassenger();

    std::string printObject();
    std::string printStatus();
    std::string printProgress();

    static int counter;
};


#endif //SO2_P3_GUARD_H
