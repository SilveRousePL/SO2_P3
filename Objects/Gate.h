//
// Created by darek on 30.05.19.
//

#ifndef SO2_P3_GATE_H
#define SO2_P3_GATE_H


#include "Base/Resource.h"

class Gate : public Resource {
public:
    int id;

    Gate();
    Gate(const Gate&) = delete;
    virtual ~Gate();

    static int counter;
};


#endif //SO2_P3_GATE_H
