//
// Created by darek on 10.06.19.
//

#ifndef SO2_P3_THREAD_H
#define SO2_P3_THREAD_H
#include <thread>
#include <mutex>

class Thread {
public:
    std::thread thread;
    int progress;
    bool running;
    bool finished;
    bool paused;
    int global_id;
    int iteration;

    std::mutex status_m;

    static int global_counter;

    Thread();
    Thread(const Thread&) = delete;
    virtual ~Thread();

    bool start();
    bool stop();

    void pause();
    void resume();

    void run();
    bool isFinished();
    bool isFinishing();

    void wait(int from, int to);

    virtual void live() = 0;
};


#endif //SO2_P3_THREAD_H
