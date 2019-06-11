//
// Created by darek on 10.06.19.
//

#ifndef SO2_P3_THREAD_H
#define SO2_P3_THREAD_H
#include <thread>
#include "../../Sync.h"

class Thread {
public:
    std::thread thread;
    bool running;
    bool finished;

    Thread();
    Thread(const Thread&) = delete;
    virtual ~Thread();

    bool start();
    bool stop();

    void run();
    bool isFinished();

    virtual void live() = 0;
};


#endif //SO2_P3_THREAD_H
