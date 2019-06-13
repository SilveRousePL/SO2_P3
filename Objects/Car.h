//
// Created by darek on 30.05.19.
//

#ifndef SO2_P3_CAR_H
#define SO2_P3_CAR_H


#include "Base/Thread.h"
#include "Base/Resource.h"

class Car : public Thread {//, public Resource {
public:
    enum Status {
        READY,
        DEPARTURE,
        ARRIVAL
    } status;

    int id;
    std::mutex busy;
    std::mutex exit_mutex;

    Car();
    Car(const Car&) = delete;
    virtual ~Car();

    void live() override;

    std::string printObject();
    std::string printStatus();
    std::string printProgress();

    static int counter;
};


#endif //SO2_P3_CAR_H
