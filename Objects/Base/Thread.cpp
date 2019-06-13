//
// Created by darek on 10.06.19.
//

#include "Thread.h"

int Thread::global_counter = 0;

Thread::Thread() : running(false), finished(false), global_id(global_counter), progress(0) {
    global_counter++;
    this->start();
}

Thread::~Thread() {
    global_counter--;
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

void Thread::pause() {
    paused = true;
}

void Thread::resume() {
    paused = false;
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

void Thread::wait(int from, int to) {
    int rand = (from + (random() % (to - from))) / 100;
    this->progress = 0;
    for (progress = 0; progress < 100; progress++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand));

        //visualisation.updateTableInfo(globalID, getBlacksmith(), getStatus(), isFinished());

        while(paused)
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    this->progress = 0;
}