//
// Created by darek on 10.06.19.
//

#include "Thread.h"

Thread::Thread() : running(false), finished(false) {
    this->start();
}

Thread::~Thread() {

}

bool Thread::start() {
    if(running)
        return false;
    running = true;
    thread = std::thread(&Thread::run, this);
    return true;
}

bool Thread::stop() {
    if (!running)
        return false;
    running = false;
    return true;
}

void Thread::run() {
    while(running)
        live();
    finished = true;
    if (thread.joinable())
        thread.detach();
}

bool Thread::isFinished() {
    return finished;
}