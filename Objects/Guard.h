//
// Created by darek on 30.05.19.
//

#ifndef SO2_P3_GUARD_H
#define SO2_P3_GUARD_H


#include "Base/Thread.h"
#include "Base/Resource.h"

class Guard : public Thread, public Resource {
public:
    int id;

    Guard();
    Guard(const Guard&) = delete;
    virtual ~Guard();

    void live() override;

    static int counter;
};


#endif //SO2_P3_GUARD_H
