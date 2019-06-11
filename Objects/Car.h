//
// Created by darek on 30.05.19.
//

#ifndef SO2_P3_CAR_H
#define SO2_P3_CAR_H


#include "Base/Thread.h"
#include "Base/Resource.h"

class Car : public Thread, public Resource {
public:
    int id;

    Car();
    Car(const Car&) = delete;
    virtual ~Car();

    void live() override;

    static int counter;
};


#endif //SO2_P3_CAR_H
