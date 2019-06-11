//
// Created by darek on 30.05.19.
//

#ifndef SO2_P3_AIRPLANE_H
#define SO2_P3_AIRPLANE_H


#include "Base/Thread.h"
#include "Base/Resource.h"

class Airplane : public Thread, public Resource {
public:
    int id;

    Airplane();
    Airplane(const Airplane&) = delete;
    virtual ~Airplane();

    void live() override;

    static int counter;
};


#endif //SO2_P3_AIRPLANE_H
