//
// Created by darek on 30.05.19.
//

#ifndef SO2_P3_AIRPLANE_H
#define SO2_P3_AIRPLANE_H


#include "Base/Thread.h"
#include "Base/Resource.h"
#include <vector>

class Airplane : public Thread {
public:
    enum Status {
        PENDING,
        FLIGHT,
        EXIT,
        PREPARING
    } status;

    int id;
    std::mutex front_door_in;
    std::mutex front_door_out;

    Airplane();
    Airplane(const Airplane&) = delete;
    virtual ~Airplane();

    void live() override;

    void letPassengersIn();
    void letPassengersOut();

    std::string printObject();
    std::string printStatus();
    std::string printProgress();

    static int counter;
};


#endif //SO2_P3_AIRPLANE_H
